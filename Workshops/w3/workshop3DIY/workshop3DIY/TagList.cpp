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
#include <iostream>
#include <cstring>
#include <cstdio>
#include "NameTag.h"
#include "TagList.h"

using namespace std;

namespace sdds {
	//Sets the TagList to an empty state
	void TagList::set() {
		m_Tags = nullptr;
		m_frameSize = 0;
		m_volum = 0;
		m_size = 0;
	}
	//Calls CleanUp() and then dynamically creates an array of num NameTags
	void TagList::set(int num) {
		cleanup();
		m_Tags = new NameTag[num];
		m_volum = num;
		m_frameSize = 0;
		m_size = 0;
	}
	//Adds up to num (of the set method) NameTags to the TagList.
	void TagList::add(const NameTag& nt) {
		m_size++;
		m_Tags[m_size - 1] = nt; 
		int length;
	    length = strlen(m_Tags[m_size - 1].getName());
			if (length > m_frameSize) {
				m_frameSize = length;
		}
	}
	//Prints all the tags with the same size that is the frame size of the longest name 
	//in the list.
	void TagList::print() {
		m_frameSize += 4;
		for (int i = 0; i < m_size; i++) {
			cout.width(m_frameSize);
			cout.fill('*');
			cout << '*';
			cout << endl;
			cout << "* ";
			cout.width(m_frameSize - 3);
			cout.fill(' ');
			cout.setf(ios::left);
			cout << m_Tags[i].getName();
			cout << '*';
			cout.unsetf(ios::left);
			cout << endl;
			cout.width(m_frameSize);
			cout.fill('*');
			cout << '*';
			//cout << endl;
			cout << endl;
		}
	}
	//Deallocates the NameTags and put the TagList back to a safe empty state
	void TagList::cleanup() {
		delete[] m_Tags;
		m_Tags = nullptr;
	}
	

 
}