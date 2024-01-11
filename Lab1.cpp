/*
 * Course: CS215-004
 * Project: Lab 1
 * Purpose: this program first displays a greeting message
 *          followed by a smiley face,
 *          then it asks the user to input how many "likes" they 
 *			would give for the face and display the result.
 *
 * Author: Nathan Jones
 */

#include <iostream>

using namespace std;

int main() {
    cout << "Hello Atik," << endl;
    cout << "I am glad you are my TA." << endl;
    cout << "My name is Nathan Jones. Nice to meet you!" << endl;
    cout << endl << endl;

    // Prints a happy face
    cout << "     ~~~~~~~~~~" << endl;
    cout << "   // IIIIIIII \\\\" << endl;
    cout << "   /|          |\\" << endl;
    cout << "    |  ~~  ~~  |" << endl;
    cout << "   {{   *  *   }}" << endl;
    cout << "    |    >     |" << endl;
    cout << "    |   \\___/  |" << endl;
    cout << "    |__________|" << endl;
    cout << endl << endl;

    // Declares an integer variable called "likes" to store the number of likes
    double likes = 0;
    cout << "Please rate this face (0-10):" << endl;
    cout << "How many LIKES?: ";
    cin >> likes;
    cout << "The smiling face has " << likes << " LIKE(s)!" << endl;

    // Collects user input and calculate the time spent
    double hours = 0.0; // declare a variable to store how many hours
    cout << "How many hours are you going to spend on CS215 every week ? " << endl;
    cin >> hours;
    const int HOUR_TO_MIN = 60; //declare a constant: 1 hour = 60 minutes
    const int MIN_TO_SEC = 60; //declare a constant: 1 minute = 60 seconds
    double seconds = hours * HOUR_TO_MIN * MIN_TO_SEC;
    cout << "Good Luck! You will spend " << seconds << " seconds each week on CS215." << endl;

    return 0;
}