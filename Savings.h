//
// Created by imanu on 9/10/2022.
//

#ifndef M1OEP_ACHASE4_SAVINGS_H
#define M1OEP_ACHASE4_SAVINGS_H

#include "Person.h"

class Savings {
public:
    //Constructor
    Savings();

    //Getters
    Person getOwner();
    double getBalance();
    double getDividend();
    double getMonthlyFee();

    //Setters
    void setOwner(Person owner);
    void setBalance(double balance);
    void setDividend(double dividend);
    void setMonthlyFee(double monthlyFee);

    //Overloaded ++
    //++ will now add to balance field the new balance after dividend
    Savings& operator ++ ();

    //Overloaded --
    //-- will now subtract monthlyFee field from balance field
    Savings& operator -- ();

private:
    //Fields
    Person owner;
    double balance;
    double dividend;
    double monthlyFee;
};

#endif //M1OEP_ACHASE4_SAVINGS_H
