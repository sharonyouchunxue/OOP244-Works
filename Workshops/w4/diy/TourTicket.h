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

#ifndef SDDS_TOURTICKET_H_
#define SDDS_TOURTICKET_H_


namespace sdds {
    class TourTicket {
        char m_name[41]; // passenger name
        int m_ticketNumber;
        void copyName(const char* str);
    public:
        TourTicket();
        TourTicket& issue(const char* passengerName);
        std::ostream& display(std::ostream& coutRef = std::cout)const;
        bool valid()const;
    };


}
#endif 