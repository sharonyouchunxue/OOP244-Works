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
#include "TourBus.h"
using namespace std;
using namespace sdds;
void depart(const TourBus& T) {
    if (T.validTour())
        T.startTheTour();
}
int main() {
    TourBus* t;
    bool done = false;
    int num;
    cout << "Enter the following data:" << endl
        << "100<ENTER>" << endl
        << "10<ENTER>" << endl
        << "22<ENTER>" << endl
        << "16<ENTER>" << endl
        << "4<ENTER>" << endl
        << "John Doe<ENTER>" << endl
        << "Jane Doe<ENTER>" << endl
        << "Jack Doe<ENTER>" << endl
        << "Jill Doe<ENTER>" << endl
        << "-------------------" << endl;
    while (!done) {
        cout << "Please enter number of passengers: ";
        cin >> num;
        cin.ignore(1000, '\n');
        t = new TourBus(num);
        if (t->validTour()) {
            if (num == 4) {
                depart(t->board());
                done = true;
            }
            else {
                depart(*t);
            }
        }
        else {
            cout << "Invalid tour bus!" << endl;
        }
        delete t;
    }
    return 0;
}