// Program - Inventory Products
// Author: Bryce Smith
// Purpose: This program simulates the use of a credit card:
//          1. Charge an item
//          2. Make a payment
//          3. Show Balance
//          4. Quit


#include <iostream>
#include <iomanip>
#include <string>
#include "card.h"
using namespace std;

// Function prototypes
int menu();
void chargeIt(card &);
void payIt(card &);
void showIt(const card);

int main()
{
	int choice;		//use to store menu selestion

	card myWallet(5000); // class object
	card testobj;		// this is an instantiation to test your constructor
						// with no argument, you will not write any 
						// code for the testobj

	cout << fixed << showpoint << setprecision(2); // diplays to two decimal places
	choice = menu(); // get a menu choice before entering the loop		

	while (choice != 4)
	{
		if (choice == 1) {
            chargeIt(myWallet);     // Charge an item
        }
		else if (choice == 2) {
			payIt(myWallet);      // Make a payment
        }
		else if (choice == 3) {
			showIt(myWallet);   // Show Balance
        }
        else if (choice == 4) {
            exit(1);          // Quit
        }
		choice = menu();
	}
	return 0;
}


//-----------------------------------------------------
// Function: Menu
// Parameter: None
// Return type: int
// Allows the user to enter a menu choice from 1-4.
// Uses a data validation loop to insure a valid choice
//          1. Charge an item
//          2. Make a payment
//          3. Show Balance
//          4. Quit
//-----------------------------------------------------


int menu() {
    int choice;
    do {
        cout << "\n----------------------";
        cout << "\n1. Charge an item";
        cout << "\n2. Make a payment";
        cout << "\n3. Show Balance";
        cout << "\n4. Quit";
        cout << "\n----------------------";
        cout << "\nEnter your choice: ";
        cin >> choice;
    } while (choice < 1 || choice > 4);
    return choice;
}


//-----------------------------------------------------
// Function: chargeIt
// Parameter: card object
// Return type: void
// Displays current limit and balance
// Allows the use to enter an amount to change
// Checks for available credit and makes the purchase
// or declines the transaction.
// Displays the resulting balance
//-----------------------------------------------------


void chargeIt(card &myCard) {
    int amount;
    cout << "Credit Limit:    $" << myCard.getLimit() << endl;
    cout << "Current Balance: $" << myCard.getBalance() << endl;
    cout << "Enter the charge amount: ";
    cin >> amount;
    if (myCard.getBalance() + amount > myCard.getLimit()) {
        cout << "Purchase Declined $" << amount;   // Purchase goes over credit limit (decline)
    } else {
        myCard.purchase(amount);
        cout << "Purchase approved $" << amount;
    }
    cout << "\nNew Balance: $" << myCard.getBalance();
}


//-----------------------------------------------------
// Function: payIt
// Parameter: card object
// Return type: void
// Displays current limit and balance
// Allows the use to enter an amount to pay
// Checks for overpayment and makes the payment
// or declines the transaction.
// Displays the resulting balance
//-----------------------------------------------------


void payIt(card &myCard) {
    int amount;
    cout << "Credit Limit:    $" << myCard.getLimit() << endl;
    cout << "Current Balance: $" << myCard.getBalance() << endl;
    cout << "Enter the payment amount: ";
    cin >> amount;
    if (amount > myCard.getBalance()) {
        cout << "Payment Declined $" << amount << endl;   // Overpaid (decline)
    } else {
        myCard.payment(amount);
        cout << "Payment processed\n";
    }
    cout << "New Balance: $" << myCard.getBalance();
}


//-----------------------------------------------------
// Function: showIt
// Parameter: card object
// Return type: void
// Displays balance
// We probably didn't need a function for this, but why not!
//-----------------------------------------------------


void showIt(const card myCard) {
    cout << "Balance: $" << myCard.getBalance();   // Display balance
}
