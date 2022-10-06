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

#ifndef SDDS_CC_H_
#define SDDS_CC_H_

namespace sdds {

    int const MAX_NAME_LEN = 70;

    class CC
    {
        
    private:
        //data members
        char* m_name;
        unsigned long long m_cardNo;
        short m_cvv;
        short m_expMon;
        short m_expYear;
        bool validate(const char* name,
            unsigned long long cardNo,
            short cvv,
            short expMon,
            short expYear) const;
        void prnNumber()const;
    public:
        void set();
        void cleanUp();
        bool isEmpty() const;
        void set(const char* cc_name,
            unsigned long long cc_no,
            short cvv,
            short expMon,
            short expYear);
        bool read();
        void display(int row = 0) const;
    };
}
#endif 