/*
 *Course: CS215-004
 *Project: Lab 9
 *Purpose: Define all constructors in MathOperations.h
 *Author: Nathan Jones
 */

#include "MathReport.h"
#include "MathOperations.h"
#include <iomanip>
#include <list>

// default constructor
MathReport::MathReport() {
    numCorrectAnswers = 0;  // number of correctly answered questions
    numWrongAnswers = 0;  // number of wrong answers
    mathQuestions = {}; // sequence of questions
    errorList = {};  // sequence of questions with wrong answers in first try, need to practice more
}

// add a newQuestion into the vector of mathQuestions
// and the response to check with the correct answer:
//    if response is correct, increase numCorrectAnswers
//    otherwise, increase numWrongAnswers and also insert newQuestion to errorList
void MathReport::insert(MathOperations newQuestion, int response) {
    mathQuestions.push_back(newQuestion);

    // Checks if question is answered correctly
    if (response == newQuestion.getAnswer()) {
        numCorrectAnswers++;
    }
    else {
        numWrongAnswers++;
        errorList.push_back(newQuestion);
    }
}

// return the value of numCorrectAnswers
int MathReport::getNumOfCorrectAnswers() const {
    return numCorrectAnswers;
}

// return the value of numWrongAnswers
int MathReport::getNumOfWrongAnswers() const {
    return numWrongAnswers;
}

// generate a brief report
// if showAnswer is true, display questions solved with correct answers
// otherwise, display questions solved without answers
void MathReport::generateReport(bool showAnswer) const {
    cout << endl << "You have solved the following " << mathQuestions.size() << " math problem(s):" << endl << endl;
    if (showAnswer) {
        for (int i = 0; i < mathQuestions.size(); i++) {
            cout << "Question : " << to_string(i + 1) << endl;
            mathQuestions[i].print(); // Prints question
            cout << setw(5) << mathQuestions[i].getAnswer() << endl;
        }
    }
    else {
        for (int i = 0; i < mathQuestions.size(); i++) {
            cout << "Question : " << to_string(i + 1) << endl;
            mathQuestions[i].print(); // Prints question
            cout << endl;
        }
    }
    cout << "----------------------------------" << endl;
    cout << "You answered " << numCorrectAnswers << " questions correctly." << endl;
    cout << "You made " << numWrongAnswers << " mistakes." << endl;
    if (getNumOfCorrectAnswers() <= getNumOfWrongAnswers()) {
        cout << "You will do better next time..." << endl;
    }
    else {
        cout << "Great job!" << endl;
    }
}


// display the questions in errorList for practice again and collect the user answer
// then check if the answer is correct so that it can be removed from the errorList
// it returns false if all questions in errorList have been corrected and removed from the errorList
// otherwise returns true: errorList is not empty yet, need more practice
bool MathReport::needMorePractice() {
    int listSize = errorList.size();
    for (int i = 0; i < listSize; i++) {
        int answer = errorList.front().collectUserAnswer();
        if (answer == errorList.front().getAnswer()) {
            errorList.pop_front();
            numCorrectAnswers++;
            numWrongAnswers--;
            cout << "Congratulations! " << answer << " is the right answer." << endl;
        }
        else {
            errorList.push_back(errorList.front());
            errorList.pop_front();
            cout << "Sorry, answer is wrong. You may practice again." << endl;
        }
        if (errorList.empty()) {
            cout << "Excellent! Your answers are all correct! No more practice is needed:)" << endl;
            return false;
        }
    }
    cout << "You still need more practice!" << endl;
    return true;
}

/*
// Using linked lists
bool MathReport::needMorePractice() {
    list<MathOperations>::iterator it = errorList.begin();
    while(it != errorList.end()) {
        int answer = it->collectUserAnswer();
        // int answer = (*it).collectUserAnswer();
        if (it->checkAnswer(answer)) { // the user answer the question correctly
            // remove the current node; increase numCorrectAnswers; decrease numWrongAnswers
            it = errorList.erase(it);
            numCorrectAnswers++;
            numWrongAnswers--;
        }
        else { // the user answers the question wrong
            it++;
        }
    }
    // decide the return value
    if (errorList.empty()) {
        cout << "?????" << endl;
        return false;
    }
    else {
        cout << "   " << endl;
        return true;
    }
}*/
