#ifndef SDDS_HTMLTEXT_H__
#define SDDS_HTMLTEXT_H__
#include "Text.h"
namespace sdds {
	class HtmlText : public Text {
		char* m_title{};
	public:
		HtmlText();
		HtmlText(const char* title);
		//rule of three
		HtmlText(const HtmlText& HT);
		HtmlText& operator=(const HtmlText& HT);
		virtual ~HtmlText(); 
		//Text::write override
		std::ostream& write(std::ostream& ostr)const;
	};
}

#endif
