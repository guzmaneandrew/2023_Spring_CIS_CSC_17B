/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "Headers.h"

Item::Item() {
}

Item::Item(string name, float price, int stock) {
    this->name = name;
    this->price = price;
    numStock = stock;
}

void Item::setName(string name) {
    this->name = name;
}

void Item::setPrice(float price) {
    this->price = price;
}

void Item::setStock(int s) {
    numStock = s;
}

string Item::getName() const {
    return name;
}

float Item::getPrice() const {
    return price;
}

int Item::getStock() const {
    return numStock;
}

void Item::display() const {
    cout << right << setw(10) << "Item: " << left << setw(20) << name << endl;
    cout << right << setw(10) << "Price: " << left << fixed << setprecision(2)
            << "$" << price << "/each" << endl;
    cout << right << setw(10) << "In Stock: " << left << setw(20) << numStock << endl;
    cout << endl;
}