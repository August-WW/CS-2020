// card.h
// Header file for defining the card class
// Includes constructor, accessors, mutators, and functions

#ifndef CARD_H
#define CARD_H

// No namespace std

class card {
private:
    int limit;
    int balance;

public:
    // Constructor with default parameter
    card(int creditLimit = 5000) : limit(creditLimit), balance(0) {}

    // Accessors
    int getLimit() const { 
        return limit; 
    }
    int getBalance() const { 
        return balance; 
    }

    // Mutators
    void setLimit(int newLimit) { 
        limit = newLimit; 
    }
    void setBalance(int newBalance) {
        balance = newBalance; 
    }

    // Functions
    void purchase(int amount) {
        if (balance + amount > limit) {
            std::cerr << "Payment declined.\n";   // Goes over credit limit (declined)
            exit(1);
        }
        balance += amount;
    }

    void payment(int amount) {
        if (balance - amount < 0) {
            std::cerr << "Payment declined.\n";   // Overpaid (declined)
            exit(1);
        }
        balance -= amount;
    }
};

#endif
