#ifndef __DATE_H__
#define __DATE_H__

#include <iostream>
#include <vector>
#include <sstream>

class Date {
private:
    int year;
    int month;
    int day;
    bool valid = true;
public:
    /* Constructor */
    Date(int year, int month, int day) {
        this->year = year;
        this->month = month;
        this->day = day;
    }
    Date(bool valid) {
        this->valid = valid;
    }
    Date() {
        this->year = 2000;
        this->month = 1;
        this->day = 1;
    }
    /* Setters */
    void setYear(int year) { this->year = year; }
    void setMonth(int month) { this->month = month; }
    void setDay(int day) { this->day = day; }
    void setValid(bool valid) { this->valid = valid; }
    /* Getters */
    int getYear() const { return this->year; }
    int getMonth() const { return this->month; }
    int getDay() const { return this->day; }
    bool getValid() const { return this->valid; }
};
/* Operator "<<" overloading */
std::ostream& operator<<(std::ostream& out, const Date& date) {
    if(date.getValid()) {
        out << date.getYear();
        out << "/";
        if(date.getMonth() < 10) {
            out << "0";
        }
        out << date.getMonth();
        out << "/";
        if(date.getDay() < 10) {
            out << "0";
        }
        out << date.getDay();
    } else {
        out << "--/--/--";
    }
}
/* Operator ">>" overloading */
std::istream& operator>>(std::istream& in, Date& date) {
    std::string dateString;
    in >> dateString;

    std::istringstream dateStringStream(dateString);
    std::string number;
    std::vector<int> dateVector;
    while(getline(dateStringStream, number, '/')) {
        if(number == "--") {
            date.setValid(false);
            break;
        }
        dateVector.push_back(stoi(number));
    }

    if(date.getValid()) {
        date.setYear(dateVector[0]);
        date.setMonth(dateVector[1]);
        date.setDay(dateVector[2]);
    }
}

#endif
