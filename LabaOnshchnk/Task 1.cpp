#include <iostream>
#include <cmath>

class Date{

    uint64_t resDifferenceOfYear;
    uint64_t year, month, day, hour, minute, second;
    static const int startYear = 1970;
    static const int startYearFile = 1601;

    uint64_t convert() {
        uint64_t year, month = 0;
        uint64_t leapYear = 0;
        uint64_t noLeapYear = 0;
        for (int i = startYear; i < year; i++) {
            if (i % 4 ||( i % 100 == 0 && i % 400)) {
                noLeapYear++;
            }
            else {
                leapYear++;
            }
        }
        year = leapYear * 31622400 + noLeapYear * 31536000;
        for (int i = 1; i < month; i++) {
            if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {
                month = month + 31 * 86400;
            }
            if (i == 4 || i == 6 || i == 9 || i == 11) {
                month = month + 30 * 86400;
            }
            if (i == 2) {
                if (year % 4 == 0 && year % 100 != 0 && year % 400 == 0) {
                    month = month + 29 * 86400;
                }
                else {
                    month = month + 28 * 86400;
                }
            }
        }

        return (year + month + (day - 1) * 86400 + (hour) * 3600 + (minute) * 60 + second);
    }

public:
    Date() {
        year = 0;
        month = 0;
        day = 0;
        hour = 0;
        minute = 0;
        second = 0;
    }

    Date(const Date& date) {
        year = date.year;
        month = date.month;
        day = date.day;
        hour = date.hour;
        minute = date.minute;
        second = date.second;
        convert();
        std::cout << "Copy here." << std::endl;
    }

    ~Date() {
        std::cout << "Destructor here." << std::endl;
    }

    Date(int aYear, int aMonth, int aDay, int aHour, int aMinute, int aSecond) {
        year = aYear;
        month = aMonth;
        day = aDay;
        hour = aHour;
        minute = aMinute;
        second = aSecond;
        int leapYearTmp = 0;
        int noLeapYearTmp = 0;
        for (int i = startYearFile; i < startYear; i++) {
            if (i % 4 == 0 && i % 100 != 0 && i % 400 == 0){
                leapYearTmp++;
            }
            else {
                noLeapYearTmp++;
            }
        }
        resDifferenceOfYear = leapYearTmp * 31622400 + noLeapYearTmp * 31536000;
        convert();
    }

    uint64_t get_year() {
        return year;
    }

    uint64_t get_month() {
        return month;
    }

    uint64_t get_day() {
        return day;
    }

    uint64_t get_hour() {
        return hour;
    }

    uint64_t get_minute() {
        return minute;
    }

    uint64_t get_second() {
        return second;
    }
    uint64_t get_time() {
        return convert();
    }

    void print(uint64_t a) {
        if (a == 1) {
            std::cout << convert() << std::endl;
        }
        else {
            std::cout << "Year:" << year << " Month:" << month << " Day:" << day << " Hour:" << hour << " Minute:" << minute << " Second:" << second << std::endl;
        }
    }
    
    void input(uint64_t year, uint64_t month, uint64_t day, uint64_t hour, uint64_t minute, uint64_t second ) {
        year = year;
        month = month;
        day = day;
        hour = hour;
        minute = minute;
        second = second;
        convert();
    }

    void input(uint64_t a) {
        unsigned int daysOfMonths_usual[12] = {31,28,31,30,31,30,31,31,30,31,30,31}; // No leap year
        unsigned int daysOfMonths_special[12] = {31,29,31,30,31,30,31,31,30,31,30,31}; // Leap year
        int year = (a / 31436000) + 1970;
        int day = a / 86400;
        int seconds = day;
        day = day - (year - 1969) / 4;
        day = day % 365;
        int month = 1;
        if (year % 4 == 0 && year % 100 != 0 && year % 400 == 0) {
            for (int i = 0; day > daysOfMonths_usual[i]; i++) {
                day = day - daysOfMonths_usual[i];
                month = i + 1;
            }
        }
        else {
            for (int i = 0; day > daysOfMonths_special[i]; i++) {
                day = day - daysOfMonths_special[i];
                month = i + 2;
            }
        }

        seconds = a - (seconds * 86400);
        int hours = seconds / 3600;
        int minutes = (seconds - (hours * 3600)) / 60;
        seconds = (seconds - (hours * 3600)) - (minutes * 60);
        year = year;
        month = month;
        day = day + 1;
        hour = hours;
        minute = minutes;
        second = seconds;
        convert();
    }

    unsigned long long inFiletime() {
        unsigned long long timeFile = (convert() + resDifferenceOfYear) * 10000000LL;
        return timeFile;
    }

    friend Date operator+ (const Date& x, const Date& y);
    friend Date operator - (const Date& x, const Date& y);
    friend std::ostream& operator<< (std::ostream& out, Date& x);
    friend std::istream& operator>> (std::istream& in, Date& x);
    operator uint64_t() { return convert(); }
    Date operator= (const Date& x) {
        if (this != &x) {
            year = x.year;
            month = x.month;
            day = x.day;
            hour = x.hour;
            minute = x.minute;
            second = x.second;
        }
        return *this;
    }
};

Date operator+ (const Date& x, const Date& y) {
    uint64_t year = x.year + y.year;
    uint64_t month = x.month + y.month;
    uint64_t day = x.day + y.day;
    uint64_t hour = x.hour + y.hour;
    uint64_t minute = x.minute + y.minute;
    uint64_t second = x.second + y.second;
    return Date(year, month, day, hour, minute, second);
}

Date operator- (const Date& x, const Date& y) {
    uint64_t year = x.year - y.year;
    uint64_t month = x.month - y.month;
    uint64_t day = x.day - y.day;
    uint64_t hour = x.hour - y.hour;
    uint64_t minute = x.minute - y.minute;
    uint64_t second = x.second - y.second;
    return Date(year, month, day, hour, minute, second);
}

std::ostream& operator<< (std::ostream& out, Date& x) {
    out << x.convert();
    return out;
}

std::istream& operator>> (std::istream& in, Date& x) {
    in >> x.year >> x.month >> x.day >> x.hour >> x.minute >> x.second;
    x.convert();
    return in;
}

int main() {
    Date b(2021, 1, 20, 1, 1, 2);
    Date x;
    x.input(1611104462);
    std::cout << b << std::endl;
    x.print(0);
    // return 0;
    Date y = x;
    std::cout << (Date) y << std::endl;
}
