/*
*****************************************************************************
                        Workshop 10
Full Name  : Chunxue You(Sharon)
Student ID#: 127632214
Email      : cyou8@myseneca.ca
Section    : OOP244 NAA
Date       : 2022-11-28
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. I have done all
the coding by myself and only copied the code that my professor provided to
complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_SEARCH_H_
#define SDDS_SEARCH_H_
#include <iostream>
#include "Collection.h"
namespace sdds {
    //Template type requirements
    //search function with four arguments
    //1.add the template type for an array of object, and also because collection 
    //  is a template class, so we can use same type name for array and collection
    //2. Add a different type name for the key value
    //3. in this template, a "==" operator must be defined in order to compare each class if it matches,
    //   if it matches, then call the add function in the collection class to add the data in.

    template <typename T1, typename T2>
    bool search(Collection<T1>& object, const T1* array, int num, T2 key) {
        bool found = false;
        for (int i = 0; i < num; i++) {
            if (array[i] == key) { //call "==" operator
                object.add(array[i]); //call the template function "add" in the collection template class
                found = true;
            }
        }
        return found;
    }

}
#endif 