#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "HtmlText.h"
using namespace std;
namespace sdds {
	//default constructor
	HtmlText::HtmlText() {
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
	HtmlText::HtmlText(const HtmlText& HT) :Text(HT) {
		m_title = new char[strlen(HT.m_title) + 1];
		strcpy(m_title, HT.m_title);
	}

	//assignment constructor
	HtmlText& HtmlText::operator=(const HtmlText& HT) {
		if (this != &HT) {
			Text::operator=(HT);
			if (HT.m_title) {
				delete[] m_title;
				m_title = new char[strlen(HT.m_title) + 1]{};
				strcpy(m_title, HT.m_title);
			}
		}
		return *this;
	}

	//destructor
	HtmlText::~HtmlText() {
		delete[] m_title;
		m_title = nullptr;
	}

	//write ovverride function from the parent class
	std::ostream& HtmlText::write(std::ostream& ostr) const {
		bool MS = false;
		const HtmlText& HT = *this;
		int i;
		ostr << "<html><head><title>";
		if (m_title != nullptr) {
			ostr << m_title;
		}
		else {
			ostr << "No No Title";
		}
		ostr << "</title></head>\n<body>\n";
		if (m_title != nullptr) {
			ostr << "<h1>" << m_title << "</h1>\n";
		}
		for (i = 0; HT[i]; i++) {
			switch (HT[i])
			{
			case ' ':
				if (MS) ostr << "&nbsp;";
				else {
					MS = true;
					ostr << ' ';
				}
				break;
			case'<':
				ostr << "&lt;";
				MS = false;
				break;
			case'>':
				ostr << "&gt;";
				MS = false;
				break;
			case'\n':
				ostr << "<br />\n";
				MS = false;
				break;
			default:
				ostr << HT[i];
				MS = false;
				break;
			}
		}
		ostr << "</body>\n</html>";
		return ostr;
	}
}




