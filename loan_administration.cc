#include "loan.h"
#include "date.h"
#include "loan_administrator.h"
#include <iostream>
using namespace std;

int main() {
    // Date date;
    // cin >> date;
    // cout << date << endl;

    // Loan loan("Fisica2", "Frenk", Date(2019, 20, 20), Date(false));
    // cout << loan << endl;
    // cout << loan << endl;
    // cout << loan << endl;
    // cout << loan << endl;
    // cout << loan << endl;

    // Loan loan;
    // cin >> loan;
    // cout << loan << endl;

    // /* Debug loan_administrator - write */
    // Loan loan1("Fisica2", "Frenk", Date(2019, 20, 20), Date(false));
    // Loan loan2("Analisi1", "Fara", Date(2019, 20, 20), Date(false));
    // Loan loan3("PPS", "Enzo", Date(2019, 20, 20), Date(false));
    // LoanAdministrator admin;
    // admin.addLoan(loan1);
    // admin.addLoan(loan2);
    // admin.addLoan(loan3);
    // admin.writeOnFile("./register.txt");

    /* Debug loan_administrator - read */
    // LoanAdministrator admin;
    // admin.readFromFile("./in.txt");

    cout << "*** Your loan administration ***\n";
    LoanAdministrator admin;
    admin.readFromFile("./register.txt");
    admin.writeOnFile("out.txt");
    int choice;
    do {
        cout << "1- Print all loans\n";
        cout << "2- Search for loan title\n";
        cout << "3- Exit\n";
        cout << "Your choice: ";
        cin  >> choice;
        cout << endl;

        cout << admin << endl;
        // switch (choice) {
        //     case 1:
        //         cout << admin << endl;
        //         break;
        // }
    } while(choice != 3);


    return 0;
}
