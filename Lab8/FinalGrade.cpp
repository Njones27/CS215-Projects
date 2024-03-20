/*
 *Course: CS215-008
 *Project: Lab 8
 *Purpose: Define all constructors in FinalGrade.h
 *Author: Nathan Jones
 */

#include <iostream>
#include <iomanip>
#include "FinalGrade.h"

// default constructor
FinalGrade::FinalGrade() {
    score = 0.0;
}

// constructor: give the initial value to the private data member score
// to pass-in parameter in_score
FinalGrade::FinalGrade(double in_score) {
    if (in_score < MIN_SCORE || in_score > MAX_SCORE)
    {
        cout << "Invalid Score" << endl;
        score = 0.0;
    }
    else
    {
        setScore(in_score);
    }
}

// set the private data member: score
// to pass-in parameter in_score
void FinalGrade::setScore(double in_score) {
    score = in_score;
}

// return the value of the data member: score
double FinalGrade::getScore() const {
    return score;
}

// return the corresponding letter grade from score
// based on the grading policy in CS215 syllabus
char FinalGrade::decideLetterGrade() const {
    char letter = ' ';
    if (score <= 100 && score >= 90) {
        letter = 'A';
    }
    else if (score < 90 && score >= 80) {
        letter = 'B';
    }
    else if (score < 80 && score >= 70) {
        letter = 'C';
    }
    else if (score < 70 && score >= 60) {
        letter = 'D';
    }
    else {
        letter = 'E';
    }
    return letter;
}

// print the score and letter grade in the format: (for example)
// Score: 88.00        Letter Grade: B
void FinalGrade::print() const {
    cout << "Score: " << fixed << setprecision(2) << score << "        " << " Letter grade: " << decideLetterGrade() << endl;
}
