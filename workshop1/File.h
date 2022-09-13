/*
*****************************************************************************
                        Workshop 1 - part 1
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
#ifndef SDDS_FILE_H // replace with relevant names
#define SDDS_FILE_H
#include "ShoppingRec.h"


namespace sdds {

    bool openFileForRead();

    bool openFileForOverwrite();
    void closeFile();

    bool freadShoppingRec(ShoppingRec* rec);

    void fwriteShoppintRec(const ShoppingRec* rec);


}
#endif


