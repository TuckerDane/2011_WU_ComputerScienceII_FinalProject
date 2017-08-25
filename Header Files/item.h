#include <iostream>
#pragma once
using namespace std;

class Item								// Item: BOUGHT FROM AND STORED IN VENDING MACHINES
{
private:
    string name;						// the name of the item
public:   
	Item();								// constructor
    string getName();					// returns the name of the item
    void setName(string newName);		// sets the name of the item
};
