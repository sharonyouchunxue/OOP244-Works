/*
*****************************************************************************
                        Milestone 5
Full Name  : Chunxue You(Sharon)
Student ID#: 127632214
Email      : cyou8@myseneca.ca
Section    : OOP244 NAA
Date       : 2022-11-27

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. I have done all
the coding by myself and only copied the code that my professor provided to
complete my workshops and assignments.
*****************************************************************************
*/
#include <iostream>
#include "ReadWritable.h"
using namespace std;
namespace sdds {

    //no argument constructor that sets the  Comma Separated Values flag to false.
    ReadWritable::ReadWritable() {
        flag = false;
    }

    //empty destructor
    ReadWritable::~ReadWritable() {
    }
    //returns the Comma Separated Values flag
    bool ReadWritable::isCsv() const {
        return flag;
    }
    //set the Comma Separated Values flag to the incoming bool value.
    void ReadWritable::setCsv(bool value) {
        flag = value;
    }
    //helper function to overload insertion operator to insert a ReadWritable into a stream
    //this operator call write member function  in the class ReadWritable
    std::ostream& operator<<(std::ostream& ostr, const ReadWritable& RW) {
        return RW.write(ostr);
    }

    //helper function to overload extraction operator to insert a ReadWritable into a stream
   //this operator call write member function  in the class ReadWritable
    std::istream& operator>>(std::istream& istr, ReadWritable& RW) {
        return RW.read(istr);
    }

}