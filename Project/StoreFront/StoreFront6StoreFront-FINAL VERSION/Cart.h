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

    Cart();

    ~Cart();

    int getNumItms() const;

    vector<Item *> getItems() const;

    Item *getItem(int i) const;

    void clearItems();

    void setItem(Item *);

    void setItems(vector<Item *>);

    void setNumItems(int);

    void setNumItems();

    void display() const;

    void deleteItem(int);

    void saveBin(string);

    void readBin(string);
};

#endif /* CART_H */

