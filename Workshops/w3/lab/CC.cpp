/*
*****************************************************************************
                        Workshop 3 - part 1
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
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <cstdio>
#include <iostream>
#include "CC.h"
//#include "Utils.h"

using namespace std;

namespace sdds {
    //validates the credit card information,it will return true if all the conditions are met,
    //otherwise it will return false
    bool CC::validate(const char* name,
        unsigned long long cardNo,
        short cvv,
        short expMon,
        short expYear) const
    {
        if (name != nullptr && name[0] != '\0' && (strlen(name) > 2))
        {
            if ((4000000000000000 <= cardNo) && (cardNo <= 4099999999999999))
            {
                if ((100 <= cvv) && (cvv <= 999))
                {
                    if ((1 <= expMon) && (expMon <= 12))
                    {
                        if ((22 <= expYear) && (expYear <= 32))
                        {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }

    //This function prints a 16-digit number in a set of 4-digit numbers separated by spaces
    void CC::prnNumber()const { //please note this function I borrowed from classmate in different class,mine code was not working properly see below

        int i = 0;
        unsigned long long division[4], division1, division2, divison3;
        division1 = 1000000000000;
        division2 = 100000000;
        divison3 = 10000;
        division[0] = (m_cardNo - (m_cardNo % division1)) / division1;
        division[1] = (m_cardNo - (division[0] * division1) - (m_cardNo % division2)) / division2;
        division[2] = (m_cardNo - (division[0] * division1) - (division[1] * division2) - (m_cardNo % divison3)) / divison3;
        division[3] = m_cardNo - (division[0] * division1) - (division[1] * division2) - (division[2] * divison3);

        /*int Number;
        unsigned long long division1, division2, division3;
        division1 = 1000000000000;
        division2 = 100000000;
        division3 = 10000;
        Number = m_cardNo / division1;
        cout << Number << " ";
        int remainder = m_cardNo % division1;
        Number = remainder / division2;
        cout << Number << " ";
        int remainder2 = m_cardNo % division2;
        Number = remainder2 / division3;
        cout << Number << " ";
        int remainder3 = m_cardNo % division3;
        cout << remainder3;*/

        for (i = 0; i < 4; i++)
        {
            if (i == 3)
            {
                cout.width(4);
                cout.fill('0');
                cout.setf(ios::right);
                cout << division[i];
                cout.unsetf(ios::right);
            }
            else
            {
                cout.width(4);
                cout.fill('0');
                cout.setf(ios::right);
                cout << division[i];
                cout.unsetf(ios::right);//print first 4 digit number
                cout << " ";

            }
            cout.fill(' ');
        }

    }

    //Sets the object to a safe empty state by setting all the values to zero and nullptr.
    void CC::set() {
        m_name = nullptr;
        m_cardNo = 0;
        m_cvv = 0;
        m_expMon = 0;
        m_expYear = 0;
    }
    //First, it will deallocate the cardholder's name and then calls the set() to set the 
    //object to a safe empty state.
    void CC::cleanUp() {
        delete[] m_name;
        m_name = nullptr;
        CC::set();
    }

    //Returns if the CC object is in a safe empty state or not; by returning true if the 
    //cardholder name pointer attribute of the object is nullptr, otherwise, it will return false.
    bool CC::isEmpty() const {
        if (m_name == nullptr) {
            return true;
        }
        return false;
    }

    //First, it will cleanUp() the object. Then if all the arguments are valid using validate(),
    //it will dynamically keep a copy of the name in the name attribute and set the rest of the
    //attributes to their corresponding values.
    //If any of the arguments are invalid, nothing will be set.
    void CC::set(const char* cc_name,
        unsigned long long cc_no,
        short cvv,
        short expMon,
        short expYear) {
        cleanUp();
        if (validate(cc_name, cc_no, cvv, expMon, expYear)) {
            m_name = new char[MAX_NAME_LEN + 1];
            strcpy(m_name, cc_name);
            m_cardNo = cc_no;
            m_cvv = cvv;
            m_expMon = expMon;
            m_expYear = expYear;
        }
    }

    bool CC::read() {
        char tempName[71];
        unsigned long long tempCarNo = 0;
        short tempCvv = 0;
        short tempExpMon = 0;
        short tempExpYear = 0;
        cleanUp();
        cout << "Card holder name: ";
        cin >> tempName;
        cin.getline(tempName, 71);
        if (!cin.fail()) cout << "Credit card number: ";
        cin >> tempCarNo;
        if (!cin.fail()) cout << "Card Verification Value (CVV): ";
        cin >> tempCvv;
        if (!cin.fail()) cout << "Expiry month and year (MM/YY): ";
        cin >> tempExpMon;
        cin.ignore(1);
        cin >> tempExpYear;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            
        }
        else {
            set(tempName,
                tempCarNo,
                tempCvv,
                tempExpMon,
                tempExpYear);
            return false;
        }
        return false;
    }

    void CC::display(int row)const {
        if (CC::isEmpty())
        {
            cout << "Invalid Credit Card Record" << endl;
        }
        else {
            if (row > 0) {
                cout << "| ";
                cout.width(3);
                cout.fill(' ');
                cout.setf(ios::right);
                cout << row;
                cout.unsetf(ios::right);
                cout << " | ";
                cout.setf(ios::left);
                if (strlen(m_name) < 30) {
                    cout.width(30);
                    cout << m_name;
                }
                else {
                    for (int i = 0; i < 30; i++) {
                        cout << m_name[i];
                    }
                }
                cout.unsetf(ios::right);
                cout << " | ";
                prnNumber();
                cout << " | " << m_cvv << " | ";
                cout.width(2);
                cout.setf(ios::right);
                cout << m_expMon;
                cout.unsetf(ios::right);
                cout << "/" << m_expYear << " |" << endl;

            }
            else {
                cout << "Name: " << m_name << endl;
                cout << "Creditcard No: ";
                prnNumber();
                cout << endl;
                cout << "Card Verification Value: " << m_cvv << endl;
                cout << "Expiry Date: " << m_expMon << "/" << m_expYear << endl;
            }
        }

    }
}









