/*
*****************************************************************************
                        Workshop 8 - part 1
Full Name  : Chunxue You(Sharon)
Student ID#: 127632214
Email      : cyou8@myseneca.ca
Section    : OOP244 NAA
Date       : 2022-11-15
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. I have done all
the coding by myself and only copied the code that my professor provided to
complete my workshops and assignments.
*****************************************************************************
*/
#include <iostream>
#include <fstream>
#include "Shape.h"
#include "Rectangle.h"
#include "Line.h"
using namespace sdds;
using namespace std;
int main() {
    Line BadOne;
    Rectangle BadRectangle("Bad one", 1, 1);
    Line* L = new Line("Separator", 50);
    Rectangle* R = new Rectangle("Container", 30, 5);
    Shape* S[2] = { L, R };
    cout << "Nothing should be printed between these two lines" << endl;
    cout << "------------------------------------" << endl;
    cout << BadOne << BadRectangle;
    cout << "------------------------------------" << endl;
    cout << *L << endl;
    cout << *R << endl;
    cout << "Enter the following:\n>Line two,40<ETNER>\n>";
    cin >> *L;
    cout << "The following outputs should be the same" << endl;
    cout << "The correct output:" << endl;
    cout << "Line two================================" << endl;
    cout << "Your output:" << endl;
    cout << *L << endl;
    cout << "Enter the following:\n>A 50 by 4 frame to be printed on screen,50,4<ETNER>\n>";
    cin >> *R;
    cout << "The following outputs should be the same" << endl;
    cout << "The correct output:" << endl;
    cout << "+------------------------------------------------+\n"
        "| A 50 by 4 frame to be printed on screen        |\n"
        "|                                                |\n"
        "+------------------------------------------------+" << endl;
    cout << "Your output:" << endl;
    cout << *R << endl;
    cout << "printing Line and Rectangle using Shape pointers: " << endl;
    cout << *S[0] << endl << *S[1] << endl;
    delete S[0];
    delete S[1];
    cout << "Reading the data from a file" << endl;
    ifstream file("ws8data.csv");
    Shape* sptr;
    char type;
    while (file) {
        sptr = nullptr;
        type = 'x';
        file.get(type);
        file.ignore();
        if (type == 'L') {
            sptr = new Line;
        }
        else if (type == 'R') {
            sptr = new Rectangle;
        }
        if (sptr) {
            file >> *sptr;
            cout << *sptr << endl;
            delete sptr;
        }
    }
    return 0;
}