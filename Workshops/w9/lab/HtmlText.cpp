#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "HtmlText.h"
using namespace std;
namespace sdds {
	HtmlText::HtmlText(){
		m_title = nullptr;
	}
	//two argument constructor
	HtmlText::HtmlText(const char* title) {
		if (title) {
			m_title = new char[strlen(title) + 1];
			strcpy(m_title, title);
		}
	}
	//copy constructor
	HtmlText::HtmlText(const HtmlText& HT){
		operator = (HT);
	}
	//assignment constructor
	HtmlText& HtmlText::operator=(const HtmlText& HT) {
		if (this != &HT) {
			Text::operator=(HT);
			if (HT.m_title) {
				delete[] m_title;
				m_title = new char[strlen(HT.m_title) + 1];
				strcpy(m_title, HT.m_title);
			}
		}
		return *this;
	}

	HtmlText::~HtmlText() {
		delete[] m_title;
		m_title = nullptr;
	}

	std::ostream& HtmlText::write(std::ostream& ostr) const {
		Text::write(ostr);
		bool MS = false;
		int i = 0;
		ostr << "<html><head><title>";
		if (m_title != nullptr) {
			ostr << m_title;
		}
		else {
			ostr << "No Title";
		}
		ostr << "</title></head>\n<body>\n";
		if (m_title != nullptr) {
			ostr << "<h1>" << m_title << "</h1>\n";
		}
		while (this->operator[](i) != '\0') {
			const char ch = this->operator[](i);
			if (ch == ' ') {
				if (MS) {
					ostr << "&nbsp;";
				}
				else {
					MS = true;
					ostr << ' ';
				}
			}
			else if (ch == '<') {
				MS = false;
				ostr << "&lt;";
			}
			else if (ch == '>') {
				MS = false;
				ostr << "&gt;";
			}
			else if (ch == '\n') {
				MS = false;
				ostr << "<br />\n";
			}
			else {
				MS = false;
				ostr << ch;
			}
			i++;
		}
		ostr << "</body>\n</html>";
		return ostr;
	}

}

