#define _CRT_SECURE_NO_WARNINGS
// Author: Cornel
#include <iostream>
//#include "word.h"
//#include "word.h"
//#include "dictionary.h"
//#include "dictionary.h"

using namespace std;
namespace sdds {


	//prototype for dictionary module
	int LoadDictionary(const char* filename);
	void SaveDictionary(const char* filename);
	void DisplayWord(const char* word);
	void AddWord(const char* word, const char* type, const char* definition);
	int UpdateDefinition(const char* word, const char* type, const char* definition);
	char sortStrings(char temp[MAX_WORD_LEN + 1], Dictionary* dictionary, int* wordCount,
		int* definitionCount, int* blankCount);
	

	//prototype for word section


	const char* DICTIONARY_DATA_FILE = "dictionary.txt";
	FILE* sfptr = nullptr;

	const int MAX_NUM_WORDS = 100; //the file max 100 words with definition
	const int MAX_WORD_DEFINITIONS = 8;//each word max 8 definition
	const int MAX_WORD_LEN = 64; // the type of word have max 64 characters
	const int MAX_TEXT_DEFI_LEN = 1024; //text definition max 1024 characters

	struct Word {
		Definition m_definition[MAX_WORD_DEFINITIONS];
		char m_content_word[MAX_WORD_LEN + 1];
		int m_numOfDefinition;
		bool m_wordFind;
	};

	struct Definition {
		char m_content_def[MAX_TEXT_DEFI_LEN + 1];
	};

	struct Dictionary {
		Word m_word[MAX_NUM_WORDS];
		bool m_user_search_word;
		int m_numOfWord;
	};

	extern Word m_word[MAX_NUM_WORDS];
	extern Dictionary dictionary;

	//function section
	FILE* file = nullptr;


	char sortStrings(char temp[MAX_WORD_LEN + 1], Dictionary* dictionary, int* wordCount,
		int* definitionCount, int* blankCount) {

	}

	//Load dictionary file, return 0 if properly loaded
	int LoadDictionary(const char* filename) {
		int fileLoaded = -1;
		int wordCount = 0;
		int definitionCount = 0;
		int blankCount = 0;
		int clearWord;
		char result = ' ';
		int tempVal;
		dictionary.m_numOfWord = 0;
		for (clearWord = 0; clearWord < MAX_NUM_WORDS;
			clearWord++) dictionary.m_word[clearWord] = { 0 };

		file = fopen(filename, "r");
		if (file) {
			fileLoaded = 0;
			char temp[MAX_WORD_LEN + 1];
			do {
				tempVal = fscanf(file, "% [^ \n]", temp);
				if (fgetc(file) == '\n')
					blankCount++;
				if (blankCount != 2) {
					result = sortStrings(temp, &dictionary, &wordCount, &definitionCount, &blankCount);
				}
				if (result == 'a') wordCount++;
				if (blankCount == 2) {
					blankCount = 0;
					definitionCount++;
					wordCount = 0;
				}
			} while (feof(file) == 0);
		}
		else {
			cout << "File Failed to Load" << endl;
		}
		return fileLoaded;
		
	}
	

	int main()
	{
		
		// USAGE CASE #1: load a dictionary from a file that doesn't exist
		cout << "------------------------------------------------------------\n";
		cout << "USAGE CASE #1: bad input file\n";
		cout << "------------------------------------------------------------\n";
		if (sdds::LoadDictionary("missing.txt") == 0)
		{
			cout << "ERROR: There is no file; the function 'LoadDictionary()' should return non-zero value.\n";
			cout << "       Keep working on your code.\n";
		}
		else
		{
			cout << "SUCCESS\n";
		}
		cout << "------------------------------------------------------------\n\n";


		
		// USAGE CASE #2: load a valid dictionary from the file and display it to the user
		cout << "------------------------------------------------------------\n";
		cout << "USAGE CASE #2: good dictionary\n";
		cout << "------------------------------------------------------------\n";
		 if (sdds::LoadDictionary("dictionary.txt") == 0)
		{
			cout << "SUCCESS\n";

			std::cout << "\nSearch for the word 'fine'\n\n";
			sdds::DisplayWord("fine");

			std::cout << "\nAdding 2 more definitions to word 'fine' and display it.\n\n";
			sdds::AddWord("fine", "verb", "clarify (beer or wine) by causing the precipitation of sediment during production.");
			sdds::AddWord("fine", "verb", "make or become thinner.");
			sdds::DisplayWord("fine");

			//std::cout << "\nSeach for words containing 'very' in their definition.\n\n";
			//sdds::DisplayMatches("very");
			std::cout << "\nDisplay the word 'apple'.\n\n";
			sdds::DisplayWord("apple");

			std::cout << "\nOOOPS! The SECOND definition for apple is wrong. Let's update it.\n\n";
			sdds::UpdateDefinition("apple", "noun", "the tree which bears apples.");
			std::cout << "\n";
			sdds::DisplayWord("apple");

			// add a few more words
			std::cout << "\n\nAdding more words and display them.\n\n";

			sdds::AddWord("language", "noun", "a system of communication used by a particular country or community.");
			sdds::AddWord("computer", "noun", "an electronic device for storing and processing data, "
				"typically in binary form, according to instructions "
				"given to it in a variable program.");
			sdds::AddWord("computer", "noun", "a person who makes calculations, especially with a calculating machine.");
			sdds::DisplayWord("language");
			std::cout << "\n";
			sdds::DisplayWord("computer");

			sdds::SaveDictionary("dictionary_better.txt");
		}
		else
		{
			cout << "ERROR: There is no file; the function 'LoadDictionary()' should return non-zero value.\n";
			cout << "       Keep working on your code.\n";

		}
		cout << "------------------------------------------------------------\n\n";
		

		// USAGE CASE #3: load a dictionary from a file that doesn't exist
		cout << "------------------------------------------------------------\n";
		cout << "USAGE CASE #3: bad input file\n";
		cout << "------------------------------------------------------------\n";
		if (sdds::LoadDictionary("missing_better.txt") == 0)
		{
			cout << "ERROR: There is no file; the function 'LoadDictionary()' should return non-zero value.\n";
			cout << "       Keep working on your code.\n";
		}
		else
		{
			cout << "SUCCESS\n";

			// the loaded dictionary should be empty now
			// the following function should not find anything
			sdds::DisplayWord("apple");
		}
		cout << "------------------------------------------------------------\n\n";
		

		// USAGE CASE #4: load the previously saved distionary
		cout << "------------------------------------------------------------\n";
		cout << "USAGE CASE #4: loading the previously saved dictionary\n";
		cout << "------------------------------------------------------------\n";
		if (sdds::LoadDictionary("dictionary_better.txt") == 0)
		{
			cout << "SUCCESS\n";

			std::cout << "Search for the word 'apple'\n\n";
			sdds::DisplayWord("apple");

			std::cout << "\n\nSearch for the word 'language'\n\n";
			sdds::DisplayWord("language");

			std::cout << "\n\nSearch for the word 'computer'\n\n";
			sdds::DisplayWord("computer");

			std::cout << "\n\nSearch for the word 'oop'\n\n";
			sdds::DisplayWord("oop");
		}
		else
		{
			cout << "ERROR: The dictionary should be valid; the function 'LoadDictionary()' should return non-zero value.\n";
			cout << "       Keep working on your code.\n";
		}
		cout << "------------------------------------------------------------\n\n";


		
		return 0;
	}

	
	

}