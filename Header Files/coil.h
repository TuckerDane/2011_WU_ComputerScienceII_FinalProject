#include "item.h"
#include <iostream>
#include <stack>
#include <vector>
#pragma once
using namespace std;

class coil													// coil: WHERE ITEMS ARE STORED IN A VENDING MACHINE
{
private:
    double price;											// holds the price items contained in the coil
    Item item;												// items contained in the coil
	stack <Item> coilstack;									// a stack of items called coilstack
public:
	coil();													// constructor
	bool empty();											// tells wether or not coilstack is empty
    double getPrice();										// returns the current price of the coil
    string getItemName();									// gets the name of the items stored in the coilstack
    void popItem();											// pops an item off of coilstack
    void setPrice(double newPrice);							// sets the price of the coil
    void stockItem(string name, int num, double price);		// stocks an item into the coil using push_back()
	int getStackSize();										// returns the number of items in coilstack
};