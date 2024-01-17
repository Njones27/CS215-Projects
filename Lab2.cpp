/*
 * Course: CS215-004
 * Project: Lab 2
 * Purpose: This program directs a cashier how to give change.
 *          The program has two inputs: the amount due and the amount received
 *          from the customer (expressed in dollars).
 *          The outputs displayed are dollars, dimes, nickels,
 *          and pennies that the customer should receive in return.
 *
 * Author: Nathan Jones
 */

#include <iostream>

using namespace std;

int main() {

    // User inputs the amount due and the amount paid
    double amount = 0;
    double paid = 0;
    cout << "Enter the amount due: $";
    cin >> amount;
    cout << "Enter the amount received: $";
    cin >> paid;

    // Initialize monetary variables
    double change = (paid - amount);
    int changeToCents = static_cast<int>(round(change * 100));  // Rounds change and converts the double into an integer
    int dollars = changeToCents / 100;
    int centsRemain = changeToCents % 100;  // Amount left after dollars
    int quarters = centsRemain / 25;
    centsRemain %= 25;                    // Amount of cents after quarters, assigns centsRemain to that value
                                          // TA Question: centsRemain = centsRemain % 25;
    int dimes = centsRemain / 10;
    centsRemain %= 10;                    // Amount of cents after dimes, assigns centsRemain to that value
    int nickels = centsRemain / 5;
    centsRemain %= 5;                     // Amount of cents after nickels, assigns centsRemain to that value
    int pennies = centsRemain;

    // A condition-statement for if the amount paid is less than amount due
    // If change is less than 0, then an error message is displayed and program ends
    if (change > 0) {
        cout << "The change is: " << endl;
        cout << "Dollars:                " << dollars << endl;
        cout << "Quarters:               " << quarters << endl;
        cout << "Dimes:                  " << dimes << endl;
        cout << "Nickels:                " << nickels << endl;
        cout << "Pennies                 " << pennies << endl;
    }
    else {
        cout << "Please enter a number greater than the amount due. " << endl;
    }

    return 0;
}
