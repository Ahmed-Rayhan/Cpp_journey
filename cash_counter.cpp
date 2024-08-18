#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // items and their prices
    const int numItems = 5;
    string items[numItems] = {"Apple", "Banana", "Milk", "Bread", "Eggs"};
    float prices[numItems] = {1.50, 1.00, 3.00, 2.00, 1.50}; // Prices in dollars

    int quantities[numItems];
    float totalPrice = 0.0;
    const float VAT_RATE = 0.15; // 15% VAT

    // Display available items
    cout << "Welcome to My Store !" << endl;
    cout << "Here are the available items:" << endl;
    for (int i = 0; i < numItems; i++) {
        cout << i + 1 << ". " << items[i] << " - $" << fixed << setprecision(2) << prices[i] << " each" << endl;
    }

    // Get quantities from user
    cout << "\nEnter the quantity for each item:" << endl;
    for (int i = 0; i < numItems; i++) {
        cout << items[i] << ": ";
        cin >> quantities[i];
        totalPrice += quantities[i] * prices[i];
    }

    // Calculate VAT and total price
    float vat = totalPrice * VAT_RATE;
    float finalPrice = totalPrice + vat;

    // Display the final price
    cout << "\nTotal Price: $" << fixed << setprecision(2) << totalPrice << endl;
    cout << "VAT (15%): $" << vat << endl;
    cout << "Final Price (including VAT): $" << finalPrice << endl;

    return 0;
}
