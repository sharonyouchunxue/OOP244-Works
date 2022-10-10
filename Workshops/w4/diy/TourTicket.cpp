/*
*****************************************************************************
                        Workshop 4 - part 2
Full Name  : Chunxue You(Sharon)
Student ID#: 127632214
Email      : cyou8@myseneca.ca
Section    : OOP244 NAA
Date       : 2022-10-07

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. I have done all
the coding by myself and only copied the code that my professor provided to
complete my workshops and assignments.
*****************************************************************************
*/
#include <iostream>
#include "TourTicket.h"
using namespace std;
namespace sdds {
    int next_ticketNumber = 100;
    void TourTicket::copyName(const char* str) {
        int i = 0;
        for (i = 0; i < 40 && str[i]; m_name[i] = str[i], i++);
        m_name[i] = 0;
    }
    TourTicket::TourTicket() {
        m_name[0] = char(0);
        m_ticketNumber = -1;
    }
    TourTicket& TourTicket::issue(const char* passengerName) {
        if (passengerName && passengerName[0]) {
            copyName(passengerName);
            m_ticketNumber = next_ticketNumber++;
        }
        return *this;
    }
    std::ostream& TourTicket::display(std::ostream& coutRef) const {
        if (valid()) {
            cout << "| ";
            coutRef.width(40);
            coutRef.setf(ios::left);
            coutRef << m_name << " | " << m_ticketNumber << " |";
            coutRef.unsetf(ios::left);
        }
        else {
            coutRef << "Invalid TourTicket information" << endl;
        }
        return coutRef;
    }
    bool TourTicket::valid() const {
        return bool(m_name[0]);
    }
}
