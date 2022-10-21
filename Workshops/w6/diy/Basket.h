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
#ifndef SDDS_BASKET_H_
#define SDDS_BASKET_H_

namespace sdds {
    struct Fruit
    {
        char m_name[30 + 1]; // the name of the fruit
        double m_qty;        // quantity in kilograms
    };

    class Basket {
    private:
        struct Fruit* m_fruitType{};
        int m_size{};
        double m_price{};
        void setEmpty();
    public:
        Basket();//default constructor
        Basket(const Fruit* fruit, int size, double price);//custom constructor
        Basket(const Basket& basket);//copy constructor
        Basket& operator=(const Basket& basket);//assignment constructor
        ~Basket(); //destructor;
        void setPrice(double price);//update price to value
        operator bool()const;//conversion
        Basket& operator +=(Fruit& fruit);//+=overlodaing operator
        //Friend Helper Function
        friend std::ostream& operator<<(std::ostream& ostr, const Basket& B);
        std::ostream& display(std::ostream& ostr)const;//display

    };
   


}
#endif