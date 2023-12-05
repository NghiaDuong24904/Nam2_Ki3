#include <iostream>
#include <ctime>

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date() {
        // Get current time
        std::time_t t = std::time(0);
        std::tm* now = std::localtime(&t);

        // Initialize the Date object with the current date
        day = now->tm_mday;
        month = now->tm_mon + 1; // tm_mon is 0-based, so add 1
        year = now->tm_year + 1900; // tm_year is years since 1900
    }

    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    void displayDate() {
        std::cout << "Date: " << day << "/" << month << "/" << year << std::endl;
    }
};

int main() {
    Date defaultDate;

    std::cout << "Default ";
    defaultDate.displayDate();

    Date customDate(25, 12, 2023);

    std::cout << "Custom ";
    customDate.displayDate();

    return 0;
}
