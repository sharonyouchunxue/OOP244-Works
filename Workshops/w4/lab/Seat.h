/*
*****************************************************************************
						Workshop 4 - part 1
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
#pragma once
#ifndef SDDS_SEAT_H_
#define SDDS_SEAT_H_
namespace sdds {
	class Seat {
	private:
		char* m_passengerName{}; // char* m_passengerName = nullptr;
		int m_seatRow;
		char m_letterSeat;
		bool validate(int row, char letter)const;	
		Seat& alAndCp(const char* str);
	public:
		Seat& reset();
		bool isEmpty() const;
		bool assigned() const;
		Seat();
		Seat(const char* passengerName);
		Seat(const char* passengerName, int row, char letter);
		~Seat();
		Seat& set(int row, char letter);
		int row()const;
		char letter()const;
		const char* passenger()const;
		std::ostream& display(std::ostream& coutRef = std::cout)const;
		std::istream& read(std::istream& cinRef = std::cin);

	};
}
#endif // !SDDS_SEAT_H_

