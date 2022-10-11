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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "TourBus.h"
#include "TourTicket.h"
using namespace std;

namespace sdds {

    //1.check if the current tour bus is valid or not
    bool TourBus::validTour() const
    {
        bool res = false;
        if (m_num == 4 || m_num == 16 || m_num == 22) {
            res = true;
        }
        return res;
    }

    /*2.A TourBus should be created using the number of passengers it can carry.
    first constructor that receive the number of passengers, if the number is invalid,
    don't created, it becomes invalid*/
    TourBus::TourBus(int num) {
        m_tickets = nullptr;
        m_num = num;
    }

    TourBus::~TourBus()
    {
        delete[] m_tickets;
        m_tickets = nullptr;
    }

    TourBus& TourBus::board()
    {
        //check if valid ticket
        //check the number of issued ticket, number of ticket == number of passenger
        //display the boarding information list
        //return TourBus object;
        char tempName[41]{};
        m_tickets = new TourTicket[m_num];
        cout << "Boarding " << m_num << " Passengers:" << endl;
        for (int i = 0; i < m_num; i++) {
            if (!m_tickets[i].valid()) {
                cout << i + 1 << "/" << m_num << "- Passenger Name: ";
                cin.getline(tempName, 41, '\n');
                if (!cin.fail()) {
                    m_tickets[i].issue(tempName);
                }
            }
        }
        return *this;
    }
     void TourBus::startTheTour()const
    {
        int i = 0;
        if (m_tickets != nullptr)
        {
            cout << "Starting the tour...." << endl;
            cout << "Passenger List:" << endl;
            cout << "|Row | Passenger Name                           | Num |" << endl;
            cout << "+----+------------------------------------------+-----+" << endl;
            //cout << endl;
            for (i = 0; i < m_num; i++)
            {
                cout << "| ";
                cout.width(2);
                cout.fill(' ');
                cout.setf(ios::right);
                cout << i + 1;
                cout.unsetf(ios::right);
                cout << " ";
                m_tickets[i].display();
                cout << endl;
            }
            cout << "+----+------------------------------------------+-----+" << endl;
        }
        else
        {
            cout << "Cannot start the tour, the bus is not fully boarded!" << endl;
        }
    }

}