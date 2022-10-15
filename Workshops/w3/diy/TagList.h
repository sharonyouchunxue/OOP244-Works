#pragma once
/*
*****************************************************************************
                        Workshop 3 - part 2
Full Name  : Chunxue You
Student ID#: 127632214
Email      : cyou8@myseneca.ca
Section    : OOP244 NAA
Date       : 2022-09-29

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. I have done all
the coding by myself and only copied the code that my professor provided to
complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_TAGLIST_H_
#define SDDS_TAGLIST_H_
#include "NameTag.h"
namespace sdds {
    //const int MAX_NAME_NUMBER = 100;
    class TagList {
    private:
        NameTag* m_Tags;
        int m_frameSize;
        int m_size;
        int m_volum;

    public:
        
        void set(); 
        void set(int num);
        void add(const NameTag& nt);
        void print();
        void cleanup();
        
    };
   
}

#endif 

