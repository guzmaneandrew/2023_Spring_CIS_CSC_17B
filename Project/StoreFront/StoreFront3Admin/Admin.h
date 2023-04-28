/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Admin.h
 * Author: andrewguzman
 *
 * Created on April 18, 2023, 2:08 PM
 */

#ifndef ADMIN_H
#define ADMIN_H

#include "Store.h"

struct AdminInfo {
    char username[10];
    char password[12];
};

class Admin {
private:
    AdminInfo info;
    Store *store;
public:

    Admin(string name, string pass) {
        strcpy(info.username, name.c_str());
        strcpy(info.password, pass.c_str());
        store = new Store();

        int choice;
        do {
            cout << endl << "Hello Admin, " << info.username << endl;
            cout << " 1) Add New Items" << endl;
            cout << " 2) View Items" << endl;
            cout << " 3) View Items Currently In Stock" << endl;
            cout << " 4) View Items No Longer In Stock" << endl;
            cout << " 5) Update an Item" << endl;
            cout << " 6) List Users" << endl;
            cout << " 7) List Admins" << endl;
            cout << " 8) Add Admins" << endl;
            cout << "-99) Delete All Items" << endl;
            cout << "-1) Logout" << endl;
            cin>>choice;
            cin.ignore();
            if (choice == 1) {
                addItems();
            } else if (choice == 2) {
                viewItms();
            } else if (choice == 3) {
                viewItmsInStck();
            } else if (choice == 4) {
                viewItmsNotInStck();
            } else if (choice == 5) {
                updtItem();
            } else if (choice == 6) {
                listUsrs();
            } else if (choice == 7) {
                listAdmins();
            } else if (choice == 8) {
                addAdmin();
            } else if (choice == -99) {
                deleteAll();
            }

        } while (choice != -1);
    }

    ~Admin() {
        delete store;
    }

    void addItems() {
        //Create items and add to item DB
        int num;

        cout << "ADD ITEMS" << endl;
        cout << "Enter Number of Items: ";
        cin>>num;
        cin.ignore();

        //Create items and add to store items vector
        for (int i = 0; i < num; i++) {
            store->newItem();
        }
        reloadItms("Store.dat");
        store->display();
    }

    void viewItms() {
        int num = 1; //number in list of items

        store->clearItems();
        readBin("Store.dat");

        cout << endl << "ALL STORE ITEMS" << endl;
        if (store->getNumItms() == 0) {
            cout << "No Items to Retrieve from the Database." << endl;
        } else {
            store->display();
        }
    }

    void viewItmsInStck() {
        bool none = true;
        int num = 1; //number in the list and number of items in stock

        store->clearItems();
        readBin("Store.dat");

        cout << endl << "STORE ITEMS CURRENTLY IN STOCK" << endl;
        if (store->getNumItms() == 0) {
            cout << "No Items to Retrieve from the Database." << endl;
        } else {
            for (int i = 0; i < store->getNumItms(); i++) {
                if (store->getItem(i)->getStock() != 0) {
                    cout << num++ << ") " << endl;
                    store->getItem(i)->display();
                    none = false;
                }
            }
            if (none == true) {
                cout << "- - - - - - None - - - - - -" << endl;
            } else {
                cout << "Total Items in Stock: " << --num << "/" << store->getNumItms() << endl;
            }
        }
    }

    void viewItmsNotInStck() {
        bool none = true;
        int num = 1; //number in the list and number of items in stock

        store->clearItems();
        readBin("Store.dat");

        cout << endl << "STORE ITEMS CURRENTLY NOT IN STOCK" << endl;
        if (store->getNumItms() == 0) {
            cout << "No Items to Retrieve from the Database." << endl;
        } else {
            for (int i = 0; i < store->getNumItms(); i++) {
                if (store->getItem(i)->getStock() == 0) {
                    cout << num++ << ") " << endl;
                    store->getItem(i)->display();
                    none = false;
                }
            }
            if (none == true) {
                cout << "- - - - - - None - - - - - -" << endl;
            } else {
                cout << "Total Items Not in Stock: " << --num << "/" << store->getNumItms() << endl;
            }
        }
    }

    void updtItem() {

    }

    void listUsrs() {

    }

    void listAdmins() {

    }

    void addAdmin() {

    }

    void deleteAll() {
        clearBin("Store.dat");
        store->clearItems();
        cout << endl << "All Items Have Been Deleted from Store" << endl;
    }

    void readBin(string file) {
        store->clearItems();

        fstream db(file, ios::in | ios::binary);
        if (!db) {
            cerr << "ERROR: Unable to Open File for Reading." << endl;
            return;
        }

        //Use cursor to get size of file to read entire file
        db.seekg(0, ios::end);
        int size = db.tellg();
        db.seekg(0, ios::beg);

        vector<Item *> items;
        int numItms;
        //Read in item information until size of file reached
        while (db.tellg() < size) {
            //Read number of items
            db.read(reinterpret_cast<char *> (&numItms), sizeof (int));
            for (int i = 0; i < numItms; i++) {
                int len;
                string name;
                float price;
                int numStck;

                db.read(reinterpret_cast<char *> (&len), sizeof (int));
                name.resize(len);
                db.read(&name[0], len);
                db.read(reinterpret_cast<char *> (&price), sizeof (float));
                db.read(reinterpret_cast<char *> (&numStck), sizeof (int));

                //Create new Item object and set it's properties
                Item *newItem = new Item(name, price, numStck);
                items.push_back(newItem);
            }

        }
        //Set store items vector
        store->setItems(items);
        store->setNumItems(numItms);
        db.close();
    }

    void clearBin(string file) {
        //Deletes all contents of the binary file
        ofstream DB(file, ios::out | ios::trunc);
        DB.close();
    }

    void reloadItms(string file) {
        //Clear binary file, output vector to binary, then read from binary
        clearBin(file);

        store->saveBin(file);

        readBin(file);
    }
};

#endif /* ADMIN_H */

