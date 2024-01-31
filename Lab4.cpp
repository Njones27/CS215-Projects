/*
 * Course: CS215-004
 * Project: Lab 4
 * Purpose: This program checks the validity of an 8-digit
 *          credit card number using a specified algorithm,
 *          involving the calculation of a check digit.
 *
 * Author: Nathan Jones
 */
#include <iostream>
#include <string>

using namespace std;

int main() {

    while (true) {

        // Sets up initial prompt and gets the entire line for user input
        cout << "Please enter the 8-digit credit card number (enter -1 to quit): " << endl;
        string initialInput;
        getline(cin, initialInput);

        // Tests if user input is "-1", if so, loop breaks
        if (initialInput == "-1") {
            cout << "Thank you for using Credit Card Number Validation!" << endl;
            break;
        }

        // Initialize variables
        int first = initialInput.at(0) - '0';
        int second = initialInput.at(1) - '0';
        int third = initialInput.at(2) - '0';
        int fourth = initialInput.at(3) - '0';
        int fifth = initialInput.at(4) - '0';
        int sixth = initialInput.at(5) - '0';
        int seventh = initialInput.at(6) - '0';
        int eighth = initialInput.at(7) - '0';

        // Sum of first set of numbers
        int firstSum = eighth + sixth + fourth + second;

        // Doubles the unused numbers
        int double1 = first * 2;
        int double3 = third * 2;
        int double5 = fifth * 2;
        int double7 = seventh * 2;

        // Calculates the doubled digits
        int lastDigit1 = double1 % 10;
        int firstDigit1 = double1 / 10;
        int lastDigit3 = double3 % 10;
        int firstDigit3 = double3 / 10;
        int lastDigit5 = double5 % 10;
        int firstDigit5 = double5 / 10;
        int lastDigit7 = double7 % 10;
        int firstDigit7 = double7 / 10;

        // Combines the first and last digit of the second set of numbers
        int secondSum = lastDigit1 + firstDigit1 + lastDigit3 + firstDigit3 +
                        lastDigit5 + firstDigit5 + lastDigit7 + firstDigit7;

        // Combines the two sums
        int total = firstSum + secondSum;

        // Checks if the number is valid
        if (total % 10 == 0) {
            cout << "Number is valid." << endl;
        }

        // Calculates the check digit by evaluating all 9 possibilities
        else {
            cout << "Number is invalid." << endl;
            int check;

            total -= eighth;
            for (int i = 0; i < 10; i++) {
                if ((i + total) % 10 == 0) {
                    check = i;
                }
            }
            cout << "Check digit should have been " << check << endl;
        }
    }

    return 0;
}
