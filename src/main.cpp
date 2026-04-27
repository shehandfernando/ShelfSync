#include <iostream>
#include <iomanip>
#include "DatabaseManager.h"

using namespace std;

void displayMenu() {
    cout << "\n=== ShelfSync Core Menu ===\n";
    cout << "1. View Inventory\n2. Add Book\n3. Process Sale\n4. Exit\nChoice: ";
}

int main() {
    // Initialize OOP Database Manager with the new name
    DatabaseManager dbManager("shelfsync.db");
    dbManager.initializeDatabase();

    cout << "System Boot: Database Connected.\n";
    
    string user, pass;
    cout << "Username: "; cin >> user;
    cout << "Password: "; cin >> pass;

    if (!dbManager.authenticate(user, pass)) {
        cout << "Authentication failed. Exiting.\n";
        return 1;
    }

    int choice;
    do {
        displayMenu();
        if (!(cin >> choice)) { cin.clear(); cin.ignore(10000, '\n'); continue; }

        if (choice == 1) {
            auto books = dbManager.getAllBooks();
            cout << left << setw(5) << "ID" << setw(20) << "Title" << setw(10) << "Price" << "Qty\n";
            for (const auto& b : books) {
                cout << left << setw(5) << b.id << setw(20) << b.title << "$" << setw(9) << b.price << b.quantity << "\n";
            }
        } else if (choice == 2) {
            Book b;
            cout << "ID: "; cin >> b.id;
            cout << "Title: "; cin >> b.title;
            cout << "Author: "; cin >> b.author;
            cout << "Price: "; cin >> b.price;
            cout << "Quantity: "; cin >> b.quantity;
            dbManager.addBook(b);
        } else if (choice == 3) {
            int id, qty;
            cout << "Book ID: "; cin >> id;
            cout << "Qty to Sell: "; cin >> qty;
            dbManager.processSale(id, qty);
        }
    } while (choice != 4);

    cout << "ShelfSync shutting down safely.\n";
    return 0;
}