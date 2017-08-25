#include <iostream>
#include <string>
#include "cashBox.h"

//objects of coins
coin penny(0.01);
coin nickel(0.05);
coin dime(0.1);
coin quarter(0.25);
coin dollar(1.0);
coin fiveHundredDollarBill(500.00);			// cheat codes for developers
coin hundredThousandDollars(100000.00);		// cheat codes for developers

//cash box constructor
cashBox::cashBox(double cash)
{
	this -> cash = cash;
	tempCash = 0;
}

//RESTOCK MODE: returns how much money is currently in the cash box without altering this value
double cashBox::getCash()
{
	return cash;
}

//RESTOCK MODE: add money to cash box
void cashBox::addCash(double amount)
{
	cash += amount;
}

//RESTOCK MODE: returns amount of cash removed from cash box, and adjusts amount in cash box depending on what was taken out
double cashBox::removeCash(double amount)
{
	cash -= amount;

	return amount;
}

//RESTOCK MODE: returns how much money was in the cash box and emptys the cash box
double cashBox::emptyCash()
{
	double temp = cash;
	cash = 0;

	return temp;
}

//VENDING MODE: displays contents of tempCash to user making purchase
void cashBox::displayTempCash()
{
	cout << "You have inserted: $" << tempCash << endl;
}

//VENDING MODE: returns tempCash
double cashBox::getTempCash()
{
	return tempCash;
}

//VENDING MODE: interface for the user to insert money
void cashBox::addCoin()
{
	string user;

		cout << "p= Penny" << endl << "n= Nickel" << endl << "d= Dime" << endl << "q= Quarter" << endl << "D= Dollar Coin" << endl;
		cout << "r= coin return" << endl << "0= end payment" << endl;
	
	do{
		cout << endl << "Enter a corresponding letter to perform desired action: ";
		cin >> user;
		cout << endl;

		if(user.size() != 1)
		{
			cout << "Invalid coin. Please try again." << endl;
			continue;
		}

		switch(user[0])
		{
			case 'p': 
				addTempCash(penny);
				break;
			case 'n':
				addTempCash(nickel);
				break;
			case 'd':
				addTempCash(dime);
				break;
			case 'q':
				addTempCash(quarter);
				break;
			case 'D':
				addTempCash(dollar);
				break;
			case 'f':
				addTempCash(fiveHundredDollarBill);
				break;
			case 'h':
				addTempCash(hundredThousandDollars);
				break;
			case '0':
				break;
			case 'r':
				cout << "The vending machine dispensed $" << tempCashReturn() << " in coin return." << endl;
				break;
			default:
				cout << "Not a valid choice." << endl;
				break;
		}
	} while(user[0] != '0' && user[0] != 'r');

	cout << endl;
}

//VENDING MODE: add money to tempCash as user inserts coins
void cashBox::addTempCash(coin COIN)
{
	tempCash += COIN.getValue();
	displayTempCash();
}

//VENDING MODE: emptys tempCash and returns money to user
double cashBox::tempCashReturn()
{
	double temp = tempCash;
	tempCash = 0;

	return temp;
}

//VENDING MODE: carrys out a trasaction
double cashBox::transaction(coil COIL)
{
	double change;	
	
	change = tempCash - COIL.getPrice();
	addCash(tempCash);
	tempCash = 0;
		
	removeCash(change);
	return change;
}