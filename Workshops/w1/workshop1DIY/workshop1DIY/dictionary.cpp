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
#include <cstdio>
#include <cstring>
#include <cstdio>
#include "dictionary.h"
#include "word.h"
using namespace std;

namespace sdds {

    FILE* fptr;
    //Load dictionary file, return 0 if properly loaded
    int LoadDictionary(const char* filename) {
        char str[MAX_FILE_WORDS];
        fptr = fopen(filename, "r");
        if (fptr == NULL) {
            return 1;
        }
        
            while (fgets(str, sizeof(str), fptr) != NULL) {
                fputs(str, stdout);
            }
        fclose(fptr);
        return 0;
    }
    /// <summary>
/// Save all the words existing in the dictionary into a file.  The functions
///   "LoadDictionary" should be able to load from this after the save finished.
/// </summary>
/// <param name="filename">The name of the file where to save.</param>
    void SaveDictionary(const char* filename) {

    }

    /// <summary>
/// Adds a word to the dictionary.
/// 
/// If the dictionary already contains the word, add a new definition for it.
/// </summary>
/// <param name="word">The word to add to the dictionary.</param>
/// <param name="type">The type of the word (noun, verb, adjective, etc.)</param>
/// <param name="definition">The definition for the word.</param>
    void AddWord(const char* word, const char* type, const char* definition) {

    }

    /// <summary>
/// Searches in the dictionary for a word and update its definition and type.
///   If the word contains multiple definitions, print the message
///   "The word [X] has multiple definitions:" followed by a list of existing
///   definitions, and asks user which one to update.  This function assumes that
///   the user's input is correct and doesn't require validation.
/// 
/// If the word is not in the dictionary, this function does nothing.
/// </summary>
/// <param name="word">The word to update.</param>
/// <param name="type">The new type of the definition.</param>
/// <param name="definition">The new definition.</param>
/// <returns></returns>
    int UpdateDefinition(const char* word, const char* type, const char* definition) {

        return 0;
    }

}