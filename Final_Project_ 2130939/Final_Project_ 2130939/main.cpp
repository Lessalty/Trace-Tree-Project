#include <iostream>
#include "ContactTree.h"

using namespace std;

void displayMenu() {
    cout << "\n--- Contact Tracing Tree Menu ---\n";
    cout << "1. Add Patient Zero\n";
    cout << "2. Add Contact\n";
    cout << "3. Display All Contacts\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    ContactTree tree;
    int choice;
    string id, parentId;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter ID for Patient Zero: ";
            cin >> id;
            tree.AddPatientZero(id);
            cout << "Patient Zero added.\n";
            break;

        case 2:
            cout << "Enter Parent ID: ";
            cin >> parentId;
            cout << "Enter New Contact ID: ";
            cin >> id;
            if (tree.AddContact(parentId, id)) {
                cout << "Contact added successfully.\n";
            }
            else {
                cout << "Failed to add contact. Check if the Parent ID exists.\n";
            }
            break;

        case 3:
            cout << "Current Contact Tree:\n";
            tree.PrintContactTree();
            break;

        case 4:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
