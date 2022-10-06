/*
*****************************************************************************
                        Workshop 1 - part 2
Full Name  : Chunxue You
Student ID#: 127632214
Email      : cyou8@myseneca.ca
Section    : OOP244 NAA
Date       : 2022-09-12
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. I have done all
the coding by myself and only copied the code that my professor provided to
complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "word.h"

using namespace std;
namespace sdds {
    Word words[MAX_FILE_WORDS] = {};
    
    int numOfword = 0;
    void sort() {
        int i, j;
        Word temp;
        for (i = numOfword - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (strlen(words[j].words_name) > strlen(words[j].words_name)) {
                    temp = words[j];
                    words[j] = words[j + 1] = temp;
                }
            }
        }
     
    }
    /// <summary>
/// Search in the dictionary for the word and display all the definitions found.
/// 
/// Print "NOT FOUND: word [X] is not in the dictionary." if
///   the word doesn't exist in dictionary.
/// </summary>
/// <param name="word">The word to search and display.</param>


    void DisplayWord(const char* word) {
        sort();
        int i;
        for (i = 0; i < numOfword; i++) {
            cout << i + 1 << words[i].words_name << endl;
        }

    }



}



