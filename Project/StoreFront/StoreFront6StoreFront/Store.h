/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Store.h
 * Author: andrewguzman
 *
 * Created on April 17, 2023, 2:04 AM
 */

#ifndef STORE_H
#define STORE_H
#include "Headers.h"

class Store {
private:
    vector<Item *> items;
    int numItems;
public:

    Store() {
        numItems = 0;
    }

    ~Store() {
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

    void setItem(string n, float p, int s) {
        Item *newItem = new Item(n, p, s);
        items.push_back(newItem);
        numItems++;
    }

    void setItems(int num) {
        numItems = num;
        for (int i = 0; i < num; i++) {
            newItem();
        }
    }

    void setItems(vector<Item *> items) {
        this->items = items;
    }

    void setNumItems(int n) {
        numItems=n;
    }

    void setNumItems() {
        numItems = items.size();
    }

    void display() const {
        int num = 1;

        for (int i = 0; i < items.size(); i++) {
            cout << num++ << ") " << endl;
            items[i]->display();
        }
    }

    void newItem() {
        //Receive input for new item
        string name;
        float price;
        int stock;

        cout << "Item Name: ";
        getline(cin, name);

        cout << "Item Price: $";
        cin>>price;
        cin.ignore();

        cout << "Number in Stock: ";
        cin>>stock;
        cin.ignore();

        setItem(name,price,stock);
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

        //Create new Store object, set the items, and display
        Store *store = new Store();
        store->setItems(items);
        store->setNumItems(num);
        store->display();

        storeDB.close();
    }
};


#endif /* STORE_H */

