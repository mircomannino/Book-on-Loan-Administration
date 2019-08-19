#ifndef __LOAN_H__
#define __LOAN_H__

#include <iostream>
#include <sstream>
#include "date.h"

class Loan {
private:
    std::string title;
    std::string person;
    Date start;
    Date end;
public:
    /* Constructor */
    Loan(const std::string& title, const std::string& person, Date start, Date end) {
        this->title = title;
        this->person = person;
        this->start = start;
        this->end = end;
    }
    /* Getters */
    std::string getTitle() const { return this->title; }
    std::string getPerson() const { return this->person; }
    Date getStart() const { return this->start; }
    Date getEnd() const { return this->end; }
    /* Read from file */
    void readFromString(const std::string& line) {
        std::stringstream is(line);
        is >> this->title;
        is >> this->person;
        is >> this->start;
        is >> this->end;
    }
};
/* Operator "<<" overloading */
std::ostream& operator<<(std::ostream& out, const Loan& loan) {
    out << loan.getTitle() << "            ";
    out << loan.getPerson() << "            ";
    out << loan.getStart() << "            ";
    out << loan.getEnd() << "            ";
}

#endif
