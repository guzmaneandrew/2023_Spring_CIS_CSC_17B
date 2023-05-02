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
            cout << " 2) List Items" << endl;
            cout << " 3) List Items Currently In Stock" << endl;
            cout << " 4) List Items No Longer In Stock" << endl;
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
                listItms();
            } else if (choice == 3) {
                listItmsInStck();
            } else if (choice == 4) {
                listItmsNotInStck();
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
            cout << i << endl;
            store->newItem();
        }
        reloadItms("Store.dat");
        //        store->display();
    }

    void listItms() {
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

    void listItmsInStck() {
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

    void listItmsNotInStck() {
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
        Item *itm2updt;
        int choice;
        string itmName;
        bool valid; //Flag to check if item name is valid

        cout << endl << "UPDATE ITEM" << endl;

        //List all items(also reloads items from binary file)
        listItms();

        if (store->getNumItms() != 0) {
            //If items in DB, prompt for which to update
            do {
                cout << "Enter Name of Item to Update: ";
                getline(cin, itmName);

                //Search for item name in items vector
                for (int i = 0; i < store->getNumItms(); i++) {
                    if (store->getItem(i)->getName() == itmName) {
                        itm2updt = store->getItem(i);
                        valid = true;
                    }
                }

            } while (valid == false);

            //Display item to be updated
            itm2updt->display();

            do { //Print menu
                cout << "Enter What You Would Like to Update for This Item" << endl;
                cout << " 1) Name" << endl;
                cout << " 2) Price" << endl;
                cout << " 3) Number in Stock" << endl;
                cout << " 0) Cancel Item Updates " << endl;

                cin>>choice;
                cin.ignore();
                switch (choice) {
                    case 1:
                        cout << endl << "UPDATE NAME" << endl;
                        updtName(itm2updt);
                        break;
                    case 2:
                        cout << endl << "UPDATE PRICE" << endl;
                        updtPrice(itm2updt);
                        break;
                    case 3:
                        cout << endl << "UPDATE NUMBER IN STOCK" << endl;
                        updtNumStk(itm2updt);
                        break;
                    case 0:
                        cout << endl << "CANCEL SURVEY UPDATES" << endl;
                        break;
                    default:
                        cout << endl << "You picked an invalid option" << endl;
                        break;
                }
            } while (choice != 0);

            store->display();
            reloadItms("Store.dat");
        }

    }

    void updtName(Item *item) {
        string newName;

        cout << "Enter New Name: ";
        getline(cin, newName);
        item->setName(newName);

        item->display();
    }

    void updtPrice(Item *item) {
        float newPrice;

        cout << "Enter New Price: ";
        cin>>newPrice;
        item->setPrice(newPrice);
    }

    void updtNumStk(Item *item) {
        int newStk;

        cout << "Enter New Number in Stock: ";
        cin>>newStk;
        item->setStock(newStk);
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

    void saveBin(string file) {
        fstream storeDB(file, ios::out | ios::binary | ios::app);

        if (!storeDB) {
            cerr << "Error: Unable to Open File for Writing." << endl;
            return;
        }

        int numItms = store->getNumItms();

        //Write number of items to binary file
        storeDB.write(reinterpret_cast<char *> (&numItms), sizeof (int));

        //Write each item info to binary file
        for (int i = 0; i < store->getNumItms(); i++) {
            string name;
            float price;
            int numStck;

            name = store->getItem(i)->getName();
            price = store->getItem(i)->getPrice();
            numStck = store->getItem(i)->getStock();

            int len = name.length();
            storeDB.write(reinterpret_cast<char *> (&len), sizeof (int));
            storeDB.write(name.c_str(), len);
            storeDB.write(reinterpret_cast<char *> (&price), sizeof (float));
            storeDB.write(reinterpret_cast<char *> (&numStck), sizeof (int));
        }
        storeDB.close();
    }

    void readBin(string file) {
        store->clearItems();

        fstream db(file, ios::in | ios::binary);

        if (!db) {
            cerr << "ERROR: Unable to Open File for Reading." << endl;
            return;
        }

        //Read number of items from binary file
        vector<Item *> items;
        int numItms;
        db.read(reinterpret_cast<char *> (&numItms), sizeof (int));

        //Read each of the item's properties in the file
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