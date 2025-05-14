//initialization
#include<iostream>
#include<string>
using namespace std;
string menuitems[7]=
{
    "Burger"
    "Pizza" 
    "Pasta" 
    "Fries"
    "Sandwich" 
    "Salad"
    "Ice Cream"
};
double menuprices[7]={5.99, 8.99, 7.99, 2.99, 4.49, 3.99, 1.49};
int orderitems[10];
int ordercount=0;
//display menu
void displaymenu() 
{
    cout << "\n--- Menu ---" << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << i + 1 << ". " << menuitems[i] << " - $" << menuPrices[i] << endl;
    }
}
void takeOrder()
 {
    ordercount = 0;
    char choice;
    do {
        displaymenu();
        cout << "Enter the menu item number to add to the cart: ";
        int itemnumber;
        cin >> itemnumber;
        if (itemnumber < 1 || itemnumber > 7) {
            cout << "Invalid menu item number. Please try again." << endl;
        } else {
            orderitems[ordercount] = itemnumber - 1; 
            ordercount++;
            cout << "Item added to the cart!" << endl;
        }
        if (ordercount >= 10) {
            cout << "Maximum cart size reached!" << endl;
            break;
        }
        cout << "Do you want to add another item to the cart? (y/n): ";
        cin >> choice;
    }
     while (choice == 'y' || choice == 'Y');
}
bool confirmOrder() {
    if (ordercount == 0) {
        cout << "Your cart is empty!" << endl;
        return false;
    }
    double total = 0.0;
    cout << "\n--- Your Order ---" << endl;
    for (int i = 0; i < ordercount; i++) {
        int index = orderitems[i];
        cout << i + 1 << ". " << menuitems[index] << " - $" << menuprices[index] << endl;
        total += menuprices[index];
    }
    cout << "Total: $" << total << endl;
    cout << "Do you want to confirm your order? (y/n): ";
    char choice;
    cin >> choice;
    return (choice == 'y' || choice == 'Y');
}
void displayBill() {
    if (ordercount == 0) {
        cout << "No items in your cart to bill!" << endl;
        return;
    }
    double total = 0.0;
    cout << "\n--- Final Bill ---" << endl;
    for (int i = 0; i < ordercount; i++) {
        int index = orderitems[i];
        cout << i + 1 << ". " << menuitems[index] << " - $" << menuprices[index] << endl;
        total += menuprices[index];
    }
    cout << "Total Amount: $" << total << endl;
    cout << "Thank you for your order. Enjoy your meal!" << endl;
}