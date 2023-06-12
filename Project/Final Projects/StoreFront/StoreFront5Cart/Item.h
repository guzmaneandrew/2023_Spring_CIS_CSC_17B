/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Item.h
 * Author: andrewguzman
 *
 * Created on April 8, 2023, 10:20 PM
 */
#ifndef ITEM_H
#define ITEM_H
#include "Headers.h"

class Item {
private:
    string name;
    float price;
    int numStock;
public:

    Item() {
    }

    Item(string name, float price, int stock) {
        this->name = name;
        this->price = price;
        numStock = stock;
    }
    
    void setName(string name) {
        this->name = name;
    }

    void setPrice(float price) {
        this->price = price;
    }

    void setStock(int s) {
        numStock = s;
    }

    string getName() const {
        return name;
    }

    float getPrice() const {
        return price;
    }

    int getStock() const {
        return numStock;
    }

    void display() const {
        cout << right << setw(10) << "Item: " << left << setw(20) << name << endl;
        cout << right << setw(10) << "Price: " << left << fixed << setprecision(2) 
                << "$"<< price << "/each" << endl;
        cout << right << setw(10) << "In Stock: " << left << setw(20) << numStock << endl;
        cout<<endl;
    }
};

#endif /* QUESTION_H */