//
// Created 02/08/2024 | Rako
//

#include <iostream>
#include <ctime>
#include <cstring>
#include <cerrno>
#include <sys/stat.h>
#include <utime.h>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 8) {
        cerr << "Usage: " << argv[0] << " file month day year hour minute second" << endl;
        return 1;
    }

    // Command line arguments
    const char *filename = argv[1];
    int month = stoi(argv[2]);
    int day = stoi(argv[3]);
    int year = stoi(argv[4]);
    int hour = stoi(argv[5]);
    int minute = stoi(argv[6]);
    int second = stoi(argv[7]);

    // Validate time
    if (month < 1 || month > 12 || day < 1 || day > 31 || hour < 0 || hour > 23 ||
        minute < 0 || minute > 59 || second < 0 || second > 59) {
        cerr << "Error: Invalid date/time values." << endl;
        return 1;
    }

    // Construct new time
    struct tm newTime;
    memset(&newTime, 0, sizeof(struct tm));
    newTime.tm_year = year - 1900;
    newTime.tm_mon = month - 1;
    newTime.tm_mday = day;
    newTime.tm_hour = hour;
    newTime.tm_min = minute;
    newTime.tm_sec = second;

    // Convert tm -> time_t
    time_t t = mktime(&newTime);
    if (t == (time_t) - 1) {
        cerr << "Error: Failed to convert time." << endl;
        return 1;
    }

    // Update
    struct utimbuf newTimes;
    newTimes.actime = t;
    newTimes.modtime = t;
    if (utime(filename, &newTimes) != 0) {
        cerr << "Error: Failed to update file timestamp (" << strerror(errno) << ")." << endl;
        return 1;
    }

    // Print
    char buf[80];
    strftime(buf, sizeof(buf), "%a %b %d %H:%M:%S %Y", &newTime);
    cout << "Changing file " << filename << " timestamps to " << buf << endl;

    return 0;
}
