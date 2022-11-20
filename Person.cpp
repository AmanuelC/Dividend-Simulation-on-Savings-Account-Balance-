//
// Created by imanu on 9/10/2022.
//

#include "Person.h"

using namespace std;

Person::Person(): firstName(""), lastName(""), age(0), zipCode(0) { }

string Person::getFirstName() {
    return firstName;
}

string Person::getLastName() {
    return lastName;
}

int Person::getAge() {
    return age;
}

int Person::getZipCode() {
    return zipCode;
}

void Person::setFirstName(string firstName) {
    this->firstName = firstName;
}

void Person::setLastName(string lastName) {
    this->lastName = lastName;
}

void Person::setAge(int age) {
    this->age = age;
}

void Person::setZipCode(int zipCode) {
    this->zipCode = zipCode;
}

string Person::fullDetails() {
    string fullDetails = lastName + ", " + firstName + ", " + to_string(zipCode) + ". Age: " + to_string(age);
    return fullDetails;
}

Person& Person::operator++() {
    age = age + 1;
    return *this;
}