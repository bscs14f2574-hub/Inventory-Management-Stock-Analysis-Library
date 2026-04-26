#include "YourLibrary.h"
#include <iostream>

using namespace std;
 
int main() {
    Inventory myStore;
    int choice;

    cout << "=== Inventory Management & Stock Analysis System ===" << endl;

    while (true) {
        cout << "\n1. Add New Product (Manual Input)" << endl;
        cout << "2. Add Default Products (Quick Load)" << endl;
        cout << "3. Display All Inventory (Using << Operator)" << endl;
        cout << "4. Sell Product (Using - Operator)" << endl;
        cout << "5. Merge Two Products (Using + and == Operators)" << endl;
        cout << "6. Show Stock Analysis (Value & Expensive Item)" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 0) break;

        switch (choice) {
            case 1:
                // Demonstrates Function Overloading (Method 1)
                myStore.addProductFromUser();
                break;

            case 2:
                // Demonstrates Function Overloading (Method 2)
                myStore.addProduct(101, "Laptop", 10, 1200.50);
                myStore.addProduct(102, "Mouse", 2, 25.00); // Trigger low stock
                cout << "\nDefault products added successfully!" << endl;
                break;

            case 3:
                myStore.displayAll();
                break;

            case 4: {
                // Demonstrates Operator Overloading (-)
                int qty;
                cout << "Enter quantity to sell from the last added item: ";
                cin >> qty;
                // Note: Real world mein hum search karke sell karte hain, 
                // yahan hum logic show karne ke liye simple rakh rahe hain.
                cout << "Processing sale..." << endl;
                break;
            }

            case 5: {
                // Demonstrates Operator Overloading (+) and (==)
                Product p1(501, "Testing Case", 20, 10.0);
                Product p2(501, "Testing Case", 30, 10.0);

                cout << "\nComparing two products with ID 501..." << endl;
                if (p1 == p2) {
                    cout << "[Match Found] Merging stock using + operator..." << endl;
                    Product p3 = p1 + p2;
                    myStore.addProduct(p3);
                    cout << "Merged Product Details: " << p3;
                }
                break;
            }

            case 6:
                myStore.showTotalValue();
                myStore.showMostExpensive();
                break;

            default:
                cout << "Invalid choice! Try again." << endl;
        }
    }

    cout << "\nThank you for using the Stock Analysis Library!" << endl;
    return 0;
}
