#include "Savings.h"
#include "Savings.cpp"
#include "Person.h"
#include "Person.cpp"
#include <iostream>

using namespace std;

bool testSavings();

int main() {
    if (testSavings()) {
        cout << "Passed all Savings test cases " << endl;
    }
}

bool testSavings() {
    bool passed = true;
    Savings savings;

    //Test balance field getters/setters
    savings.setBalance(100);
    if (savings.getBalance() != 100) {
        passed = false;
        cout << "Failed balance test case " << endl;
    }

    //Test dividend field getters/setters
    savings.setDividend(.02);
    if (savings.getDividend() != .02) {
        passed = false;
        cout << "Failed dividend test case " << endl;
    }

    //Test monthlyFee field getters/setters
    savings.setMonthlyFee(25);
    if (savings.getMonthlyFee() != 25) {
        passed = false;
        cout << "Failed monthlyFee test case " << endl;
    }

    //Test ++operator
    ++savings;
    if (savings.getBalance() != 102) {
        passed = false;
        cout << "Failed ++operator test case " << endl;
    }

    //Test --operator
    --savings;
    if (savings.getBalance() != 77) {
        passed = false;
        cout << "Failed --operator test case " << endl;
    }

    return passed;

}



