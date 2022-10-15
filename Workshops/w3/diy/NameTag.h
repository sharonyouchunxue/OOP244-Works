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

#ifndef SDDS_NAMETAG_H_
#define SDDS_NAMETAG_H_
#include<cstring>
namespace sdds {
    int const MAX_NAME_LEN = 50;

  class NameTag {
    private:
        char m_name[MAX_NAME_LEN + 1];
    public:
        void set(const char* name); 
        char* getName();    
    };
}

#endif 
