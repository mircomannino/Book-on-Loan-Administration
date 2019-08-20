#ifndef __LOAN_H__
#define __LOAN_H__

#include "date.h"
#include <iostream>
#include <sstream>
#include <iomanip>

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
    Loan() {
        this->title = "";
        this->person = "";
        this->start = "--/--/--";
        this->end = "--/--/--";
    }
    /* Setters */
    void setTitle(const std::string& title) { this->title = title; }
    void setPerson(const std::string& person) { this->person = person; }
    void setStart(const Date& start) { this->start = start; }
    void setEnd(const Date& end) {this->end = end; }
    /* Getters */
    std::string getTitle() const { return this->title; }
    std::string getPerson() const { return this->person; }
    Date getStart() const { return this->start; }
    Date getEnd() const { return this->end; }
    /* Read from string */
    void readFromString(const std::string& line) {
        std::stringstream is(line);
        is >> this->title;
        is >> this->person;
        is >> this->start;
        is >> this->end;
    }
};
/* Operator ">>" overloading */
std::istream& operator>>(std::istream& in, Loan& loan) {
    std::string loanString;
    std::string word;
    for(int i = 0; i < 4; i++) {
        in >> word;
        loanString += word + " ";
    }

    std::istringstream loanStringStream(loanString);
    std::string titleInput;
    std::string personInput;
    Date startInput;
    Date endInput;

    loanStringStream >> titleInput;
    loanStringStream >> personInput;
    loanStringStream >> startInput;
    loanStringStream >> endInput;

    loan.setTitle(titleInput);
    loan.setPerson(personInput);
    loan.setStart(startInput);
    loan.setEnd(endInput);

    return in;
}
/* Operator "<<" overloading */
std::ostream& operator<<(std::ostream& out, const Loan& loan) {
    out << loan.getTitle()  << "\t\t";
    out << loan.getPerson() << "\t\t";
    out << loan.getStart()  << "\t\t";
    out << loan.getEnd();

    return out;
}

#endif
