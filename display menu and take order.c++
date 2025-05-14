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