/*
*	Workshop 1 Part 2
*	File Name: quiz.cpp
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

	FILE* file = nullptr;

	// Loads Quiz File, returns 0 if properly loaded.
	int LoadQuiz(const char* filename) {

		int fileLoaded = -1;
		int qCounter = 0;
		int aCounter = 0;
		int blankCounter = 0;
		int clearQuestions = 0;
		char result = ' ';
		int tempValue;
		quizzes.numOfQuestions = 0;
		for (clearQuestions = 0; clearQuestions < MAX_QUESTIONS; clearQuestions++) quizzes.questions[clearQuestions] = { 0 };



		file = fopen(filename, "r");

		if (file) {
			fileLoaded = 0;
			char temp[MAX_Q_CHARACTERS + 1];
			do {
				tempValue = fscanf(file, "%[^\n]", temp);
				if (fgetc(file) == '\n') blankCounter++;

				if (blankCounter != 2) {
					result = sortStrings(temp, &quizzes, &qCounter, &aCounter, &blankCounter);
				}

				if (result == 'a') aCounter++;
				//if (result == 'b') blankCounter++; ////// NO LONGER NEEDED?

				if (blankCounter == 2) {
					blankCounter = 0;
					qCounter++;
					aCounter = 0;
				}
			} while (feof(file) == 0);

		}
		else {
			// cout << "File Failed to Load" << endl;
		}

		return fileLoaded;
	}



	int IsQuizValid() {

		int i;
		int j;
		int isValid = 1;
		int numberOfAnswers = 0;

		if (quizzes.numOfQuestions >= 5) {
			for (i = 0; i < quizzes.numOfQuestions; i++) {

				for (j = 0; j < MAX_ANSWERS; j++) {
					if (quizzes.questions[i].answers[j].answer[1] == 'X') {
						numberOfAnswers++;
					}
				}

				if (quizzes.questions[i].typeOfQuestion == 'c') {
					if (numberOfAnswers == 1) {
						cout << "QUESTION " << i + 1 << " -> OK" << endl;
					}
					else {
						cout << "QUESTION " << i + 1 << " -> ERROR" << endl;
						isValid = 0;
					}
				}
				else {
					cout << "QUESTION " << i + 1 << " -> OK" << endl;
				}
				numberOfAnswers = 0;
			}
		}

		return ((quizzes.numOfQuestions >= 5) ? 1 : 0) && isValid;
	}

	int HasMoreQuestions() {

		return quizzes.currentQuestion < quizzes.numOfQuestions;
	}
	void ShowNextQuestion() {

		int i = 0;

		quizzes.isStarted = 1;
		cout << quizzes.questions[quizzes.currentQuestion].question << endl;

		printAnswer(i);

		cout << "Your answer? ";
		cin >> quizzes.questions[quizzes.currentQuestion].userAnswer;

		checkAnswers();

		quizzes.currentQuestion += 1;
	}
	void ShowQuizResults() {


		if (quizzes.isStarted != 0) {
			int i = 0;

			cout << endl << "QUIZ RESULTS : your score is " << quizzes.correctAnswers << "/" << quizzes.numOfQuestions << endl;

			quizzes.currentQuestion = 0;
			quizzes.correctAnswers = 0;
			for (i = 0; i < MAX_QUESTIONS; i++) quizzes.questions[i] = { 0 };
			quizzes.isStarted = 0;
		}
	}
}
