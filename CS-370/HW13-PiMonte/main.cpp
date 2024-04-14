#include <iostream>
#include <thread>
#include <vector>
#include <random>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <iomanip>

using namespace std;

mutex mtx;
condition_variable cv;
long long total_hits = 0;
long long total_attempts = 0;
bool all_threads_completed = false;

void monteCarlo(int iterations) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0);

    int hits = 0;
    for (int i = 0; i < iterations; ++i) {
        double x = dis(gen);
        double y = dis(gen);
        if (x * x + y * y <= 1.0)
            hits++;
    }

    lock_guard <mutex> lock(mtx);
    total_hits += hits;
    total_attempts += iterations;
}

void displayResults(int delay, int N, int iterations) {
    unique_lock <mutex> lock(mtx);
    auto next_time = chrono::steady_clock::now() + chrono::milliseconds(delay);

    while (!all_threads_completed || total_attempts < N * iterations) {
        cv.wait_until(lock, next_time, [&]() { return total_attempts == N * iterations; });

        double pi_estimate = 4.0 * total_hits / total_attempts;
        cout << fixed << setprecision(10) << pi_estimate << endl;

        if (total_attempts == N * iterations) { break; }
        next_time += chrono::milliseconds(delay);
    }
}


int main(int argc, char *argv[]) {
    if (argc != 4) {
        cerr << "Usage: " << argv[0] << " <iterations> <N> <delay>" << endl;
        return 1;
    }

    int iterations = stoi(argv[1]);
    int N = stoi(argv[2]);
    int delay = stoi(argv[3]);

    vector <thread> threads;
    for (int i = 0; i < N; ++i) {
        threads.emplace_back(monteCarlo, iterations);
    }

    thread displayThread(displayResults, delay, N, iterations);

    for (auto &th: threads) {
        th.join();
    }

    all_threads_completed = true;
    cv.notify_all();
    displayThread.join();

    double final_estimate = 4.0 * total_hits / total_attempts;
    cout << "hits = " << total_hits << ", attempts = " << total_attempts << endl;
    cout << "PI ~= " << fixed << setprecision(10) << final_estimate << endl;

    return 0;
}
