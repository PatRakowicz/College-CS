#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <random>
#include <atomic>

struct Item {
    int id;
    int sleepTime;
};

class SharedBuffer {
private:
    std::vector <Item> buffer;
    std::mutex mutex;
    std::condition_variable buffer_not_full;
    std::condition_variable buffer_not_empty;
    size_t capacity;
    std::atomic<int> produced_count;
    int total_items;
    bool producing_done;

public:
    SharedBuffer(size_t cap, int total) : capacity(cap), produced_count(0), total_items(total), producing_done(false) {}

    bool addItem(int producer_id, const Item &item) {
        std::unique_lock <std::mutex> lock(mutex);
        buffer_not_full.wait(lock, [this] { return buffer.size() < capacity; });
        buffer.push_back(item);
        std::cout << "P" << producer_id << ": added item (" << item.id << ", " << item.sleepTime << ") to buffer\n";
        std::cout << "P" << producer_id << ": posting- item in buffer\n";
        produced_count++;
        if (produced_count == total_items) {
            producing_done = true;
            buffer_not_empty.notify_all();
        }
        buffer_not_empty.notify_one();
        return producing_done;
    }

    Item removeItem(int consumer_id) {
        std::unique_lock <std::mutex> lock(mutex);
        buffer_not_empty.wait(lock, [this] { return !buffer.empty() || producing_done; });
        if (buffer.empty())
            return {-1, -1};
        Item item = buffer.back();
        buffer.pop_back();
        std::cout << "C" << consumer_id << ": removing item (" << item.id << ", " << item.sleepTime
                  << ") from buffer\n";
        std::cout << "C" << consumer_id << ": consumed item (" << item.id << ", " << item.sleepTime << ")\n";
        std::cout << "C" << consumer_id << ": posting- space in buffer\n";
        buffer_not_full.notify_one();
        return item;
    }

    bool canStop() const {
        return producing_done && buffer.empty();
    }
};

void producer(int id, int num_items, SharedBuffer &buffer) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(200, 900);
    std::uniform_int_distribution<> sleepTime(300, 700);

    for (int i = 0; i < num_items; ++i) {
        std::this_thread::sleep_for(std::chrono::microseconds(sleepTime(gen)));
        int sleep_duration = distrib(gen);
        std::cout << "P" << id << ": producing (" << sleep_duration << " us)\n";
        Item item{i, sleep_duration};
        if (buffer.addItem(id, item)) {
            std::cerr << "DONE PRODUCING!!\n";
            break;
        }
    }
}

void consumer(int id, SharedBuffer &buffer) {
    while (true) {
        std::cout << "C" << id << ": waiting for item in buffer\n";
        Item item = buffer.removeItem(id);
        if (item.id == -1) break;
        std::this_thread::sleep_for(std::chrono::microseconds(item.sleepTime));
    }
    std::cerr << "DONE CONSUMING!\n";
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        std::cerr << "Usage: " << argv[0] << " num_prod num_cons buf_size num_items\n";
        return 1;
    }

    int num_prod = std::stoi(argv[1]);
    int num_cons = std::stoi(argv[2]);
    int buf_size = std::stoi(argv[3]);
    int num_items = std::stoi(argv[4]);

    SharedBuffer buffer(buf_size, num_items);

    std::vector <std::thread> producers;
    std::vector <std::thread> consumers;

    for (int i = 0; i < num_prod; ++i) {
        producers.emplace_back(producer, i, num_items / num_prod + (i < num_items % num_prod ? 1 : 0),
                               std::ref(buffer));
    }
    for (int i = 0; i < num_cons; ++i) {
        consumers.emplace_back(consumer, i, std::ref(buffer));
    }

    for (auto &t: producers) {
        t.join();
    }
    for (auto &t: consumers) {
        t.join();
    }

    return 0;
}
