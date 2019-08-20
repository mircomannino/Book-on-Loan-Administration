#include "loan.h"
#include "date.h"
#include "loan_administrator.h"
#include <iostream>
using namespace std;

int main() {
    cout << "*** Your loan administration ***\n";
    /* Load initial data */
    LoanAdministrator admin;
    admin.readFromFile("./register.txt");

    int choice;
    do {
        cout << "1- Print all loans\n";
        cout << "2- Search for loan title\n";
        cout << "3- Add a loan\n";
        cout << "4- Delete a loan\n";
        cout << "5- Exit\n";
        cout << "Your choice: ";
        cin  >> choice;
        cout << endl;

        switch (choice) {
            case 1: {
                cout << admin << endl;
                break;
            }
            case 2: {
                string searchTitle;
                cout << "Insert a title: ";
                cin  >> searchTitle;
                Loan findLoan = admin.searchPerTitle(searchTitle);
                if(findLoan.getTitle() != "") {
                    cout << "Title found:\n";
                    cout << findLoan << endl << endl;
                } else {
                    cout << "Title not found\n\n";
                }
                break;
            }
            case 3: {
                string title;
                string person;
                Date start;
                Date end;
                cout << "Insert title: ";
                cin  >> title;
                cout << "Insert person: ";
                cin  >> person;
                cout << "Insert start date: ";
                cin  >> start;
                cout << "Insert end date: ";
                cin  >> end;
                Loan loan(title, person, start, end);
                admin.addLoan(loan);
                cout << "Loan added successfully\n\n";
                break;
            }
            case 4: {
                string titleToDelete;
                cout << "Insert a title to delete: ";
                cin  >> titleToDelete;
                if(admin.deleteLoan(titleToDelete)) {
                    cout << "Title deleted successfully\n\n";
                } else {
                    cout << "The title you insert does not exist\n\n";
                }

            }
        }

        /* Clean the screen */
        cout << "Press any key to continue...\n";
        cin.get(); cin.get();
        system("clear");
    } while(choice != 5);


    return 0;
}
