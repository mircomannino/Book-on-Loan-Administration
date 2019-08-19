#include "loan.h"
#include "date.h"
#include <iostream>
using namespace std;

int main() {
    // Date date;
    // cin >> date;
    // cout << date << endl;

    Loan loan("Fisica2", "Frenk", Date(2019, 20, 20), Date(false));
    cout << loan << endl;
    cout << loan << endl;
    cout << loan << endl;
    cout << loan << endl;
    cout << loan << endl;

    return 0;
}
