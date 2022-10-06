/*
*	Workshop 1 Part 2
*	File Name: question.cpp
*	Date: May 21st, 2022
*	Name: Sebastian Rubina
*	Student ID: 150640217
*	Seneca Email: srubina-sanchez@myseneca.ca
*	Section: NFF
*
*	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/
#define _CRT_SECURE_NO_WARNINGS
#include "question.h"


namespace quizzer {

	Question questions[MAX_QUESTIONS] = { 0 };
	Quiz quizzes;

	char sortStrings(char temp[MAX_Q_CHARACTERS + 1], Quiz* quizzes, int* qCounter, int* aCounter, int* blankCounter) {


		int i = *qCounter;
		int j = *aCounter;
		char result = ' ';

		if (temp[0] == '{' && temp[2] == 'a') {
			strcpy(quizzes->questions[i].question, temp);
			quizzes->questions[i].typeOfQuestion = 'a';
			strcpy(temp, " ");
			j = 0;
			result = 'q';
			quizzes->numOfQuestions += 1;
			*blankCounter = 0;
		}
		else if (temp[0] == '{' && temp[2] == 'c') {
			strcpy(quizzes->questions[i].question, temp);
			quizzes->questions[i].typeOfQuestion = 'c';
			strcpy(temp, " ");
			j = 0;
			result = 'q';
			quizzes->numOfQuestions += 1;
			*blankCounter = 0;
		}
		else if (temp[0] == '[') {
			strcpy(quizzes->questions[i].answers[j].answer, temp);
			if (quizzes->questions[i].answers[j].answer[1] == 'X') quizzes->questions[i].answers[j].isCorrect = 1;
			strcpy(temp, " ");
			result = 'a';
			*blankCounter = 0;
		}
		/* else {
			result = 'b';
		} NO LONGER NEEDED? */


		*aCounter = j;

		return result;
	}

	void printAnswer(int i) {
		for (i = 0; i < MAX_ANSWERS; i++) {
			if (quizzes.questions[quizzes.currentQuestion].answers[i].answer[0] == '[') {
				cout << i + 1 << "." << quizzes.questions[quizzes.currentQuestion].answers[i].answer + 3 << endl;
			}
		}
	}

	void checkAnswers() {

		/*
		* //////////// OLD SOLUTION, MADE A MUCH SIMPLER ONE DOWN BELOW
		int i;
		int foundCorrectAnswer = 0;
		int correctAnswer = -1;
		for (i = 0; i < MAX_ANSWERS; i++) {

			if (quizzes.questions[quizzes.currentQuestion].answers[i].answer[1] == 'X' && !foundCorrectAnswer) {
				correctAnswer = i + 1;
				foundCorrectAnswer = 1;
			}

		}

		if (quizzes.questions[quizzes.currentQuestion].userAnswer == correctAnswer) {
			quizzes.correctAnswers++;
		}
		*/

		if (quizzes.questions[quizzes.currentQuestion].answers[quizzes.questions[quizzes.currentQuestion].userAnswer - 1].isCorrect) {
			quizzes.correctAnswers++;
		}

	}
}