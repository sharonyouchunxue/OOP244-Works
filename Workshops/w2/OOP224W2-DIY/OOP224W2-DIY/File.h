/*
*****************************************************************************
						Workshop 2 - part 1
Full Name  : Chunxue You
Student ID#: 127632214
Email      : cyou8@myseneca.ca
Section    : OOP244 NAA
Date       : 2022-09-24

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. I have done all
the coding by myself and only copied the code that my professor provided to
complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
	// Opens a file and keeps the file pointer in the File.cpp (file scope)
	bool openFile(const char filename[]);
	// Closes the open file
	void closeFile();
	// Finds the records kept in the file to be used for the dynamic memory allocation 
	// of the records in the file
	int noOfRecords();
	bool read(int& m_population);
	bool read(char* m_postalcode);

}
#endif // !SDDS_FILE_H_