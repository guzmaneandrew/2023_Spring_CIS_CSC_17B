/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Cart.h
 * Author: andrewguzman
 *
 * Created on May 4, 2023, 12:10 AM
 */

#ifndef CART_H
#define CART_H

#include "Item.h"

class Cart {
private:
    vector<Item *> items;
    int numItems;
public:

    Cart() {
        numItems = 0;
    }

    ~Cart() {
        for (int i = 0; i < items.size(); i++) {
            delete items[i];
        }
    }

    int getNumItms() const {
        return numItems;
    }

    vector<Item *> getItems() const {
        return items;
    }

    Item *getItem(int i) const {
        return items[i];
    }

    void clearItems() {
        for (int i = 0; i < items.size(); i++) {
            delete items[i];
        }
        items.clear();
    }

    void setItem(Item *item) {
        items.push_back(item);
        numItems++;
    }

    void setItems(vector<Item *> items) {
        this->items = items;
    }

    void setNumItems(int n) {
        numItems = n;
    }

    void setNumItems() {
        numItems = items.size();
    }

    void display() const {
        int num = 1;
        float total = 0.0;

        for (int i = 0; i < numItems; i++) {
            cout << fixed << setprecision(2);
            total += items[i]->getPrice();
            cout << num++ << ") " << endl;
            cout << "Item: " << items[i]->getName() << endl;
            cout << "Price: $" << items[i]->getPrice() << endl;
            cout << endl;
        }

        cout << "Total: $" << total << endl;
    }

    void deleteItem(int i) {
        int index = --i;
        if (index >= 0 && index < items.size()) {
            numItems--;
            delete items[index];
            items.erase(items.begin() + index);
        } else {
            cout << "ERROR: Invalid Item Number." << endl;
        }
    }

    void saveBin(string file) {
        fstream storeDB(file, ios::out | ios::binary | ios::app);

        if (!storeDB) {
            cerr << "Error: Unable to Open File for Writing." << endl;
            return;
        }

        //Write number of items to binary file
        storeDB.write(reinterpret_cast<char *> (&numItems), sizeof (int));

        //Write each item info to binary file
        for (int i = 0; i < numItems; i++) {
            string name;
            float price;
            int numStck;

            name = items[i]->getName();
            price = items[i]->getPrice();
            numStck = items[i]->getStock();

            int len = name.length();
            storeDB.write(reinterpret_cast<char *> (&len), sizeof (int));
            storeDB.write(name.c_str(), len);
            storeDB.write(reinterpret_cast<char *> (&price), sizeof (float));
            storeDB.write(reinterpret_cast<char *> (&numStck), sizeof (int));
        }
        storeDB.close();
    }

//    void saveItem2Bin(string file,Item *item) {
//        fstream storeDB(file, ios::out | ios::binary | ios::app);
//
//        if (!storeDB) {
//            cerr << "Error: Unable to Open File for Writing." << endl;
//            return;
//        }
//
//        string name;
//        float price;
//        int numStck;
//
//        name = item->getName();
//        price = item->getPrice();
//        numStck = item->getStock();
//
//        int len = name.length();
//        storeDB.write(reinterpret_cast<char *> (&len), sizeof (int));
//        storeDB.write(name.c_str(), len);
//        storeDB.write(reinterpret_cast<char *> (&price), sizeof (float));
//        storeDB.write(reinterpret_cast<char *> (&numStck), sizeof (int));
//        storeDB.close();
//    }

    void readBin(string file) {
        //Clear items from vector
        items.clear();

        fstream storeDB(file, ios::in | ios::binary);

        if (!storeDB) {
            cerr << "Error: Unable to Open File for Writing." << endl;
            return;
        }

        //Read number of items from binary file
        int num;
        storeDB.read(reinterpret_cast<char *> (&num), sizeof (int));

        //Read each of the item's properties in the file
        for (int i = 0; i < num; i++) {
            int len;
            string name;
            float price;
            int numStck;

            storeDB.read(reinterpret_cast<char *> (&len), sizeof (int));
            name.resize(len);
            storeDB.read(&name[0], len);
            storeDB.read(reinterpret_cast<char *> (&price), sizeof (float));
            storeDB.read(reinterpret_cast<char *> (&numStck), sizeof (int));

            //Create new Item object and set it's properties
            Item *newItem = new Item(name, price, numStck);
            items.push_back(newItem);
        }

        //Create new Cart object, set the items, and display
        Cart *cart = new Cart();
        cart->setItems(items);
        cart->setNumItems(num);
        cart->display();

        storeDB.close();
    }
};

#endif /* CART_H */

