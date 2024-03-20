/*
 *Course: CS215-008
 *Project: Lab 8
 *Purpose: to implement a Gradebook Report
 *         it allows the user to input students' scores
 *         until the user types "q" or "Q" to quit
 *         then displays all the valid scores from user input
 *                       and the corresponding letter grades;
 *                       the average score, highest score and lowest score.
 *Author: Nathan Jones
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "FinalGrade.h"

using namespace std;

double calculateGradebook(const vector<FinalGrade>& gradebook, double& max_score, double& min_score);

int main()
{
    // Initialize an empty vector
    vector<FinalGrade> CS215gradebook;
    double input_score;

    // User-input validation
    while (true)
    {
        cout << "Please enter a score for CS215 (type 'Q' or 'q' to quit): " << endl;
        cin >> input_score;
        cin.ignore(256, '\n');

        // check if the user input is invalid
        if (cin.fail())
        {
            string check_input;
            cin.clear();
            cin >> check_input;
            cin.ignore(256, '\n');
            if (check_input == "Q" || check_input == "q")
                break;
            else {
                cout << "Invalid input, please try again..." << endl;
                continue;
            }
        }

        // check if the input score is in the correct range: [0,100]
        if (input_score < 0 || input_score > 100)
        {
            cout << "The score is not in the correct range, please try again..." << endl;
        }
        else  // valid user input, store into gradeList object
        {
            FinalGrade inputFG(input_score);
            CS215gradebook.push_back(inputFG);
        }
    }

    // Check if the gradebook is empty
    // If it is empty, report it then quit the program
    if (CS215gradebook.size() == 0)
    {
        cout << "The gradebook for CS215 is empty!" << endl;
        return 1;
    }

    // if the gradebook is not empty
    // Display each score and corresponding letter grade in the grade
    // Display the average score, the highest and lowest scores from the gradebook
    cout << endl << endl;
    cout << "The gradebook for CS215:" << endl;
    for (int i = 0; i < CS215gradebook.size(); i++)
    {
        CS215gradebook[i].print();
    }

    double max_score = 0;
    double min_score = 0;
    double average = 0;
    average = calculateGradebook(CS215gradebook, max_score, min_score);
    cout << fixed << setprecision(2);
    cout << "The average score is: " << average << endl;
    cout << "The highest score is: " << max_score << endl;
    cout << "The lowest score is: " << min_score << endl;
    return 0;
}

/*
 * it finds the highest score and lowest score of the gradebook
 *    then returns the average score from the gradebook
 *@para gradebook vector<FinalGrade>: the vector of FinalGrade objects to represent the gradebook (const call by reference for efficiency and safety purpose)
 *@para max_score double (call by reference): stores the highest score in the gradebook
 *@para min_score double (call by reference): stores the lowest score in the gradebook
 *@return double: the average score from the gradebook
 */
double calculateGradebook(const vector<FinalGrade>& gradebook, double& max_score, double& min_score) {
    // Gives max_score and min_score a value, such as the first score
    max_score = gradebook[0].getScore();
    min_score = gradebook[0].getScore();

    // Calculates the sum of all the scores
    double sum = 0.0;
    for (int i = 0; i < gradebook.size(); i++) {
        sum += gradebook[i].getScore();
        if (gradebook[i].getScore() > max_score) {
            max_score = gradebook[i].getScore();
        }
        if (gradebook[i].getScore() < min_score) {
            min_score = gradebook[i].getScore();
        }
    }

    // Calculates the average score
    double average = sum / gradebook.size();
    return average;
}
