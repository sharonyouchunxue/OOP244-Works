#pragma once
/*
*	Workshop 1 Part 2
*	File Name: quiz.h
*	Date: May 21st, 2022
*	Name: Sebastian Rubina
*	Student ID: 150640217
*	Seneca Email: srubina-sanchez@myseneca.ca
*	Section: NFF
*
*	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/
#ifndef QUIZZER_QUIZ_H
#define QUIZZER_QUIZ_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

namespace quizzer {

	int LoadQuiz(const char* filename);
	int IsQuizValid();
	int HasMoreQuestions();
	void ShowNextQuestion();
	void ShowQuizResults();

}


#endif // quiz.h
