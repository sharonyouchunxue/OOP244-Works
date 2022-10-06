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
#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_
namespace sdds {
	int strlen(const char* str);
	// copies up to len chars from src to des
	// if len is negative, it will copy up to null char
	// resulting a cstring in des in any case
	void strcpy(char* des, const char* src, int len = -1);
	int strcmp(const char* s1, const char* s2);
}
#endif // !SDDS_UTILS_H_

