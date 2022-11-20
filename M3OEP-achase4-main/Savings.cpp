//
// Created by imanu on 9/10/2022.
//

#include "Savings.h"
#include "Person.h"

Savings::Savings() : owner(), balance(0), dividend(0), monthlyFee(0) { }

Person Savings::getOwner() {
    return owner;
}

double Savings::getBalance() {
    return balance;
}

double Savings::getDividend() {
    return dividend;
}

double Savings::getMonthlyFee() {
    return monthlyFee;
}

void Savings::setOwner(Person owner) {
    this->owner = owner;
}

void Savings::setBalance(double balance) {
    this->balance = balance;
}

void Savings::setDividend(double dividend) {
    this->dividend = dividend;
}

void Savings::setMonthlyFee(double monthlyFee) {
    this->monthlyFee = monthlyFee;
}

Savings& Savings::operator++() {
    double dividendCredit = balance * dividend;
    balance = balance + dividendCredit;
    return *this;
}

Savings& Savings::operator--() {
    balance = balance - monthlyFee;
    return *this;
}

