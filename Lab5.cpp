/*course: CS215 - 004
 *Project: Lab 5
 *Purpose: First, it converts each number in the range of [1, 99]
 *         to its corresponding Roman Numeral.
 *         Second, it repeatedly asks the user to input a triangle size until
 *         the user enters "Q" or "q" to quit the program,
 *         then displays a triangles using stars (asterisk symbol) and the total
 *         rows of stars is equal to the user input size, say n.
 *         (The triangle contains one star at the first line,
 *         three little stars at the second line, and so on till 2*n-1
 *         stars at the nth line, and it is symmetric.)
 *         It displays the original triangle then rotates the triangle 90-degree clockwise
 *
 *Author: Nathan Jones
 */

#include <iostream>
#include <iomanip>
#include <limits>     //define numeric_limits
#include <string>

using namespace std;

// The compiler needs to see at least function prototype before the function can be called

// Sets the value of n and puts the corresponding
// Roman Numerals into the "roman" string
string roman_numeral(int n) {

    string roman;

    switch (n) {
        case 1: roman = "I"; break;
        case 2: roman = "II"; break;
        case 3: roman = "III"; break;
        case 4: roman = "IV"; break;
        case 5: roman = "V"; break;
        case 6: roman = "VI"; break;
        case 7: roman = "VII"; break;
        case 8: roman = "VIII"; break;
        case 9: roman = "IX"; break;
        case 10: roman = "X"; break;
        case 11: roman = "XI"; break;
        case 12: roman = "XII"; break;
        case 13: roman = "XIII"; break;
        case 14: roman = "XIV"; break;
        case 15: roman = "XV"; break;
        case 16: roman = "XVI"; break;
        case 17: roman = "XVII"; break;
        case 18: roman = "XVIII"; break;
        case 19: roman = "XIX"; break;
        case 20: roman = "XX"; break;
        case 21: roman = "XXI"; break;
        case 22: roman = "XXII"; break;
        case 23: roman = "XXIII"; break;
        case 24: roman = "XXIV"; break;
        case 25: roman = "XXV"; break;
        case 26: roman = "XXVI"; break;
        case 27: roman = "XXVII"; break;
        case 28: roman = "XXVIII"; break;
        case 29: roman = "XXIX"; break;
        case 30: roman = "XXX"; break;
        case 31: roman = "XXXI"; break;
        case 32: roman = "XXXII"; break;
        case 33: roman = "XXXIII"; break;
        case 34: roman = "XXXIV"; break;
        case 35: roman = "XXXV"; break;
        case 36: roman = "XXXVI"; break;
        case 37: roman = "XXXVII"; break;
        case 38: roman = "XXXVIII"; break;
        case 39: roman = "XXXIX"; break;
        case 40: roman = "XL"; break;
        case 41: roman = "XLI"; break;
        case 42: roman = "XLII"; break;
        case 43: roman = "XLIII"; break;
        case 44: roman = "XLIV"; break;
        case 45: roman = "XLV"; break;
        case 46: roman = "XLVI"; break;
        case 47: roman = "XLVII"; break;
        case 48: roman = "XLVIII"; break;
        case 49: roman = "XLIX"; break;
        case 50: roman = "L"; break;
        case 51: roman = "LI"; break;
        case 52: roman = "LII"; break;
        case 53: roman = "LIII"; break;
        case 54: roman = "LIV"; break;
        case 55: roman = "LV"; break;
        case 56: roman = "LVI"; break;
        case 57: roman = "LVII"; break;
        case 58: roman = "LVIII"; break;
        case 59: roman = "LIX"; break;
        case 60: roman = "LX"; break;
        case 61: roman = "LXI"; break;
        case 62: roman = "LXII"; break;
        case 63: roman = "LXIII"; break;
        case 64: roman = "LXIV"; break;
        case 65: roman = "LXV"; break;
        case 66: roman = "LXVI"; break;
        case 67: roman = "LXVII"; break;
        case 68: roman = "LXVIII"; break;
        case 69: roman = "LXIX"; break;
        case 70: roman = "LXX"; break;
        case 71: roman = "LXXI"; break;
        case 72: roman = "LXXII"; break;
        case 73: roman = "LXXIII"; break;
        case 74: roman = "LXXIV"; break;
        case 75: roman = "LXXV"; break;
        case 76: roman = "LXXVI"; break;
        case 77: roman = "LXXVII"; break;
        case 78: roman = "LXXVIII"; break;
        case 79: roman = "LXXIX"; break;
        case 80: roman = "LXXX"; break;
        case 81: roman = "LXXXI"; break;
        case 82: roman = "LXXXII"; break;
        case 83: roman = "LXXXIII"; break;
        case 84: roman = "LXXXIV"; break;
        case 85: roman = "LXXXV"; break;
        case 86: roman = "LXXXVI"; break;
        case 87: roman = "LXXXVII"; break;
        case 88: roman = "LXXXVIII"; break;
        case 89: roman = "LXXXIX"; break;
        case 90: roman = "XC"; break;
        case 91: roman = "XCI"; break;
        case 92: roman = "XCII"; break;
        case 93: roman = "XCIII"; break;
        case 94: roman = "XCIV"; break;
        case 95: roman = "XCV"; break;
        case 96: roman = "XCVI"; break;
        case 97: roman = "XCVII"; break;
        case 98: roman = "XCVIII"; break;
        case 99: roman = "XCIX"; break;
        default: roman = "Invalid input. Please enter a number between 1 and 99.";
    }

    return roman;
}

// Prints first triangle size n
void printTri(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < n - i; j++) {
            cout << " ";                                        // Spaces for triangle
        }

        for (int k = 0; k < 2 * i - 1; k++) {
            cout << "*";                                        // Stars for triangle
        }
        cout << endl;
    }
}

// Rotates triangle for size n
void printTriR90(int n) {
    for (int i = 1; i <= n; i++) {                              // Upper half of triangle
        for (int j = 1; j <= i; j++) {
            cout << "*";                                        // Stars for triangle
        }
        cout << endl;
    }

    for (int i = n - 1; i >= 1; i--) {                          // Lower half of triangle
        for (int j = 1; j <= i; j++) {
            cout << "*";                                        // Stars for triangle
        }
        cout << endl;
    }
}

int main()
{
    const int START = 1;      // The minimum number to convert
    const int END = 99;       // The maximum number to convert
    const int WIDTH = 10;     // formatted layout purpose: as WIDTH wide

    cout << "\tWelcome to CS215 Roman Numeral Converter!" << endl;
    cout << "\tDecimal\t\tRoman Numerals" << endl;

    for (int number = START; number <= END; number++)
    {
        cout << endl;
        string roman = roman_numeral(number);
        cout << setw(WIDTH) << number << "\t-->\t" << setw(WIDTH) << roman;
    }
    cout << endl << endl;

    bool toQuit = false;     // flag to decide whether to quit or not
    int triangle_size = 0;

    const int MINSIZE = 1;
    const int MAXSIZE = 70;

    do
    {
        cout << "Enter the size of your triangle (integer in [" << MINSIZE << ", " << MAXSIZE << "])" << endl;
        cout << "Type Q to quit the program: ";
        cin >> triangle_size;

        if (!cin.fail())
        {
            if (triangle_size >= MINSIZE && triangle_size <= MAXSIZE)
            {
                cout << "The triangle with size " << triangle_size << " (ROMAN NUMBER: " <<roman_numeral(triangle_size) << " ) is:" << endl;
                printTri(triangle_size);
                cout << "The rotation for 90 degrees clockwise: " << endl;
                printTriR90(triangle_size);
            }
            else
                cout << "The size is not in the correct range!" << endl;
        }
        else
        {
            cin.clear();
            string invalidOption;
            cin >> invalidOption;
            if (invalidOption == "Q" || invalidOption == "q")
                toQuit = true;
            else
                cout << "Invalid size!" << endl;
        }
        cin.ignore(numeric_limits<int>::max(), '\n'); //extra and ignore any bad input from input stream
    } while (!toQuit);

    cout << "Thank you, have a great day!" << endl;

    return 0;
}