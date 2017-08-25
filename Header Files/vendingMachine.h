#include <iostream>
#include "coil.h"
#include "cashBox.h"

using namespace std;

class vendingMachine
{
	private:
		coil location[8][5];				// a 2D array which holds the location of each coil (coils hold stacks of items)

	public:

		///////////////////////////
		// CONSTRUCTOR
		///////////////////////////

		vendingMachine();				// constructor

		///////////////////////////
		// RESTOCK MODE FUNCTIONS
		///////////////////////////

		void restock();																					// a function which allows the user to restock a coil with items
		void fillCoil(char row, char column, string coilLocation, int choice, bool &restocking);		// a function which allows the user to fill a coil with items
		void emptyCoil(char row, char column, string coilLocation, bool &restocking, bool stocking);	// a function which allows the user to stock a coil with items
		void cashBoxAccess();																			// a function which allows the user to access the cashbox and change its values

		///////////////////////////
		// VENDING MODE FUNCTIONS
		///////////////////////////

		double getTempMoney();								// a function which returns tempCash from cashBox
		void insertMoney();									// a funciton which allows the user to insert money into the machine
		string dispense(char row, char column);				// a function which dispenses an item to the user
		double coinReturn();								// a function which returns the amount of money given back to the user
		void transaction(char row, char column);			// a function which handles a transaction between the user and vending machine
		
		///////////////////////////
		// FUNCTIONS USED BY BOTH 
		// VENDING/RESTOCK MODE
		///////////////////////////

		void displayContents();														// a function which displays the contents of the vending machine (may take this one out)
		void chooseCoil(string &coilLocation, int &row, int &column);				// a function which allows the user to choose a coil to activate
		void switchCoil(string coilLocation, int &row, int &column);				// a function which switches char to int
};