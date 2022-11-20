#include "Person.h"
#include "Person.cpp"
#include <iostream>

using namespace std;

bool testPerson();

int main() {
    if (testPerson()) {
        cout << "Passed all Person test cases " << endl;
    }
}

bool testPerson() {
    bool passed = true;
    Person person;

    //Test firstName field getters/setters
    person.setFirstName("First");
    if (person.getFirstName() != "First") {
        passed = false;
        cout << "Failed firstName test " << endl;
    }

    //Test lastName field getters/setters
    person.setLastName("Last");
    if (person.getLastName() != "Last") {
        passed = false;
        cout << "Failed lastName test " << endl;
    }

    //Test age field getters/setters
    person.setAge(0);
    if (person.getAge() != 0) {
        passed = false;
        cout << "Failed age test " << endl;
    }

    //Test zipCode field getters/setters
    person.setZipCode(0);
    if (person.getZipCode() != 0) {
        passed = false;
        cout << "Failed zipCode test " << endl;
    }

    //Test ++operator
    ++person;
    if (person.getAge() != 1) {
        passed = false;
        cout << "Failed ++Operator test " << endl;
    }

    //Test fullDetails function
    string fullDetails =  + "Last, First, 0. Age: 1";
    if (person.fullDetails() != fullDetails) {
        passed = false;
        cout << "Failed fullDetails test " << endl;
    }

    return passed;

}
