#pragma once
#include "BST_Tree.h"
#include "Hashtable.h"

// Function prototypes
void displayAdminMenu();
void addAccount(BST_Tree& tree, Hashtable& hashTable);
void deleteAccount(BST_Tree& tree, Hashtable& hashTable);
void checkAllAccounts(BST_Tree& tree);
void displayPasswords(Hashtable& hashTable);

void admin() {
    BST_Tree t;
    Hashtable h;
    int condition = 0;

    while (condition != 6) {
        displayAdminMenu();
        cin >> condition;

        switch (condition) {
        case 1:
            addAccount(t, h);
            break;

        case 2:
            deleteAccount(t, h);
            break;

        case 3:
            checkAllAccounts(t);
            break;

        case 4:
            displayPasswords(h);
            break;

        case 5:
            // Add functionality for editing an account
            break;

        case 6:
            cout << "Exiting admin panel." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }
}

void displayAdminMenu() {
    cout << "Welcome ADMIN" << endl;
    cout << "Choose an option:" << endl;
    cout << "1. Add account" << endl;
    cout << "2. Delete account" << endl;
    cout << "3. Check all accounts" << endl;
    cout << "4. See passwords of accounts" << endl;
    cout << "5. Edit account" << endl;
    cout << "6. Exit" << endl;
}

void addAccount(BST_Tree& tree, Hashtable& hashTable) {
    string n = "", a = "";
    int acc, p, b;
    cout << "Enter name     : ";
    cin >> n;
    cout << "Enter adress   : ";
    cin >> a;
    cout << "Enter account number :";
    cin >> acc;
    cout << "Enter password : ";
    cin >> p;
    cout << "Enter balance  : ";
    cin >> b;
    tree.add_Account(n, a, acc, p, b);
}

void deleteAccount(BST_Tree& tree, Hashtable& hashTable) {
    int acc = 0;
    cout << "Enter account number" << endl;
    cin >> acc;
    tree.load_Server();
    tree.Root = tree.delete_Account(tree.Root, acc);
    cout << "bar a gia delete se" << endl;
    hashTable.delete_password(acc);
    cout << "Delete pass" << endl;
    tree.update_server(tree.Root);
    cout << "update h gia" << endl;
}

void checkAllAccounts(BST_Tree& tree) {
    tree.load_Server();
    tree.printoinfo(tree.Root);
}

void displayPasswords(Hashtable& hashTable) {
    hashTable.displayPasswords();
}
