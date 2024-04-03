/*
 * course: CS215-004
 * Project: Lab 10 (as part of Project 2)
 * Purpose: this program can be used as a math tutor for a young student:
 *                       In the first week of November, the topic is multiplication questions.
 *          This program focuses on testing the class definition of MathReport class, as the second part of Project 2.
 *          It shows FOUR questions ("hard-coded" questions) for the student to solve
 *          For each question, the program should wait for the student to enter the answer:
 *              if the answer is correct, a message of congratulations should be printed;
 *              if the answer is not correct, a sorry message should be printed (however DO NOT show the correct answer since the student can practice again).
 *          After FOUR questions are done, there are two cases:
 *              Case 1: if the student answers all questions correctly, it should generate a report which contains the following information then quit the program;
 *                         (1) the number of questions the student has solved;
 *                         (2) the list of questions the student has solved with correct answers;
 *                         (3) the number of questions the student answered correctly;
 *                         (4) the number of questions the student made mistakes;
 *                         (5) followed by "Great job!" message then directly quit the program
 *              Case 2: if the student answers at least one question wrong, it should first generate a report which contains the following information:
 *                         (1) the number of questions the student has solved;
 *                         (2) the list of questions the student has solved without answers;
 *                         (3) the number of questions the student answered correctly;
 *                         (4) the number of questions the student made mistakes;
 *                         (5) display either "Great job!"(if (2) > (3)) or "You will do better next time..." (otherwise),
 *                      then the program should provide the student at maximum THREE times to practice the wrong questions again:
 *                                                   During the practice, only if the answer is correct, the question will be removed from the practice list.
 *                                                   After THREE times, the program should generate a final report then quit the program:
 *                                                                      (1) the number of questions the student has solved;
 *                                                                      (2) the list of questions the student has solved without answers;
 *                                                                      (3) the number of questions the student answered correctly;
 *                                                                      (4) the number of questions the student made mistakes;
 *                                                                      (5) display either "Great job!"(if (2) > (3)) or "You will do better next time..." (otherwise)
 * Author: Nathan Jones
 */

#include <iostream>
#include <string>
#include "MathOperations.h"
#include "MathReport.h"

using namespace std;

int main()
{
    // define some constants for "hard-coded" questions
    const int OP1_STARTNUM = 37;
    const int NUM_QUESTIONS = 4;
    const int OP2 = 9;
    const int MAX_PRACTICE = 3;

    cout << "\tMonth-at-a-Glance (MAAG) of April" << endl;
    cout << "\tMath Is Fun! Try to solve Multiplication problems..." << endl;

    int op1;                    // The first operand
    int op2 = OP2;              // The second operand
    int studentAnswer;          // The student's answer
    MathOperations question;    // the question for user to solve
    MathReport userReport;  // The user report for using Math Tutor program

    for (op1 = OP1_STARTNUM; op1 < OP1_STARTNUM + NUM_QUESTIONS; op1++)
    {
        question.setOperands(op1, op2);
        question.Multiplication();
        // Display the question and collect the user input
        studentAnswer = question.collectUserAnswer();
        if (question.checkAnswer(studentAnswer))
            cout << "Congratulations! " << studentAnswer << " is the right answer." << endl;
        else
            cout << "Sorry, the answer is wrong. You may practice again." << endl;
        //add the current question and the user answer into the user report
        userReport.insert(question, studentAnswer);
        cout << endl << endl;
    }

    // generate the user report for using Math Tutor
    cout << endl;
    bool withAnswer = true;

    if (userReport.getNumOfWrongAnswers() != 0)
    {
        withAnswer = false;
        userReport.generateReport(withAnswer);
        string option;
        bool morePractice = true;

        // allow the user to practice at maximum 3 times of questions with wrong answer
        int i = 0;
        while (morePractice && i < MAX_PRACTICE)
        {
            morePractice = userReport.needMorePractice();
            i++;
        }

        if (morePractice && i == MAX_PRACTICE)
        {
            cout << "Sorry! You have reached the maximum of " << MAX_PRACTICE << " times of practice!" << endl << endl;
        }
        withAnswer = true;
    }

    userReport.generateReport(withAnswer);
    cout << "Thank you for using Math Tutor." << endl;
    return 0;
}