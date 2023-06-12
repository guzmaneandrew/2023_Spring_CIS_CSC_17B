/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   User.h
 * Author: andrewguzman
 *
 * Created on May 2, 2023, 11:32 AM
 */

#ifndef USER_H
#define USER_H

#include "Headers.h"

struct UserInfo {
    char username[11];
    char password[13];
    bool status;
};

class User {
private:
    UserInfo info;
    Store *store;
    Cart *cart;
    string usrCartFile;
public:

    User() {
        strcpy(info.username, " ");
        strcpy(info.password, " ");
        info.status = true;
    }

    void prompt() {
        int choice;
        do {
            cout << endl << "Hello User, " << info.username << endl;
            cout << "  1) List All Store Items" << endl;
            cout << "  2) List Store Items Currently In Stock" << endl;
            cout << "  3) List Store Items Currently Not In Stock" << endl;
            cout << "  4) View Cart" << endl;
            cout << "  5) Add Items to Cart" << endl;
            cout << "  6) Delete Items From Cart" << endl;
            cout << "-99) Delete All Items From Cart" << endl;
            cout << "- 1) Logout" << endl;
            cin>>choice;
            cin.ignore();
            if (choice == 1) {
                listItms();
            } else if (choice == 2) {
                listItmsInStck();
            } else if (choice == 3) {
                listItmsNotInStck();
            } else if (choice == 4) {
                listItmsInCart();
            } else if (choice == 5) {
                addItems();
            } else if (choice == 6) {

                if (info.status == false) return; //logout if account was deactivated
            } else if (choice == 99) {

            }

        } while (choice != -1);
    }

    void setUsrInfo(string name, string pass) {
        strcpy(info.username, name.c_str());
        strcpy(info.password, pass.c_str());
        info.status = true;
        usrCartFile = string(info.username) + "Cart.dat";
    }

    void listItms() {
        int num = 1; //number in list of items

        readStoreBin("Store.dat");

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

        readStoreBin("Store.dat");

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

        readStoreBin("Store.dat");

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

    void listItmsInCart() {
        int num = 1; //number in list of items

        cout << endl << "ALL CART ITEMS" << endl;
        if (cart->getNumItms() == 0) {
            cout << "No Items to Retrieve from the Database." << endl;
        } else {
            cart->display();
        }
    }

    void addItems() {
        string itmName;
        int numInStk, numReq; //num items in stock, num requested
        Item *itm2Add = nullptr;
        bool valid = false;

        listItmsInStck();
        readCartBin(usrCartFile);
        cout<<cart->getNumItms()<<endl;
        cart->display();

        do {
            //Prompt for item to add
            cout << "Enter the Item To Add to Your Cart: ";
            getline(cin, itmName);

            //Search for item in store items vector
            for (int i = 0; i < store->getNumItms(); i++) {
                if (store->getItem(i)->getName() == itmName) {
                    valid = true;
                    //Add item to cart
                    itm2Add = store->getItem(i);
                    cart->setItem(itm2Add);
                }
            }
        } while (itmName == "" || valid == false);


        //Save new cart item to file
        //        cart->saveItem2Bin(usrCartFile,itm2Add);
        //        cart->readBin(usrCartFile);
        //        cart->display();
    }

    void readStoreBin(string file) {
        fstream db(file, ios::in | ios::binary);

        if (!db) {
            cerr << "ERROR: Unable to Open File for Reading." << endl;
            return;
        }

        //Move cursor to end of file to check if file is empty
        db.seekg(0, ios::end);
        if (db.tellg() == 0) {
            db.close();
            return;
        }

        //Set the file cursor to the beginning of the file
        db.seekg(0, ios::beg);

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
        store = new Store();
        store->setItems(items);
        store->setNumItems(numItms);
        db.close();
    }

    void readCartBin(string file) {
        fstream db(file, ios::in | ios::binary);

        if (!db) {
            cerr << "ERROR: Unable to Open File for Reading." << endl;
            return;
        }

        //Move cursor to end of file to check if file is empty
        db.seekg(0, ios::end);
        if (db.tellg() == 0) {
            db.close();
            return;
        }

        //Set the file cursor to the beginning of the file
        db.seekg(0, ios::beg);

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

        //Set cart items vector
        cart = new Cart();
        cart->setItems(items);
        cart->setNumItems(numItms);
        db.close();
    }

    void clearBin(string file) {
        //Deletes all contents of the binary file
        ofstream DB(file, ios::out | ios::trunc);
        DB.close();
    }

    void reloadItms(string file) {
        //Clear binary file, output items to binary, then read from binary
        clearBin(file);
        cart->saveBin(file);
        readCartBin(file);
    }
};

#endif /* USER_H */

