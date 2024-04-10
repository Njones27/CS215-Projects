/*
 * Course: CS215-004
 * Project: Project 2
 * Purpose: Math tutor for Fourth Grade students in an elementary
            school. The program repeatedly displays the following menu to allow the student to select an
            addition, a subtraction, a multiplication, or a division question to solve, until the student chooses
            option 5 to quit the program.
 *Author: Nathan Jones
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "MathOperations.h"
#include "MathReport.h"

using namespace std;

int main() {

    // Instantiate Variables and objects
    int num1;          // The first operand for the operations
    int num2;          // The second operand for the operations
    int choice = 0;     // The user's choice: either answer the question or quit
    int answered = 0;   // Increases when a question is answered
    string userInput;   // User input for the input checker
    MathOperations question;
    MathReport userReport;

    // Start menu
    cout << "Four basic Math operations are: + - * " << DivisionSymbol << endl;
    cout << "They are considered to be the cornerstone of Math." << endl;
    cout << "I am your online math tutor, my name is Nathan Jones" << endl;
    cout << "I will help you build skills in Mathematics." << endl;
    cout << "You will gain confidence by practicing some questions." << endl;
    cout << endl;

    // Seed the random number generator.
    srand(time(NULL));

    bool isBad = true; // Variable for bad input

    // Loops until user wants to quit practice by inputting 5
    while (choice != 5) {

        // Checks for bad input
        while (isBad) {
            // Setup screen
            cout << "        Math Is Fun! Take a challenge..." << endl;
            cout << "--------------------------------------" << endl;
            cout << "1. Addition problem" << endl;
            cout << "2. Subtraction problem" << endl;
            cout << "3. Multiplication problem" << endl;
            cout << "4. Division problem" << endl;
            cout << "5. Quit this program" << endl;
            cout << "--------------------------------------" << endl;
            cout << "Enter your choice (1-5): " << endl;
            getline(cin, userInput);
            char firstCharacter = userInput[0]; // First character of user  input


            // Sets choice to the numerical ASCII value based off the user input, else input is invalid
            if (isdigit(firstCharacter)) {
                choice = firstCharacter - '0';

                // Checks to see if input is in range 1 to 5
                if (choice >= 1 && choice <= 5) {
                    isBad = false;
                } else {
                    cout << "Invalid choice! The valid choices are 1, 2, 3, 4, and 5." << endl;
                }
            } else {
                cout << "Invalid choice!" << endl;
            }
        }
            // If user selects addition practice
            if (choice == 1) {
                num1 = rand() % 500 + 1;
                num2 = rand() % 500 + 1;
                question.setOperands(num1, num2);
                question.Addition();
                int studentAnswer = question.collectUserAnswer();
                if (question.checkAnswer(studentAnswer)) {
                    cout << "Congratulations! " << studentAnswer << " is the right answer." << endl;
                } else {
                    cout << "Sorry, the answer is wrong. You may practice again." << endl;
                }
                userReport.insert(question, studentAnswer);
                cout << endl << endl;
                answered++;
            }
            // If user selects subtraction practice
            else if (choice == 2) {
                num1 = rand() % 500 + 1;
                num2 = rand() % 500 + 1;
                question.setOperands(max(num1, num2), min(num1, num2));
                question.Subtraction();
                int studentAnswer = question.collectUserAnswer();
                if (question.checkAnswer(studentAnswer)) {
                    cout << "Congratulations! " << studentAnswer << " is the right answer." << endl;
                } else {
                    cout << "Sorry, the answer is wrong. You may practice again." << endl;
                }
                userReport.insert(question, studentAnswer);
                cout << endl << endl;
                answered++;
            }
            // If user selects multiplication practice
            else if (choice == 3) {
                num1 = rand() % 89 + 11;
                num2 = rand() % 8 + 2;
                question.setOperands(num1, num2);
                question.Multiplication();
                int studentAnswer = question.collectUserAnswer();
                if (question.checkAnswer(studentAnswer)) {
                    cout << "Congratulations! " << studentAnswer << " is the right answer." << endl;
                } else {
                    cout << "Sorry, the answer is wrong. You may practice again." << endl;
                }
                userReport.insert(question, studentAnswer);
                cout << endl << endl;
                answered++;
            }
            // If user selects division practice
            else if (choice == 4) {
                num1 = rand() % 8 + 2;
                num2 = (rand() % 98 + 2) * num1;
                question.setOperands(num2, num1);
                question.Division();
                int studentAnswer = question.collectUserAnswer();
                if (question.checkAnswer(studentAnswer)) {
                    cout << "Congratulations! " << studentAnswer << " is the right answer." << endl;
                } else {
                    cout << "Sorry, the answer is wrong. You may practice again." << endl;
                }
                userReport.insert(question, studentAnswer);
                cout << endl << endl;
                answered++;
            }
            isBad = true;
    }

    // Checks if a question is answered
    if (answered > 0) {
        // When choice is 5
        bool withAnswer; // Creates condition if there should be an answer with the report

        // Checks if there are wrong answers
        if (userReport.getNumOfWrongAnswers() != 0) {
            withAnswer = false;
            userReport.generateReport(withAnswer);

            // Loops to see if user wants to quit program
            while (true) {
                cout << "Do you want to practice the questions with wrong answers?" << endl;
                cout << "(enter Q or q to quit)" << endl;
                string userInput2;
                getline(cin, userInput2); // Gathers second user input to see if user wants to quit

                // Checks if user wants to quit
                if (userInput2 != "Q" && userInput2 != "q") {
                    userReport.needMorePractice();
                } else {
                    break; // Exits loop
                }
                // Checks if there are no more wrong answers
                if (userReport.getNumOfWrongAnswers() == 0) {
                    break; // Exits loop
                }
            }

        }
        withAnswer = true;
        userReport.generateReport(withAnswer);
        cout << "I am your online Math Tutor, Nathan Jones. See you next time." << endl;
    }
    // Checks if user did not input an answer
    else if (answered == 0) {
        cout << "I am your online Math Tutor, Nathan Jones. See you next time." << endl;
    }
    return 0;
}



