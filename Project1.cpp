/*course: CS215 - 004
 *Project: Project 1
 *Purpose: Repeatedly asks the user to input a year for the Super Bowl,
 *         and displays the corresponding Super Bowl with Roman Numeral,
 *         until the user enters either “Q” or “q” to quit your program.
 *Author: Nathan Jones
 */

#include <iostream>
#include <limits>     //define numeric_limits
#include <string>

using namespace std;

//Turns a digit into a Roman numeral
string roman_digit(int digit, const string& one, const string& five, const string& ten) {
    string roman;
    switch (digit) {
        case 1: roman = one; break;
        case 2: roman = one + one; break;
        case 3: roman = one + one + one; break;
        case 4: roman = one + five; break;
        case 5: roman = five; break;
        case 6: roman = five + one; break;
        case 7: roman = five + one + one; break;
        case 8: roman = five + one + one + one; break;
        case 9: roman = one + ten; break;
        default: break;
    }
    return roman;
}

//Returns a string form of a Roman Numeral.
//(n must be between 1 and 3999)
string roman_numeral(int n) {
    int ones;
    int tens;
    int hundreds;
    int thousands;

    // Ones place
    ones = n % 10;
    n /= 10;

    // Tens place
    tens = n % 10;
    n /= 10;

    // Hundreds place
    hundreds = n % 10;
    n /= 10;

    // Thousands place
    thousands = n % 10;

    // Call roman_digit
    string unitRoman = roman_digit(ones, "I", "V", "X");
    string tenthRoman = roman_digit(tens, "X", "L", "C");
    string hundredRoman = roman_digit(hundreds, "C", "D", "M");
    string thousandRoman = roman_digit(thousands, "M", " ", " ");

    return thousandRoman + hundredRoman + tenthRoman + unitRoman;

}

int main()
{
    // Instantiate Variables
    const int START_SUPERBOWL = 1967;  // The first Super Bowl was hold in 1967 (at Los Angeles Memorial Coliseum)

    // define the correct range for Roman Numerals: [MIN_ROMAN, MAX_ROMAN]
    const int MIN_ROMAN = 1;
    const int MAX_ROMAN = 3999;

    bool toQuit = false;              // flag to decide whether to quit or not

    do
    {
        // Starting screen
        cout << "*************************************************************" << endl;
        cout << "*     The Super Bowl is the annual final playoff game       *" << endl;
        cout << "*         of the NFL to determine the league champion.      *" << endl;
        cout << "* The first Super Bowl took place on January 15, 1967.      *" << endl;
        cout << "* Super Bowl I (Los Angeles Memorial Coliseum) --> 1967     *" << endl;
        cout << "* This Roman Numerals Convertor is written by Nathan Jones. *" << endl;
        cout << "* If you had a time machine, which year of Super Bowl       *" << endl;
        cout << "* would you want to attend (1967 - 5965) ?                  *" << endl;
        cout << "*************************************************************" << endl;
        cout << "Please enter the year you want to attend (click Q or q to quit): " << endl;

        int year;
        cin >> year;

        // Checks validity of user input (year)
        if (!cin.fail())
        {
            if ((year - START_SUPERBOWL + 1 ) >= MIN_ROMAN && ((year - START_SUPERBOWL + 1) <= MAX_ROMAN))
            {
                cout << "The time machine will bring you to the year of " << year << ":" << endl;
                cout << "It is Super Bowl " << roman_numeral(year - START_SUPERBOWL + 1) << endl;
                cout << "We will help you find out the result and other interesting\ninformation...next time:)" << endl;
            }
            // If input is less than Super Bowl I
            else if (year < START_SUPERBOWL) {
                cout << "Wait!!! The year you enter is TOO EARLIER than the first Super Bowl" << endl;
            }
            // If input is greater than the limit for roman numerals
            else {
                cout << "Hold on!!! The year you enter is TOO BIG for Roman Numerals!" << endl;
            }
        }
        else
        {
            cin.clear();
            string invalidOption;
            cin >> invalidOption;
            if (invalidOption == "Q" || invalidOption == "q")
                toQuit = true;
            else
                cout << "Please use four-digit number to represent a year (1967-5965)!" << endl;
        }
        cin.ignore(numeric_limits<int>::max(), '\n'); //extra and ignore any bad input from input stream
        cout << endl;
    } while (!toQuit);

    cout << "Back to 2024, and have a great day!" << endl;

    return 0;
}
