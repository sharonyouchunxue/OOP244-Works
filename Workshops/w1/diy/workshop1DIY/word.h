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
#ifndef SDDS_WORD_H
#define SDDS_WORD_H

const int MAX_FILE_WORDS = 100;
const int MAX_WORD_DEFINITION = 8;
const int MAX_WORD_CHARACTERS = 64; //each type of word can max 64 characters
const int MAX_DEFI_CHARACTERS = 1024; // text of definition max 1024 characters


namespace sdds {
    
    struct Word {
        struct Definition Typedefinition[MAX_WORD_DEFINITION];
        char words_name[MAX_WORD_CHARACTERS + 1];
        int count;
    };

    struct Definition {
        char definition[MAX_DEFI_CHARACTERS + 1];
        char definitionType;
    };

    struct Dictionary {
        Word m_word[MAX_FILE_WORDS];
        int numOfword;

    };
}

#endif // !SDDS_WORD_H

