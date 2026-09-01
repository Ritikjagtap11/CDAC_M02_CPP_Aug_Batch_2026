//============================================================================
// Name        : 1_Inventory_Management_System.cpp
// Author      : Ritik
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

class Product {

    int productId;
    string name;
    double price;
    int quantity;

public:

    void acceptDetails(int productId, string name, double price, int quantity) {

        this->productId = productId;
        this->name = name;
        this->price = price;
        this->quantity = quantity;
    }

    double totalValue() const {
        return price * quantity;
    }

    bool isLowStock(int threshold) const {

        if (quantity < threshold) {
            return true;
        }

        return false;
    }

    void displayDetails() const {

        cout << productId << "\t"
             << name << "\t"
             << fixed << setprecision(2) << price << "\t"
             << quantity << "\t"
             << totalValue()
             << endl;
    }

    string getName() const {
        return name;
    }
};

int main1() {

    Product arr[5];

    int size = sizeof(arr) / sizeof(arr[0]);

    // Accept details
    for (int i = 0; i < size; i++) {

        int productId;
        string name;
        double price;
        int quantity;

        cout << "\nEnter details for Product " << i + 1 << endl;

        cout << "Product ID: ";
        cin >> productId;

        cout << "Name: ";
        cin >> name;

        cout << "Price: ";
        cin >> price;

        cout << "Quantity: ";
        cin >> quantity;

        arr[i].acceptDetails(productId, name, price, quantity);
    }

    // Display inventory
    cout << "\n===== INVENTORY REPORT =====" << endl;

    cout << "ID\tName\tPrice\tQty\tTotal Value" << endl;

    for (int i = 0; i < size; i++) {
        arr[i].displayDetails();
    }

    // Find highest value product
    int highIndex = 0;

    for (int i = 1; i < size; i++) {

        if (arr[i].totalValue() > arr[highIndex].totalValue()) {
            highIndex = i;
        }
    }

    cout << "\nHighest Value Product : "
         << arr[highIndex].getName()
         << " (Rs. "
         << fixed << setprecision(2)
         << arr[highIndex].totalValue()
         << ")" << endl;


    // Low stock threshold
    int threshold;

    cout << "\nEnter Low Stock Threshold: ";
    cin >> threshold;

    cout << "Low Stock (threshold: " << threshold << ") : ";

    bool found = false;

    for (int i = 0; i < size; i++) {

        if (arr[i].isLowStock(threshold)) {

            if (found) {
                cout << ", ";
            }

            cout << arr[i].getName();

            found = true;
        }
    }

    if (!found) {
        cout << "None";
    }

    cout << endl;

    return 0;
}
