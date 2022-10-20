/*
*****************************************************************************
                        Workshop 6 - part 2
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
#include <iostream>
#include <cstring>
#include "Basket.h"
using namespace std;
namespace sdds {
   
    //default constructor
    Basket::Basket(){
        setEmpty();
    }

    //set all element to empty state
    void Basket::setEmpty(){
        m_fruitType = nullptr;
        m_size = 0;
        m_price = 0.0;
    }

    //custom constructor
    Basket::Basket(const Fruit* fruit, int size, double price){
        setEmpty();
        if (size > 0 && fruit != NULL) {
            m_size = size;
            m_price = price;
            m_fruitType = new Fruit[size];
            for (int i = 0; i < size; i++) {
                m_fruitType[i] = fruit[i];
            }
        }
    }

    //copy constructor 
    Basket::Basket(const Basket& basket){
        setEmpty();
        *this = basket;
    }

    //copy assignment constructor operator
    Basket& Basket::operator=(const Basket& basket){
        if (this != &basket) {//if this is not a self-copy assignment
            delete[] m_fruitType;//double value
            setEmpty();
            m_fruitType = new Fruit[basket.m_size];
            for (int i = 0; i < basket.m_size; i++) {
                m_fruitType[i] = basket.m_fruitType[i];
            }
            m_size = basket.m_size;
            m_price = basket.m_price;
        }
        return *this;
    }

    //destructor;
    Basket::~Basket() {
        delete[] m_fruitType;
        m_fruitType = nullptr;
    }

    //update price to value
    void Basket::setPrice(double price){
        m_price = price;
    }

    //the conversion to bool operator: returns true if the basket contains any fruits, false otherwise.
    Basket::operator bool() const{
        bool valid = false;
        if (m_fruitType != NULL) {
            valid = true;
        }
        return valid;
    }

    Basket& Basket::operator+=(Fruit& fruit) {
        Fruit* temp{};
        temp = new Fruit[m_size + 1];
        for (int i = 0; i < m_size; i++) {
            temp[i] = m_fruitType[i];
        }
        temp[m_size] = fruit;
        m_size += 1;
        delete[] m_fruitType;
        m_fruitType = temp;
        return *this;
    }

    std::ostream& Basket::display(std::ostream& ostr) const{
        if (m_size == 0) {
            ostr << "The basket is empty!" << endl;
        }
        else {
            ostr << "Basket Content:" << endl;
            for (int i = 0; i < m_size; i++) {
                ostr.setf(ios::right);
                ostr.setf(ios::fixed);
                ostr.width(10);
                ostr << m_fruitType[i].m_name << ": ";
                ostr.precision(2);
                ostr << m_fruitType[i].m_qty << "kg" << endl;
            }
            ostr << "Price: " << m_price << endl;
        }
        return ostr;
    }
    std::ostream& operator<<(std::ostream& ostr, const Basket& basket){
        return basket.display(ostr);
    }
}