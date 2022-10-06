/*
*****************************************************************************
                        Workshop 3 - part 2
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
#include <cstdio>
#include "TagList.h"
#include "NameTag.h"
using namespace sdds;
int noOfNames(FILE* fptr) {
    char ch;
    int recs = 0;
    rewind(fptr);
    while (fscanf(fptr, "%c", &ch) == 1) {
        recs += (ch == '\n');
    }
    rewind(fptr);
    return recs;
}
int main() {
    char name[51]{};
    FILE* fptr = fopen("simpsons.txt", "r");
    NameTag nt;
    TagList tl;
    tl.set();
    tl.set(noOfNames(fptr));
    while (fscanf(fptr, "%[^\n]\n", name) == 1) {
        nt.set(name);
        tl.add(nt);
    }
    tl.print();
    tl.cleanup();
    fclose(fptr);
    return 0;
}