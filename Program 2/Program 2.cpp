// Program #2  Product Inventory Program
// Programmer:  Bryce Smith
// Class:  CS 2020, Spring 2025
// Due Date: February 23rd, 2025
// Purpose of program: Create a program that
// will keep an inventory of products that the user
// adds into the vector. The user can choose to add a product,
// see the average price, see the highest price, see the out of stock products,
// and display all of the products in the inventory vector.

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

struct Product
{
    string name;    // Name
    int qty;       // quantity is the number of items in stock
    double price; // price to purchase one item
};

// Function prototypes
int menu();
void addprod(vector<Product> &bginventory);
void showavgprice(const vector<Product> &bginventory);
void showhiprice(const vector<Product> &bginventory);
void showoutofstock(const vector<Product> &bginventory);
void showinventory(const vector<Product> &bginventory);

int main() {
    vector<Product> bginventory;
    int choice;
    
    choice = menu();
    while (choice != 6) {
        if (choice == 1) {
            addprod(bginventory);
        } else if (choice == 2) {
            showavgprice(bginventory);
        } else if (choice == 3) {
            showhiprice(bginventory);
        } else if (choice == 4) {
            showoutofstock(bginventory);
        } else if (choice == 5) {
            showinventory(bginventory);
        }
        choice = menu();
    }
    return 0;
}
//************************************************************************************
//Function: menu
//Function to display the main menu where the user makes a choice of what to do
//************************************************************************************
int menu() {
    int choice;
    do {
        cout << "1. Add new product\n";
        cout << "2. Average Price\n";
        cout << "3. Highest Price\n";
        cout << "4. Display out of stock\n";
        cout << "5. Display all products in inventory\n";
        cout << "6. Exit the program\n";
        cout << "Enter your choice: ";
        cin >> choice;  // User chooses menu option
    } while (choice < 1 || choice > 6); // Choices must be between 1 and 6
    return choice;
}
//************************************************************************************
//Function: addprod
//Function to allow the user to add a product to the vector
//************************************************************************************
void addprod(vector<Product> &bginventory) {
    Product temp;
    cout << "Enter product name, quantity, and price: ";
    cin >> temp.name; // Product name
    cin >> temp.qty;  // Product quantity
    cin >> temp.price;  // Product price
    bginventory.push_back(temp); // Adds product to vector
}
//************************************************************************************
//Function: showavgprice
//Function to calculate and display the average price of the products in the vector
//************************************************************************************
void showavgprice(const vector<Product> &bginventory) {
    if (bginventory.empty()) { // Check vector for elements
        cout << "No products in inventory.\n";
        return;
    }
    double total = 0;
    for (const auto &prod : bginventory) {
        total += prod.price;
    }
    cout << "The average price is: " << fixed << setprecision(2) << total / bginventory.size() << endl;
}
//************************************************************************************
//Function: showhiprice
//Function to display the product with the highest price
//************************************************************************************
void showhiprice(const vector<Product> &bginventory) {
    if (bginventory.empty()) { // Check vector for elements
        cout << "No products in inventory.\n";
        return;
    }
    Product highest = bginventory[0];
    for (const auto &prod : bginventory) {
        if (prod.price > highest.price) {
            highest = prod;
        }
    }
    cout << "The highest price is: " << highest.name << " | " << highest.price << endl;
}
//************************************************************************************
//Function: showoutofstock
//Function to display the products with a quantity of zero
//************************************************************************************
void showoutofstock(const vector<Product> &bginventory) {
    if (bginventory.empty()) { // Check vector for elements
        cout << "No products in inventory.\n";
        return;
    }
    bool hasOutofStockItems = false;
    cout << setw(2) << "##" << setw(7) << "Name" << setw(14) << "Qty" << setw(17) << "Price" << endl;
    cout << setw(2) << "--" << setw(7) << "----" << setw(14) << "---" << setw(17) << "-----" << endl;
    int index = 1;
    for (const auto &prod : bginventory) {
        if (prod.qty == 0) {
            cout << setw(5) << left << index++ << setw(15) << prod.name << setw(15) << prod.qty << prod.price << endl;
            hasOutofStockItems = true;
        }
    }
    if (!hasOutofStockItems) {
        cout << "There are no out of stock products.\n";
    }
}
//************************************************************************************
//Function: showinventory
//Function to display the inventory of all products
//************************************************************************************
void showinventory(const vector<Product> &bginventory) {
    if (bginventory.empty()) { // Check vector for elements
        cout << "No products in inventory.\n";
        return;
    }
    else {
        cout << setw(2) << "##" << setw(7) << "Name" << setw(14) << "Qty" << setw(17) << "Price" << endl;
        cout << setw(2) << "--" << setw(7) << "----" << setw(14) << "---" << setw(17) << "-----" << endl;
        int index = 1;
        for (const auto &prod : bginventory) {
            cout << setw(5) << left << index++ << setw(15) << prod.name << setw(15) << prod.qty << prod.price << endl;
        }
    }
}
