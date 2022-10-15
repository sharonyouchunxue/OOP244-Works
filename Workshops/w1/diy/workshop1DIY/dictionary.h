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
#pragma once
#ifndef SDDS_DICTIONARY_H
#define SDDS_DICTIONARY_H
#include "word.h"


namespace sdds {

  
    int LoadDictionary(const char* filename);
    void SaveDictionary(const char* filename);
    void DisplayWord(const char* word);
    void AddWord(const char* word, const char* type, const char* definition);
    int UpdateDefinition(const char* word, const char* type, const char* definition);

}
#endif  //!SDDS_DICTIONARY_H