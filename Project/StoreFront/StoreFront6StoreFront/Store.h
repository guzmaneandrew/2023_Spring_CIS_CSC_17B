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

    Store();

    ~Store();

    int getNumItms() const;

    vector<Item *> getItems() const;

    Item *getItem(int i) const;

    void clearItems();

    void setItem(string, float, int);

    void setItems(int);

    void setItems(vector<Item *>);

    void setNumItems(int);

    void setNumItems();

    void display() const;

    void newItem();

    void deleteItem(int);

    void saveBin(string);
    
    void readBin(string);
};


#endif /* STORE_H */

