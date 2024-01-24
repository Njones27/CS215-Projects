/*
 * Course: CS215-004
 * Project: Lab 3
 * Purpose: This program allows a user to pick whether they want an
 *          increasing or decreasing list, then the user inputs 3 numbers,
 *          and the program outputs the increasing or decreasing list and states
 *          if it is leniently or strictly increasing or decreasing.
 *
 * Author: Nathan Jones
 */

#include <iostream>
#include <string>

using namespace std;

int main() {

    cout << "Your wish is my command!" << endl;
    cout << "I will sort three numbers under your wish: " << endl;
    cout << "Enter I for increasing order, D for decreasing order (I or D): ";
    string order;
    cin >> order;

    if ((order == "I" || order == "i") || ((order == "D") || order == "d")) {   // Decides which order user wants
        if (order == "I" || order == "i") {                                     // Condition for increasing order
            cout << "Please enter three integer numbers: ";
            int num1, num2, num3;
            int firstNum, secondNum, thirdNum;
            cin >> num1 >> num2 >> num3;

            if (num1 <= num2 && num1 <= num3) {                                 // Tests whether 1st number is smallest
                firstNum = num1;                                                // and assign the rest of the list
                if (num2 <= num3) {
                    secondNum = num2;
                    thirdNum = num3;
                }
                else {
                    secondNum = num3;
                    thirdNum = num2;
                }

            }
            else if (num2 <= num1 && num2 <= num3) {                            // Tests whether 2nd number is smallest
                firstNum = num2;                                                // and assign the rest of the list
                if (num1 <= num3) {
                    secondNum = num1;
                    thirdNum = num3;
                }
                else {
                    secondNum = num3;
                    thirdNum = num1;
                }
            }
            else {                                                              // 3rd number is smallest, assigns the
                firstNum = num3;                                                // rest of the list
                if (num1 <= num2) {
                    secondNum = num1;
                    thirdNum = num2;
                }
                else {
                    secondNum = num2;
                    thirdNum = num1;
                }
            }

            cout << "Numbers are sorted in increasing order: " << endl;
            cout << firstNum << " --> " << secondNum << " --> " << thirdNum << endl;

            if ((num1 == num2) || (num1 == num3) || (num2 == num3)) {            // Tests if input numbers match
                cout << "Numbers are in leniently increasing order!" << endl;
            }
            else {
                cout << "Numbers are in strictly increasing order!" << endl;
            }

        }

        else if (order == "D" || order == "d") {                                // Condition for decreasing order
            cout << "Please enter three integer numbers: ";
            int firstNum, secondNum, thirdNum;
            int num1, num2, num3;
            cin >> num1 >> num2 >> num3;

            if (num1 >= num2 && num1 >= num3) {                                 // Tests whether 1st number is biggest
                firstNum = num1;                                                // and assign the rest of the list
                if (num2 >= num3) {
                    secondNum = num2;
                    thirdNum = num3;
                }
                else {
                    secondNum = num3;
                    thirdNum = num2;
                }
            }

            else if (num2 >= num1 && num2 >= num3) {                            // Tests whether 2nd number is biggest
                firstNum = num2;                                                // and assign the rest of the list
                if (num1 >= num3) {
                    secondNum = num1;
                    thirdNum = num3;
                }
                else {
                    secondNum = num3;
                    thirdNum = num1;
                }
            }

            else {                                                              // Tests whether 2nd number is biggest
                firstNum = num3;                                                // and assign the rest of the list
                if (num1 >= num2) {
                    secondNum = num1;
                    thirdNum = num2;
                }
                else {
                    secondNum = num2;
                    thirdNum = num1;
                }
            }

            cout << "Numbers are sorted in decreasing order: " << endl;
            cout << firstNum << " <-- " << secondNum << " <-- " << thirdNum << endl;

            if ((num1 == num2) || (num1 == num3) || (num2 == num3)) {            // Tests if input numbers match
                cout << "Numbers are in leniently decreasing order!" << endl;
            }
            else {
                cout << "Numbers are in strictly decreasing order!" << endl;
            }
        }
    }
    else {
        cout << "Invalid choice, quitting the program..." << endl;
    }

    return 0;
}
