/*
*****************************************************************************
                        Workshop 10
Full Name  : Chunxue You(Sharon)
Student ID#: 127632214
Email      : cyou8@myseneca.ca
Section    : OOP244 NAA
Date       : 2022-11-28
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. I have done all
the coding by myself and only copied the code that my professor provided to
complete my workshops and assignments.
*****************************************************************************
*/
#include <iostream>
#include "Car.h"
#include "Employee.h"
#include "ReadWrite.h"
#include "Student.h"
#include "Collection.h"
#include "search.h"
using namespace std;
using namespace sdds;

int main() {
    Car C[8] = { Car("GVFGHI", "Tesla Model S"), Car("ABCDEF", "BMW 320"), Car("CDEFGH", "Ford Festiva"),
                 Car("BCDEFG", "Ford Festiva"),Car("GVDGHI", "Tesla Model 3"), Car("EFGHIJ", "Nissan Maxima"),
                 Car("GVDEFG", "Tesla Model X") };
    Student S[6] = { Student(23456, "Lisa Simpson"),Student(45678, "Ralph Wiggum"), Student(56789, "Milhouse Van Houten"),
                 Student(67890, "Todd Flanders"), Student(34567, "Nelson Muntz"),Student(12345, "Bart Simpson") };
    Employee E[6] = { Employee(213456, "Carl Carlson", 62344.56), Employee(122345, "Mindy Simmons", 65432.44),
                 Employee(435678, "Lenny Leonard", 43213.22), Employee(546789, "Waylon Smithers", 654321.55),
                 Employee(657890, "Frank Grimes", 34567.88), Employee(364567, "Homer Simpson", 55432.11) };
    Collection<Car> Cres;
    Collection<Student> Sres;
    Collection<Employee>Eres;
    cout << "Searching for Tesla cars: " << endl;

    // Call the search function passing "Tesla" as the key argument and "Cres" for Collection 
    if (search(Cres, C, (sizeof(C)/sizeof(C[0])), "Tesla")) {
        cout << Cres.size() << " match" << (Cres.size() == 1 ? "" : "es") << " found:" << endl;
        for (int i = 0; i < Cres.size(); i++) {
            cout << (i + 1) << ": " << Cres[i] << endl;
        }
    }
    else {
        cout << "No matches found!" << endl;
    }
    cout << "Searching for students with \"Simpson\" in their name" << endl;
    // Call the search function passing "Simpson" as the key argument and "Sres" for Collection 
    if (search(Sres, S, (sizeof(S) / sizeof(S[0])), "Simpson")) {
        cout << Sres.size() << " match" << (Sres.size() == 1 ? "" : "es") << " found:" << endl;
        for (int i = 0; i < Sres.size(); i++) {
            cout << (i + 1) << ": " << Sres[i] << endl;
        }
    }
    else {
        cout << "No matches found!" << endl;
    }
    cout << "Searching for employees with \"Sim\" in their name" << endl;
    // Call the search function passing "Sim" as the key argument and "Eres" for Collection 
    if (search(Eres, E, (sizeof(E) / sizeof(E[0])), "Sim")) {
        cout << Eres.size() << " match" << (Eres.size() == 1 ? "" : "es") << " found:" << endl;
        for (int i = 0; i < Eres.size(); i++) {
            cout << (i + 1) << ": " << Eres[i] << endl;
        }
    }
    else {
        cout << "No matches found!" << endl;
    }
    cout << "Searching for employees with \"Jack\" in their name" << endl;
    // Call the search function passing "Jack" as the key argument  and "Eres" for Collection 
    if (search(Eres, E, (sizeof(E) / sizeof(E[0])), "Jack")) {
        cout << Eres.size() << " match" << (Eres.size() == 1 ? "" : "es") << " found:" << endl;
        for (int i = 0; i < Eres.size(); i++) {
            cout << (i + 1) << ": " << Eres[i] << endl;
        }
    }
    else {
        cout << "No matches found!" << endl;
    }
    return 0;
}