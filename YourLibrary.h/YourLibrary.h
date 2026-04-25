#ifndef YOUR_LIBRARY_H
#define YOUR_LIBRARY_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Product {
private:
    int id;
    string name;
    int quantity;
    float price;

public:
    // --- Function Overloading (Constructors) ---
    Product() : id(0), name("Unknown"), quantity(0), price(0.0) {}

    Product(int i, string n, int q, float p) : id(i), name(n), quantity(q), price(p) {}

    // Copy Constructor (Requirement fulfilled)
    Product(const Product &p) {
        id = p.id; name = p.name; quantity = p.quantity; price = p.price;
    }

    // --- Operator Overloading ---
    // 1. Combine Stock
    Product operator+(const Product &p) {
        Product temp = *this;
        temp.quantity += p.quantity;
        return temp;
    }

    // 2. Sell Product (Arithmetic)
    Product operator-(int soldQty) {
        Product temp = *this;
        if (temp.quantity >= soldQty) 
            temp.quantity -= soldQty;
        else 
            cout << "\n[!] Not enough stock to sell " << soldQty << " units.\n";
        return temp;
    }

    // 3. Comparison (By ID)
    bool operator==(const Product &p) const { return (id == p.id); }

    // 4. Display (Friend Function)
    friend ostream& operator<<(ostream &out, const Product &p) {
        out << "ID: " << p.id << " | Name: " << p.name
            << " | Qty: " << p.quantity << " | Price: $" << p.price;
        if (p.quantity < 5) out << " [LOW STOCK ALERT!]";
        out << endl;
        return out;
    }

    // Getters
    int getQuantity() const { return quantity; }
    float getPrice() const { return price; }
    int getId() const { return id; }
};

class Inventory {
private:
    vector<Product> products;

public:
    // --- Function Overloading for adding products ---
    void addProduct(Product p) { products.push_back(p); }

    void addProduct(int id, string name, int qty, float price) {
        products.push_back(Product(id, name, qty, price));
    }

    // Interactive Input (No Hardcoding)
    void addProductFromUser() {
        int id, qty; string name; float price;
        cout << "Enter ID: "; cin >> id;
        cout << "Enter Name: "; cin.ignore(); getline(cin, name);
        cout << "Enter Quantity: "; cin >> qty;
        cout << "Enter Price: "; cin >> price;
        products.push_back(Product(id, name, qty, price));
    }

    void displayAll() {
        if(products.empty()) { cout << "\nInventory is empty.\n"; return; }
        cout << "\n========== CURRENT INVENTORY ==========\n";
        for (const auto &p : products) cout << p;
    }

    // Analysis Methods
    void showTotalValue() {
        float total = 0;
        for (const auto &p : products) total += (p.getQuantity() * p.getPrice());
        cout << "\n>>> Total Inventory Value: $" << total << endl;
    }

    void showMostExpensive() {
        if (products.empty()) return;
        Product maxP = products[0];
        for (const auto &p : products) 
            if (p.getPrice() > maxP.getPrice()) maxP = p;
        cout << "\nMost Expensive Item:\n" << maxP;
    }
};

#endif