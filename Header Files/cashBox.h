#include "coin.h"
#include "coil.h"
using namespace std;

class cashBox
{
private:
	double tempCash;							// how much user currently has inserted into machine
	double cash;								// total amount of money in the cash box

public:
	cashBox(double cash);						// constructor

	//RESTOCK MODE
	double getCash();							// returns amount of money in cashbox
	void addCash(double amount);				// adds to "cash"
	double removeCash(double amount);			// allows the user to remove some money from "cash"
	double emptyCash();							// completely empties the "cash"

	//VENDING MODE
	double getTempCash();						// returns amount in "tempCash"
	void displayTempCash();						// displays the amount of money in "tempCash"
	void addCoin();								// allows the user to insert coins into the "tempCash" box
	void addTempCash(coin COIN);				// takes the name of the coin as a a parameter and adds its value to "tempCash"
	double tempCashReturn();					// empties the "tempCash" box and gives the money to the user
	double transaction(coil COIL);				// handles the money aspect of a transaction between the user and vending machine
	
};