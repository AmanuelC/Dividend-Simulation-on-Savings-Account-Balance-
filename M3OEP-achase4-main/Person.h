//
// Created by imanu on 9/10/2022.
//

#ifndef M1OEP_ACHASE4_PERSON_H
#define M1OEP_ACHASE4_PERSON_H

#include <string>

using namespace std;

class Person {
public:
    //Constructor
    Person();

    //Getters
    string getFirstName();
    string getLastName();
    int getAge();
    int getZipCode();

    //Setters
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setAge(int age);
    void setZipCode(int zipCode);

    //Function that returns string that includes all fields on Person Object
    string fullDetails();

    //Overloaded ++
    //++ will now add 1 to the age field
    Person& operator ++ ();



private:
    //Fields
    string firstName;
    string lastName;
    int age;
    int zipCode;

};
#endif //M1OEP_ACHASE4_PERSON_H
