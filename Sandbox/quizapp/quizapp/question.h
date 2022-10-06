#pragma once
/*
*	Workshop 1 Part 2
*	File Name: question.h
*	Date: May 21st, 2022
*	Name: Sebastian Rubina
*	Student ID: 150640217
*	Seneca Email: srubina-sanchez@myseneca.ca
*	Section: NFF
*
*	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/
#ifndef QUIZZER_QUESTION_H
#define QUIZZER_QUESTION_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>


using namespace std;


namespace quizzer {

	const int MAX_QUIZZES = 5;
	const int MAX_QUESTIONS = 60;
	const int MAX_ANSWERS = 10;
	const int MAX_Q_CHARACTERS = 1024;
	const int MAX_A_CHARACTERS = 128;


	struct Answers {
		bool isCorrect;
		char answer[MAX_A_CHARACTERS + 1];
	};

	struct Question {
		char question[MAX_Q_CHARACTERS + 1];
		char typeOfQuestion;
		int userAnswer;
		struct Answers answers[MAX_ANSWERS];
	};

	struct Quiz {
		struct Question questions[MAX_QUESTIONS];
		int numOfQuestions = 0;
		int currentQuestion = 0;
		int correctAnswers = 0;
		int isStarted = 0;
	};

	extern Question questions[MAX_QUESTIONS];
	extern Quiz quizzes;


	char sortStrings(char temp[MAX_Q_CHARACTERS + 1], Quiz* quizzes, int* qCounter, int* aCounter, int* blankCounter);

	void printAnswer(int i);

	void checkAnswers();

}









#endif // question.h