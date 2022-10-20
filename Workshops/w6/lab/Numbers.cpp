/*
*****************************************************************************
                        Workshop 6 - part 1
Full Name  : Chunxue You(Sharon)
Student ID#: 127632214
Email      : cyou8@myseneca.ca
Section    : OOP244 NAA
Date       : 2022-10-19

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. I have done all
the coding by myself and only copied the code that my professor provided to
complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include "Numbers.h"
using namespace std;
namespace sdds {

    //Constructors, Destructor and Copy Assignment
    //default constructor
    Numbers::Numbers() {
        setEmpty();
        m_isOriginal = false;
    }

    //One argument constructor
    Numbers::Numbers(const char* filename) {
        setEmpty();
        m_isOriginal = true;
        setFilename(filename);//sets the filename of the class
        m_numCount = numberCount();
        if (m_numCount == 0 || !load()) {
            deallocate();
            setEmpty();
            m_isOriginal = false;
        }
    }
    //Destructor
    Numbers::~Numbers() {
        save();
        deallocate();
    }

    //Copy Constructor(to be implemented by students)
    Numbers::Numbers(const Numbers& I){
        setEmpty();
        m_isOriginal = false;
        *this = I;
    }

    //Copy Assignment Operator(to be implemented by students)
    Numbers& Numbers::operator=(const Numbers& I) {
        if (this != &I) {//if this is not a self-copy assignment
            delete[] m_numbers;//double value
            setEmpty();
            m_isOriginal = false;
            m_numbers = new double[I.m_numCount];
            for (int i = 0; i < I.m_numCount; i++) {
                m_numbers[i] = I.m_numbers[i];
            }
            m_numCount = I.m_numCount;
        }
        return *this;
    }

    //Member Functions and Member operator+= overload
    //returns true if m_numbers is null
    bool Numbers::isEmpty() const {
        return m_numbers == nullptr;
    }

    //sets m_numbers and m_filename to nullptr. sets m_numCount to zero.
    void Numbers::setEmpty() {
        m_numbers = nullptr;
        m_filename = nullptr;
        m_numCount = 0;
    }
    //Deallocates the dynamic memory.
    void Numbers::deallocate() {
        delete[] m_filename;
        delete[] m_numbers;
    }
    //setFilename
    void Numbers::setFilename(const char* filename) {
        delete[] m_filename;
        m_filename = new char[strlen(filename) + 1];
        strcpy(m_filename, filename);
    }
    //Returns the smallest double number in the list
    double Numbers::min() const {
        double minVal = 0.0;
        if (!isEmpty()) {
            minVal = m_numbers[0];
            for (int i = 1; i < m_numCount; i++)
                if (minVal > m_numbers[i]) minVal = m_numbers[i];
        }
        return minVal;
    }

   // Returns the largest double number in the list
    double Numbers::max() const {
        double maxVal = 0.0;
        if (!isEmpty()) {
            maxVal = m_numbers[0];
            for (int i = 1; i < m_numCount; i++)
                if (maxVal < m_numbers[i]) maxVal = m_numbers[i];
        }
        return maxVal;
    }

    //Returns the average of the double numbers in the list.
    double Numbers::average() const {
        double aver = 0.0;
        if (!isEmpty()) {
            for (int i = 0; i < m_numCount; i++)
                aver += m_numbers[i];
            aver = aver / m_numCount;
        }
        return aver;
    }
   
    //Numbers& sort(bool ascending)
    Numbers& Numbers::sort(bool ascending){
        if (ascending) {
            for (int i = 0; i < m_numCount; i++) {
                for (int j = i + 1; j < m_numCount; j++) {
                    if (m_numbers[i] > m_numbers[j]) {
                        double temp = m_numbers[i];
                        m_numbers[i] = m_numbers[j];
                        m_numbers[j] = temp;
                    }
                }
            }
        }
        else {  //descending
            for (int i = 0; i < m_numCount; i++) {
                for (int j = i + 1; j < m_numCount; j++) {
                    if (m_numbers[i] < m_numbers[j]) {
                        double temp = m_numbers[i];
                        m_numbers[i] = m_numbers[j];
                        m_numbers[j] = temp;
                    }
                }
            }
        }  
        return *this;
    }

    //Unary negation operator ( - ) (to be implemented by students)
    //This unary operator (that is incapable of modifying the current object) will return a descending sorted copy of 
    //the Numbers object.
    Numbers Numbers::operator-() const{
      
        return *this;
    }

    //Unary plus operator ( +) (to be implemented by students)
    //This unary operator (that is incapable of modifying the current object) will return an ascending
    //  sorted copy of the Numbers object.

    Numbers Numbers::operator+() const{
       
        return *this;
    }

    //numberCount, read data from the file
    int Numbers::numberCount()const{
        int count{};
        char ch{};
        ifstream f(m_filename); 
        while (f) {
            ch = f.get();
            if (ch == '\n') {
                count++;
            }
        }    
        return count;
    }

    //load
    bool Numbers::load(){
        bool read = false;
        int i{};
        if (m_numCount > 0) {
            m_numbers = new double[m_numCount];
            ifstream f(m_filename);
            while (f && i < m_numCount) {
                f >> m_numbers[i];
                if (f) {
                    i++;
                    read = true;
                }
            }
        }
        return read;
    }

    //save copy to output.txt 
    void Numbers::save(){
        if (m_isOriginal && !isEmpty()) {
            std::ofstream f(m_filename);
            for (int i = 0; i < m_numCount; i++) {
                f << m_numbers[i] << endl;
            }
        }
    }
    
   //Operatro += (to be implemented by students)
    Numbers& Numbers::operator+=(const double M) {
        double* temp{};
        temp = new double[m_numCount + 1];
        for (int i = 0; i < m_numCount; i++) {
            temp[i] = m_numbers[i];
        }
        temp[m_numCount ] = M;
        m_numCount += 1;
        delete[] m_numbers;
        m_numbers = temp;
        return *this;
    }

    //Displays the Numbers object on the screen. Note that all the double numbers are printed with two digits after the 
    //decimal point.
    ostream& Numbers::display(ostream& ostr) const {
        if (isEmpty()) {
            cout << "Empty list";
        }
        else {
            ostr << "=========================" << endl;
            if (m_isOriginal) {
                ostr << m_filename << endl;
            }
            else {
                ostr << "*** COPY ***" << endl;
            }
                for (int i = 0; i < m_numCount; i++) {
                    ostr << m_numbers[i];
                    if (i != m_numCount - 1) {
                        ostr << ", ";
                    }
                    else {
                        ostr << endl;
                    }          
            }
            ostr << "-------------------------" << endl;
            ostr << "Total of " << m_numCount << " number(s)" << endl;
            ostr << "Largest number:  " << max() << endl;
            ostr << "Smallest number: " << min() << endl;
            ostr << "Average :        " << average() << endl;
            ostr << "========================="; cout << endl;
        }
        return ostr;
    }
    
    //Helper function overloads
    //Overload the insertion operator to display the Numbers object using istream.
    ostream& operator<<(ostream& os, const Numbers& N) {
        return N.display(os);
    }

    //Overload the extraction operator to read the Numbers object using istream.
    std::istream& operator>>(std::istream& istr, Numbers& N){
        double n{};
        istr >> n;
        N += n;
        return istr;
    }

}