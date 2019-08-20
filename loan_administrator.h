#include "loan.h"
#include "date.h"
#include <map>
#include <fstream>

class LoanAdministrator {
private:
    std::map<std::string, Loan> loans;
    const std::string registerFile = "./register.txt";
public:
    /* Constructor */
    LoanAdministrator() {}

    /* Destructors */
    ~LoanAdministrator() {
        writeOnFile(registerFile);
    }

    /* Getter */
    std::map<std::string, Loan> getLoans() const { return loans; }

    /* Adding a loan */
    void addLoan(const Loan& loan) {
        loans[loan.getTitle()] = loan;
    }
    /* Adding from string */
    void addLoanFromString(const std::string& loanString) {
        Loan loan;
        loan.readFromString(loanString);
        this->addLoan(loan);
    }

    /* Write on file */
    void writeOnFile(const std::string& file) {
        std::ofstream outStream(file);
        for(auto el : loans) {
            outStream << el.second << std::endl;
        }
        outStream.close();
    }

    /* Read from file */
    void readFromFile(const std::string& file) {
        std::ifstream inStream(file);
        std::string line;
        while(getline(inStream, line)) {
            addLoanFromString(line);
        }
        inStream.close();
    }

};
/* Operator "<<" overloading */
std::ostream& operator<<(std::ostream& out, const LoanAdministrator& loans) {
    for(auto el : loans.getLoans()) {
        out << el.second << std::endl;
    }
}
