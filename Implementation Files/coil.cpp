#include "coil.h"
#include <iostream>
#pragma once

using namespace std;

	coil::coil()
	{
		price = 0.0;
	}

    double coil::getPrice()
    {
        return price;
    }

    string coil::getItemName()
    {
        return item.getName();
    }

    void coil::popItem()
    {
        coilstack.pop();
    }

    void coil::setPrice(double newPrice)
    {
        price = newPrice;
    }

    void coil::stockItem(string name, int num, double price)
    {	
		setPrice(price);
		item.setName(name);

		for (int i = 0; i < num; i++)
		{
			coilstack.push(item);
		}
    }

	bool coil::empty()
	{
		if (coilstack.size() == 0)
			return true;
		else
			return false;
	}

	int coil::getStackSize()
	{
		return coilstack.size();
	}

