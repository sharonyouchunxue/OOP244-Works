/*
*****************************************************************************
                        Milestone 2
Student ID#: 127632214
Email      : cyou8@myseneca.ca
Section    : OOP244 NAA
Filename: Parking.cpp
Version 1.0
Full Name  : Chunxue You(Sharon)
Revision History
----------------------------------------------------------------
Date      Reason
2020/11/08  Preliminary release
2020/11/09  Added a printHeader() function to load the dash frame
-----------------------------------------------------------------

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
#include "Menu.h"
#include "Utils.h"
using namespace std;
namespace sdds {

    //menuItems class
    //1.construction
    //one argument constructor

    MenuItem::MenuItem(const char* item) {
        m_menuItem = new char[strlen(item) + 1];
        strcpy(m_menuItem, item);
    }

    void MenuItem::set(const char* item) {
        delete[] m_menuItem;
        if (item != nullptr && item[0] != '\0') {
            m_menuItem = new char[strlen(item) + 1];
            strcpy(m_menuItem, item);
        }
    }

    //2.memember function display
    std::ostream& MenuItem::display(std::ostream& ostr) const {
        if (m_menuItem != nullptr && m_menuItem[0] != '\0') {
            ostr << m_menuItem << endl;
        }
        return ostr;
    }

    //destructor
    MenuItem::~MenuItem() {
        delete[] m_menuItem;
        m_menuItem = nullptr;
    }

    //Menu class
    //1.Properties: (member variables)
    //(1).Title
    void Menu::setTitle(const char* title) {
        if (title != nullptr && title[0] != '\0') {
            m_title = new char[strlen(title) + 1];
            strcpy(m_title, title);
        }
    }
    //(2).MenuItems
    void Menu::setMenuItems(MenuItem* const Items[], int num) {
        if (num > 0) {
            if (num <= MAX_MENU_ITEMS) {
                m_numItems = num;
            }
            else {
                m_numItems = MAX_MENU_ITEMS;
            }
            for (int i = 0; i < m_numItems; i++) {
                MenuItems[i] = new MenuItem(Items[i]->m_menuItem);
            }
        }
        else {
            for (int i = 0; i < MAX_MENU_ITEMS; i++) {
                MenuItems[i] = nullptr;
            }
            m_numItems = 0;
        }
    }
    //(3).Indentation
    void Menu::setIndentation(int indenValue) {
        if (indenValue > 0) {
            indentation = indenValue;
        }
        else {
            indentation = 0;
        }
    }

    //2.construction
    Menu::Menu(const char* title, int indenValue) {
        if (title != nullptr && title[0] != '\0') {
            m_title = new char[strlen(title) + 1];
            strcpy(m_title, title);
            indentation = indenValue;
            *MenuItems = nullptr;
            m_numItems = 0;
        }
        else {
            clear();
        }
    }
    //3.Copy and Assignment

    //clear
    void Menu::clear() {
        deallocate();
        m_title = nullptr;
        *MenuItems = nullptr;
        m_numItems = 0;
        indentation = 0;
    }

    void Menu::deallocate() {
        delete[] m_title;
        m_title = nullptr;
        for (int i = 0; i < m_numItems; i++) {
            delete MenuItems[i];
            MenuItems[i] = nullptr;
        }
    }

    //Member functions, operator and cast overloads:
    //bool cast overload
    Menu::operator bool() const {
        bool valid = false;
        if (m_numItems > 0) {
            valid = true;
        }
        return valid;
    }

    //isEmpty() function
    bool Menu::isEmpty() const {
        return m_title == nullptr;
    }

    //display function
    std::ostream& Menu::display(std::ostream& ostr) const {
        if (isEmpty()) {
            ostr << "Invalid Menu!" << endl;
        }
        else {
            int space = indentation * 4;
            ostr.width(space);
            ostr << "";
            ostr << m_title << endl;
            if (MenuItems[0] == nullptr) {
                ostr << "No Items to display!" << endl;
            }
            else {
                for (int i = 0; i < m_numItems; i++) {
                    ostr.width(space);
                    ostr << "";
                    ostr << i + 1 << "- ";
                    MenuItems[i]->display();
                }
                ostr.width(space);
                ostr << "" << "> ";
            }
        }
        return ostr;
    }
    /*A Menu should be able to be assigned to a constant character C-string.
    This should reset the title of the Menu to the newly assigned string.
    If the string is invalid (null) the Menu is set to an invalid empty state.*/
    Menu& Menu::operator=(const char* title) {
        deallocate();
        setTitle(title);
        return *this;
    }

    //add function
    void Menu::add(const char* newItem) {
        if (!isEmpty()) {
            if (m_numItems < MAX_MENU_ITEMS) {
                if (newItem != nullptr && newItem[0] != '\0') {
                    MenuItems[m_numItems] = new MenuItem(newItem);
                    m_numItems++;
                }
                else {
                    delete[] m_title;
                    m_title = nullptr;
                    for (int i = 0; i < m_numItems; i++) {
                        delete MenuItems[i];
                        MenuItems[i] = nullptr;
                    }
                    clear();
                }
            }
        }
    }

    //left shift operator overload (“<<”)
    Menu& Menu::operator<<(const char* menuItem) {
        add(menuItem);
        return *this;
    }

    //Menu class in action (run function):
    int Menu::run()const {
        display();
        int selection = 0;
        if (MenuItems[0] != nullptr) {
            char ch[50];
            int invalid;
            do {
                invalid = 0;
                cin >> ch;
                cin.ignore(1000, '\n');
                if (!isdigit(*ch)) {
                    cout << "Invalid Integer, try again: ";
                    /*cin.clear();
                    cin.ignore(1000, '\n');*/
                    invalid = 1;
                }
                else {
                    selection = atoi(ch);//convert char to int
                    if (selection < 1 || selection > m_numItems) {
                        cout << "Invalid selection, try again: ";
                        /*cin.clear();
                        cin.ignore(1000, '\n');*/
                        invalid = 1;
                    }
                }
            } while (invalid);
        }
        return selection;
    }

    //Integer cast overload
    //After creating the run function, overload the cast operator so if the Menu object 
    //is casted to an integer, the run function is called, and its value is returned as 
    //the integer cast value.
    Menu::operator int() const {
        return run();
    }

    //destructor
    Menu::~Menu() {
        delete[] m_title;
        m_title = nullptr;
        for (int i = 0; i < m_numItems; i++) {
            delete MenuItems[i];
            MenuItems[i] = nullptr;
        }
    }
}