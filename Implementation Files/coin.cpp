#include <iostream>
#include "coin.h"

//create new coin
coin::coin(double v)
{
	value = v;
}

//returns value of coin
double coin::getValue()
{
	return value;
}
