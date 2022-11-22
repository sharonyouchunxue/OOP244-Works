/*
*****************************************************************************
                        Workshop 9
Full Name  : Chunxue You(Sharon)
Student ID#: 127632214
Email      : cyou8@myseneca.ca
Section    : OOP244 NAA
Date       : 2022-11-20

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. I have done all
the coding by myself and only copied the code that my professor provided to
complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include "Text.h"
using namespace std;
namespace sdds {
    //This index operator provides read-only access to the content of the text for the derived classes of Text.
    //The behaviour of the operator is not defined if the index goes out of bounds or if the content is null.
    const char& Text::operator[](int index) const {
        return m_content[index];
    }

    //copy constructor
    Text::Text(const Text& T) {
        operator=(T);
    }

    //copy assignment operator
    Text& Text::operator=(const Text& T) {
        if (this != &T) {
                delete[] m_content;
                m_content = new char[strlen(T.m_content) + 1];
                strcpy(m_content, T.m_content);
            }
        return *this;
    }

    std::istream& Text::read(std::istream& istr){
        char content[30]{};
        istr >> content;
        delete[] m_content;
        m_content = new char[strlen(content) + 1];
        strcpy(m_content, content);
        if (m_content != nullptr) {
            istr.ignore();
        }
        return istr;
    }

    std::ostream& Text::write(std::ostream& ostr) const{
        if (m_content) {
            ostr << m_content;
        }
        return ostr;
    }

    unsigned Text::getFileLength(std::istream& is){
        unsigned len{}; 
             if (is) {
                     // save the current read position
                    std::streampos cur = is.tellg();
                    // go to the end
                    is.seekg(0, ios::end);
                   // tell what is the positions (end position = size)
                    len = unsigned(is.tellg());
                   // now go back to where you were.
                    is.seekg(cur);
              }
                return len;
    }

    //destructor
    Text::~Text(){
        delete[] m_content;
        m_content = nullptr;
    }
 
    Text::Text(const char* file) {
        delete[] m_content;
            m_content = new char[strlen(file) + 1];
            strcpy(m_content, file);
        }
    std::ostream& operator<<(std::ostream& ostr, const Text& RW){
        return RW.write(ostr);
    }
    std::istream& operator>>(std::istream& istr, Text& RW){
        return RW.read(istr);
    }
}






   


