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
#ifndef SDDS_SHOPPINGREC_H // replace with relevant names
#define SDDS_SHOPPINGREC_H

const int  MAX_TITLE_LENGTH = 50;
const int MAX_QUANTITY_VALUE = 50;


struct ShoppingRec {
    char m_title[MAX_TITLE_LENGTH + 1];
    int m_quantity;
    bool m_bought;
};

namespace sdds {

    ShoppingRec getShoppingRec();

    void displayShoppingRec(const ShoppingRec* shp);

    void toggleBoughtFlag(ShoppingRec* rec);

    bool isShoppingRecEmpty(const ShoppingRec* shp);


}
#endif

#pragma once
