#pragma once
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
#ifndef SDDS_TOURBUS_H_
#define SDDS_TOURBUS_H_
#include "TourTicket.h"
namespace sdds {

    class TourBus {
    private:
        TourTicket* m_tickets{};//tourPassenger dynamic arrray
        int m_num;//three size(4 passenger, 16 pasenger, 22 passenger)

    public:
         TourBus(int num);
         ~TourBus();
         bool validTour()const;
         TourBus& board();//read
         void startTheTour()const;//display
        
    };
}

#endif 