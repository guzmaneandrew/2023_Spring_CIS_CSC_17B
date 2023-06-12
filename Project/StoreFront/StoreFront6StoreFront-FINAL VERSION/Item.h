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

    Item();

    Item(string, float, int);
    
    void setName(string);

    void setPrice(float);

    void setStock(int s);

    string getName() const;

    float getPrice() const;

    int getStock() const;
    
    void display() const;
};

#endif /* QUESTION_H */