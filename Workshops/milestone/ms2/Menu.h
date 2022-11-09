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
2020/11/09  Added printHeader function to load the dash frame format
-----------------------------------------------------------------

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. I have done all
the coding by myself and only copied the code that my professor provided to
complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__
#include <iostream>
namespace sdds {

    const int MAX_MENU_ITEMS = 10;
    //forward declare the Menu class to be able to make it a friend of MenuItem class.
    class Menu;
    class MenuItem {
    private:
        friend class Menu; //menuItem is the friend owned by Menu
        char* m_menuItem; //maximum length of 50
        MenuItem() = default;
        MenuItem(const char* item = nullptr);
        ~MenuItem();
        //MenuItem can not get copied or assigned to another MenuItem. 
        //This, must be enforced in your code
        MenuItem(const MenuItem&) = delete;
        void operator=(const MenuItem&) = delete;
        void set(const char* item);
        std::ostream& display(std::ostream& ostr = std::cout)const;
    };

    class Menu {
    private:
        char* m_title{}; // maximum length of 50 
        MenuItem* MenuItems[MAX_MENU_ITEMS]{};
        int m_numItems{};
        int indentation{};
    public:
        Menu() = default;
        Menu(const char* title, int indenValue = 0);
        Menu(const Menu&)= delete;            //MenuItem can not get copied or assigned to another MenuItem. 
        Menu& operator=(const Menu&)=delete;  //This, must be enforced in your code
        void setTitle(const char* title);
        void setMenuItems(MenuItem* const Items[], int num);
        void setIndentation(int indenValue);
        ~Menu();
        operator bool() const;
        bool isEmpty() const;
        std::ostream& display(std::ostream& ostr = std::cout)const;
        Menu& operator=(const char* title);
        void add(const char* newItem);
        Menu& operator<<(const char* menuItem);
        int run()const;
        operator int()const;
        void clear();
        void deallocate();
    };
}
#endif // !
