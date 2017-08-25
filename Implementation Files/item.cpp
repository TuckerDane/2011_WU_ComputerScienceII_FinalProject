#include <iostream>
#include "item.h"
using namespace std;

Item::Item()
{
	name = "nothing";
}

string Item::getName()
{
    return name;
}

void Item::setName(string newName)
{
    name = newName;
}
