/*
*****************************************************************************
						Workshop 4 - part 1
Full Name  : Chunxue You(Sharon)
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
#include <iostream>
#include <cstring>
#include "Seat.h"
using namespace std;
namespace sdds {
	/*
	 valid row numbers: 1 to 4; Business class, 7 to 15; Economy plus and 20 to 38; Economy
	 Valid letters: 1 to 4, ABEF, 7 to 38, ABCDEF
	 Code a private method to return true if the row number and the seating letter, together
	 correctly address a seat in the airplane. Validations:
	 row numbers 1 to 4, 7 to 15 and 20 to 38 are considered valid seat values.
	 for rows 1 to 4, letters A, B, E and F are acceptable values.
	 for the rest, the acceptable values are A, B, C, D, E and F.
	 If the row number and letter fall into the above pattern return true, otherwise, return false.
	This method is a query, hence it does not modify the current object.
		*/
	bool Seat::validate(int row, char letter)const {
		bool res = false;
		if (row >= 1 && row <= 4)
		{
			if (letter == 'A' || letter == 'B' || letter == 'E' || letter == 'F')
			{
				res = true;
			}
		}
		else if ((row <= 15 && row >= 7) || (row <= 38 && row >= 20)) {
			if (letter == 'A' || letter == 'B' || letter == 'C' || letter == 'D' || letter == 'E' || letter == 'F')
			{
				res = true;
			}
		}
		return res;
		
	}

	/*Since on many occasions you need to allocate memory for passenger name and copy the value
	into the allocated memory, it is better to create a private method to modularize this action.
	before validating the str argument to be a valid Cstring set the passenger name pointer attribute
	to nullptr so the passenger name pointer will be set to nullptr if allocation fails.
	then validate the str argument. If it is not null and not empty, then allocate memory to the
	length of the str argument (plus one for null) and keep the address in the passenger pointer
	attribute.
	copy the content of the str Cstring into the newly allocated memory.
	return the reference of the current object in case it is needed in the caller function.
	*/
	Seat& Seat::alAndCp(const char* str) {
		m_passengerName = nullptr;
		if (str != nullptr && str[0] != '\0') {
			this->m_passengerName = new char[strlen(str) + 1];
			strcpy(this->m_passengerName, str);
		}
		return *this;
	}

	/*This function resets the object into a safe empty state as follows:
	deallocates the passenger name
	sets passenger name to nullptr
	sets row and letter to zero
Then it will return the reference of the current object for possible future use.*/
	Seat& Seat::reset() {
		delete[] m_passengerName;
		m_passengerName = nullptr;
		m_seatRow = 0;
		m_letterSeat = 0;
		return *this;
	}

	/*This query returns if the object is in an empty state by returning true if the passenger
	name pointer attribute is nullptr and false otherwise.*/
	//bool Seat::isEmpty() const {
	//	bool ret = false;
	//	if (m_passengerName == nullptr) {
	//		ret = true;
	//	}
	//	return ret;
	//}
	bool Seat::isEmpty() const { //in c++ way to code not like ipc144
		return m_passengerName == nullptr;// declare return is equal to false, if m_passengerName is equal to nullptr return true, otherwise return false
	}
	/*This query returns true if the seats are assigned and valid by returning the validate method
	call result.
	Note: To see if the seat is assigned or not, we need to get row and letter that we are keeping
	inside of the class and validated if the validation returns true which means the seat is assigned, otherwise
	seat is not assigned
	*/
	bool Seat::assigned() const {
		bool res = false;
		if (validate(m_seatRow, m_letterSeat)) {//logic here used to be(!) not validate,result = true,so it didn't work
			res = true;
		}
		return res;
	}
	Seat::Seat() {
		reset();
	}

	/*If passengerName argument is a valid and non-empty Cstring, this constructor will allocate
	memory for passenger name in the passenger name pointer attribute and then copies the content
	of the passenger name argument into the newly allocated memory. See alAndCp() function!
	Then sets the seat row and letter to zero.*/
	Seat::Seat(const char* passengerName) {
		reset();
		if (passengerName && passengerName[0]) {
			this->m_passengerName = new char[strlen(passengerName) + 1];
			strcpy(this->m_passengerName, passengerName);
		}
		/*m_seatRow = 0;// if we already called reset, then no need to set seatRow and letterSeat to zero again
		m_letterSeat = 0;*/
	}

	/*Works exactly like the one argument constructor but instead of setting row and letter
	to zero, it will set them to the corresponding values after validating them. If values are not
	valid, it will set ONLY the row and letter to zero. see the set() method!*/
	Seat::Seat(const char* passengerName, int row, char letter) {
		reset();
		if (passengerName && passengerName[0]) {
			this->m_passengerName = new char[strlen(passengerName) + 1];
			strcpy(this->m_passengerName, passengerName);
			// validdate row and seat please(fardad)
			if (validate(row, letter)) {
				m_seatRow = row;
				m_letterSeat = letter;
			}
		}
	}

	/*Deallocates the memory pointed by the passenger name pointer attribute.*/
	Seat::~Seat() {
		delete[] m_passengerName;
		m_passengerName = nullptr;
	}

	/*The set function will validate the row and letter, if they are valid the corresponding
	attributes will be set to these argument values. If not, the attributes will be set to zero.
	At the end set will return the address of the current object.*/
	Seat& Seat::set(int row, char letter) {
		if (validate(row, letter)) {
			m_seatRow = row;
			m_letterSeat = letter;
		}
		else {
			m_seatRow = 0;
			m_letterSeat = 0;
		}
		return *this;
	}

	/*Returns the row attribute value.*/
	int Seat::row()const {
		return m_seatRow;
	}
	/*Returns the letter attribute value.*/
	char Seat::letter()const {
		return m_letterSeat;
	}
	/*Returns the value of the passenger name pointer attribute.*/
	const char* Seat::passenger()const {
		return m_passengerName;
	}

	/*passenger Name.......................... 17A
	Inserts the passenger name into the ostream in width of 40 characters, left justified and filled
	the spaces with dots ('.').
	Inserts a space
	Inserts the seating number
	Inserts the seating letter
	If the passenger name is longer than 40 character only the first 40 characters will be inserted.
	(To acoomplish this you can use a local 40+1 character cstring and copy the passenger name into
	it and print the local cstring instead.)
	If the seat number is invalid (zero), then it will insert three underlines ("___") instead:
	Passenger Name.......................... ___
	If the Seat object is in an empty state it will only print:
	Invalid Seat!
	At the end return the reference of the ostream;*/
	std::ostream& Seat::display(std::ostream& coutRef)const {
		if (this->isEmpty()) {
			coutRef << "Invalid Seat!";
		}
		else {
			char tempName[41]{};
			strncpy(tempName, m_passengerName, 40);
			coutRef.width(40);
			coutRef.fill('.');
			coutRef.setf(ios::left);                                    
			coutRef << tempName;
			coutRef.unsetf(ios::left);
			coutRef.fill(' ');
			if (validate(m_seatRow, m_letterSeat)){
				coutRef << " " << m_seatRow;
				coutRef << m_letterSeat;
			}
			else {
				coutRef << " " << "___";
			}	
		}
		return coutRef;
	}


	/*First reset the object to the empty state.
	Then Extract the 3 values in three local function scope variables:
	a character Cstring with a length of 70+1 (assuming a name can not be more than 70 chars)
	an integer for row
	a character for the seating letter.
	in the following format:
	Name (use getline())
	comma
	seat number (use extraction operator)
	seat letter (use extraction operator)
	After extracting all three from the istream reference argument, check and see if the istream NOT
	failed. If it did not, allocate memory and copy the name into the passenger name pointer attribute
	(alAndCp()). If it didn't fail to allocate and copy, then set the values of row and letter attributes
	using the set() function.
	At the end return the reference of the istream;*/
	std::istream& Seat::read(std::istream& cinRef) {
		reset();
		char name[71];
		int row;
		char letter;
		cinRef.getline(name, 71, ',');
		cinRef >> row;
		cinRef >> letter;
		cinRef.ignore();
		if (!cinRef.fail()){
			alAndCp(name);
			if (!isEmpty()) {
				set(row, letter);
			}
		 }		
		return cinRef;
	}
}