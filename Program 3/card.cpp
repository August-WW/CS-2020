// card.cpp
// File for implementing the card class functions.
// Includes constructor, accessors, mutators, and functions

#include "card.h"
#include <iostream>
using namespace std;

// Constructor
card::card(int creditLimit) : limit(creditLimit), balance(0) {}

// Accessors
int card::getLimit() const {
    return limit;
}
int card::getBalance() const {
    return balance;
}

// Mutators
void card::setLimit(int newLimit) {
    limit = newLimit;
}
void card::setBalance(int newBalance) {
    balance = newBalance;
}

// Purchase function
void card::purchase(int amount) {
    if (balance + amount > limit) {
        cerr << "Purchase declined.\n"; // Credit limit exceeded (declined)
        exit(1);
    }
    balance += amount;
}

// Payment function
void card::payment(int amount) {
    if (balance - amount < 0) {
        cerr << "Payment declined.\n"; // Overpaid (declined)
        exit(1);
    }
    balance -= amount;
}
