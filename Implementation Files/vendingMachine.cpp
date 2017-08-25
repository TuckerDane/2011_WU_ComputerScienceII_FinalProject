#include "vendingMachine.h"
#include <string>
#include <iomanip>
using namespace std;

cashBox box(1000.00);

vendingMachine::vendingMachine()		// constructor
{
	location[0][0].stockItem(	"Chip bag",					7,		1.50);
	location[0][1].stockItem(	"Coka-Cola",				10,		1.00);
	location[0][2].stockItem(	"Toy Dinosaur",				3,		9.00);
	location[0][3].stockItem(	"Zune",						6,		150.00);
	location[0][4].stockItem(	"Grandma's Cookies Bag",	10,		1.50);
	location[1][0].stockItem(	"Triforce Piece",			3,		1000000.00);
	location[1][1].stockItem(	"Happy Meal",				7,		0.99);
	location[1][2].stockItem(	"Power Level",				1,		9001.00);
	location[1][3].stockItem(	"Pylon",					6,		100.00);
	location[1][4].stockItem(	"Zergling",					6,		25.00);
	location[2][0].stockItem(	"Super Smash Bros. Game",	2,		8.00);
	location[2][1].stockItem(	"Pepsi",					9,		1.50);
	location[2][2].stockItem(	"Sprite",					7,		1.50);
	location[2][3].stockItem(	"Poke-Ball",				10,		150.00);
	location[2][4].stockItem(	"Dratini",					2,		100000.00);
	location[3][0].stockItem(	"MagiKarp",					1,		200.00);
	location[3][1].stockItem(	"Super Potion",				8,		175.00);
	location[3][2].stockItem(	"Vespene Gas",				4,		50.00);
	location[3][3].stockItem(	"Seige Tank",				10,		15000.00);
	location[3][4].stockItem(	"Seige Mode",				1,		1500.00);
	location[4][0].stockItem(	"Composite Long Bow",		7,		27.00);
	location[4][1].stockItem(	"BFG",						1,		1000);
	location[4][2].stockItem(	"Chainsaw",					5,		25.00);
	location[4][3].stockItem(	"Pet Zombie",				4,		10.00);
	location[4][4].stockItem(	"+1 Stealth Upgrade",		3,		500.00);
	location[5][0].stockItem(	"Din's Fire",				1,		250.00);
	location[5][1].stockItem(	"Bob-omb",					6,		2.50);
	location[5][2].stockItem(	"Tire Iron",				5,		10.50);
	location[5][3].stockItem(	"Girlfriend",				1,		0.25);
	location[5][4].stockItem(	"Bear Trap",				7,		17.25);
	location[6][0].stockItem(	"Frozen Kidney",			2,		300.00);
	location[6][1].stockItem(	"357 Ammo Box",				8,		10.75);
	location[6][2].stockItem(	"Fishing Rod",				3,		15.00);
	location[6][3].stockItem(	"Methanphetamine Drug",		8,		40.00);
	location[6][4].stockItem(	"Sniper Rifle",				1,		600.00);
	location[7][0].stockItem(	"Card Deck",				7,		3.50);
	location[7][1].stockItem(	"Nerf Gun Dart",			10,		0.10);
	location[7][2].stockItem(	"Dagger",					2,		10.00);
	location[7][3].stockItem(	"Overshield",				4,		30.00);
	location[7][4].stockItem(	"Medkit",					10,		5.00);

}

///////////////////////////
// RESTOCK MODE FUNCTIONS
///////////////////////////

void vendingMachine::restock()				// a function which allows the user to restock a coil with items
{
	cout << "RESTOCK MODE"												<< endl << endl;
	cout << "This is what is currently inside the vending machine: "	<< endl << endl;
	displayContents();
	
	bool restocking = true;
	while (restocking == true)
	{
		cout << "which coil would you like to restock? ";

		string coilLocation;
		cin >> coilLocation;					// insert the name of the coil you wish to chose (ie 'A1' or 'D3')

		int row = 0;							// makes it easier to read coil[coilLocation[n]][coilLocation[y]] later
		int column = 0;							// makes it easier to read coil[coilLocation[n]][coilLocation[y]] later

		chooseCoil(coilLocation, row, column);	// validates the coil you chose, prompts you to retry if you got it wrong...

		// OPTIONS FOR THE USER TO TAKE
		cout << endl << "Coil " << coilLocation << " currently contains " << location[row][column].getStackSize() << " " << location[row][column].getItemName() << "(s)." << endl;
		cout << "Would you like to..." << endl;
		cout << "1: Fill it with more " << location[row][column].getItemName() << "s" << endl;
		cout << "2: Empty the coil" << endl;
		cout << "3: Empty the coil and refill it with a new item" << endl;
		cout << "4: Leave the coil as it is and restock a different coil" << endl;
		cout << "5: Stop restocking items" << endl;
		cout << "Enter your choice: ";

		// RECORDS THE USER's CHOCIE
		int choice;
		cin >> choice;
		cout << endl;

		// INPUT VALIDATION OF USER's CHOICE

		while(cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid choice. Please try again: ";
			cin >> choice;
			cout << endl << endl;
		}

		while (choice > 5 && choice < 1)
		{
			cout << "Wrong answer, please enter one of the choices listed above";
			cin >> choice;
		}

		bool stocking;	// used to tell emptyCoil whether or not fillCoil will be called after

		// EXECUTION OF THE USER's CHOICE
		switch (choice)
		{
			case 1: // THE USER WANTS TO FILL THE COIL MORE ITEMS	
				fillCoil(row, column, coilLocation, choice, restocking);
				break;

			case 2: // THE USER WANTS TO EMPTY THE COIL	
				stocking = false;			// says that the coil will not be filled after being emptied
				emptyCoil(row, column, coilLocation, restocking, stocking);
				break;

			case 3: // THE USER WANTS TO EMPTY THE COIL AND FILL IT WITH A NEW ITEM		
				stocking = true;			// says that the coil will be filled after being emptied
				emptyCoil(row, column, coilLocation, restocking, stocking);
				fillCoil(row, column, coilLocation, choice, restocking);
				break;

			case 4: // THE USER WANTS TO INSPECT A DIFFERENT COIL
				break;

			case 5: // THE USER WANTS TO EXIT RESTOCK MODE
				restocking = false;
				break;
		}
	}
}

void vendingMachine::fillCoil(char row, char column, string coilLocation, int choice, bool &restocking)			// a function used inside of restock() which fills (stocks) a coil
{
	string itemName;
	int number;
	double price;

	if (choice == 1)
	{
		cout << "How many more " << location[row][column].getItemName() << "s would you like to stock the coil with? ";
		cin >> number;
		itemName = location[row][column].getItemName();
	}
	else
	{
		cout << "What would you like to stock the coil with? ";
		cin.ignore();
		getline(cin, itemName);
		cout << "How many " << itemName << "s would you like to stock the coil with? ";
		cin >> number;
	}

	cout << "What do you want its price to be? ";
	cin >> price;
	cout << endl << "Stocking... ... ... " << endl << endl;

	if (number+location[row][column].getStackSize() > 10)	// ensures that there are no more than 10 items per coil
		number = 10-location[row][column].getStackSize();
	if (number+location[row][column].getStackSize() < 1)	// ensures that the number of items is positive or 0
		number = 1;

	// FILLING THE COIL
	location[row][column].stockItem(itemName, number, price);		// coil[row][column].stockItem(itemName) should push_back() a new item with the itemName onto the coil


	cout << "Stocked up " << number << " " << location[row][column].getItemName() << "s in coil " << coilLocation << "!!" << endl << endl;

	bool smartUser = false;

	while(smartUser == false)
	{
		cout << "1: Continue Restocking"	<< endl;
		cout << "2: Quit Restocking"		<< endl;
		cout << "Enter your choice: ";

		int choice;
		cin >> choice;
		cout << endl << endl;

		if(cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid choice. Please try again" << endl << endl;
			continue;
		}
		
		if(choice == 1)
		{
			smartUser = true;
		}
		else if (choice == 2)
		{
			restocking = false;
			smartUser = true;
		}
		else
		{
			cout << "Incorrect input, please try again!" << endl << endl;
		}
	}
}

void vendingMachine::emptyCoil(char row, char column, string coilLocation, bool &restocking, bool stocking)			// a function used inside of restock() which empties (unstocks) a coil
{
	while (location[row][column].empty() == false)		// while the coil still contains items...
	{
		location[row][column].popItem();				// take the items off of the stack
	}

	cout << "Coil " << coilLocation << " is now empty" << endl;
	
	if(stocking == false)	// if you're filling the coil later, dont day this stuff because 
	{						// then you will say it twice (same statement's at the end of fillCoil)
		bool smartUser = false;
		while(smartUser == false)
		{
			cout << "1: Continue Restocking"	<< endl;
			cout << "2: Quit Restocking"		<< endl;
			cout << "Enter your choice: ";

			int choice;
			cin >> choice;
			cout << endl << endl;

			if(cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid choice. Please try again" << endl << endl;
				continue;
			}
		
			if(choice == 1)
			{
				smartUser = true;
			}
			else if (choice == 2)
			{
				restocking = false;
				smartUser = true;
			}
			else
			{
				cout << "Incorrect input, please try again!" << endl << endl;
			}
		}
	}
}

void vendingMachine::cashBoxAccess()
{
	cout << "THERE IS CURRENTLY $" << box.getCash() << " IN THE CASH BOX" << endl;
	cout << "Press 1 to add money to the cash box" << endl;
	cout << "Press 2 to take money out of the cash box" << endl;
	cout << "Prees 3 to empty the cash box"				<< endl;
	cout << "Enter your choice: ";

	int choice;
	cin >> choice;
	cout << endl << endl;

	bool smartUser = false;

	while (smartUser == false)
	{
		while(cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid choice. Please try again: ";
			cin >> choice;
			cout << endl << endl;
		}

		if (choice == 1)
		{
			cout << "How much money would you like to add to the cash box? ";
			double moneyAdded;
			cin >> moneyAdded;

			box.addCash(moneyAdded);
			cout << "The cashbox now holds $" << box.getCash() << endl << endl;
			smartUser = true;
		}
		else if (choice == 2)
		{
			cout << "How much money would you like to take out of the cash box? ";
			double moneySubtracted;
			cin >> moneySubtracted;

			if (moneySubtracted > box.getCash())
			{
				cout << "There is not this much money in the cash box... so its going to be emptied" << endl;
				cout << "You just took out $" << box.emptyCash() << endl << endl;
			}
			else
			{
				cout << "You just took out $" << box.removeCash(moneySubtracted) << "." << endl;
				cout << "There is now $" << box.getCash() << " in the cash box." << endl << endl;
			}
			smartUser = true;

		}
		else if (choice == 3)
		{
			cout << "The cash box is now empty and you took out $" << box.emptyCash() << endl << endl;
			smartUser = true;
		}
		else
		{
			cout << "Invalid Choice, Please try again: ";
			cin >> choice;
			cout << endl << endl;
		}
	}
}

///////////////////////////
// VENDING MODE FUNCTIONS
///////////////////////////

double vendingMachine::getTempMoney()						// returns the amount of money stored in tempCash
{
	return box.getTempCash();
}

void vendingMachine::insertMoney()	// a funciton which allows the user to insert money into the vending machine, which puts it into its cashBox
{
	box.addCoin();					// cashBox.addTemp() would add the value of the coin entered to the value stored in its variable tempCash
}

string vendingMachine::dispense(char row, char column)				// a function which dispenses an item to the user
{
	string dispensed;

	if (sizeof(location[row][column]) == 0)							// IF the size of the stack stored in coil[row][column] is 0, then...
	{
		dispensed = "nothing";										// you get no item... *we may need to actually make an item called "nothing" for this to work
	}
	else															// OTHERWISE...
	{
		dispensed = location[row][column].getItemName();			// coil[row][column].getItem() returns the name of the top item on coil[row][column]
		location[row][column].popItem();							// coil[row][column].popItem() pops the top item off of the stack in coil[row][column]
	}
																	// IN ANY CASE...
	return dispensed;												// the function returns the item popped off of the coil, (or "nothing")
}

double vendingMachine::coinReturn()			// a function which returns the amount of money given back to the user
{
	return box.tempCashReturn();			// cashBox.emptyTemp() would empty the value stored in tempCash AND return the amount of money that it emptied
}

void vendingMachine::transaction(char row, char column)					// handles the transaction between user and vending machine given purchase of a particular item
{
	if(location[row][column].empty())
	{
		cout << "There is nothing in this location. Please insert a new choice." << endl << endl;
	}
	else if(box.getTempCash() < location[row][column].getPrice())
	{
		cout << "You have not paid enough. Please enter $" << location[row][column].getPrice() - box.getTempCash() << "." << endl;
		box.addCoin();
	}

	else
	{
		string dispensed = dispense(row, column);
		
		if(dispensed == "nothing")
		{
			cout << "There is nothing left in this location. Make a new selection." << endl << endl;
		}
		else
		{
			cout << "The vending machine dispensed " << dispensed << "." << endl;
			cout << "You got $" << box.transaction(location[row][column]) << " in change." << endl;
			cout << "Thank you for your business. Have a nice day!" << endl << endl;
		}
	}
}

///////////////////////////
// FUNCTIONS USED BY BOTH 
// VENDING/RESTOCK MODE
///////////////////////////

void vendingMachine::displayContents()		// a function which displays the contents of the vending machine (may take this one out)
{
	cout << "VENDING MACHINE CONTENTS"					<< endl << endl;
	cout << left << setw(10) << "LOCATION" << setw(25) << "ITEM" << setw(11) << "# LEFT" << "COST" << endl;
	cout << "-------------------------------------------------------------" << endl << endl;
	char letter = 'A';
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << letter << j+1 << "        ";

			if(location[i][j].getStackSize() > 0)
			{
				cout << left << setw(25) << location[i][j].getItemName() << setw(11) << location[i][j].getStackSize();
				cout << "$ " << fixed << setprecision(2) << location[i][j].getPrice();
			}
			else
			{
				cout << "nothing";
			}
			cout << endl;
		}
		letter++;
	}

	cout << endl;
}

void vendingMachine::chooseCoil(string &cLocation, int &row, int &column)			// a function which validates the coil the user wishes to activate
{
	while (cLocation.size() != 2)
	{
		cout << "Invalid input.  Please try again: ";
		cin >> cLocation;
	}

	bool validation = false;
	
	while (validation == false)
	{
	  //if      the letter                        is A-H                                          or                     a-h                      and        the number is 1-5      then...
		if ( ((cLocation[0] >= 'A' /* ASCII for 'H' */ && cLocation[0] <= 'H' /* ASCII FOR 'A'*/) || (cLocation[0] >= 'a' && cLocation[0] <= 'h')) && (cLocation[1] <= '5' && cLocation[1] >= '1'))
		{
			switchCoil(cLocation, row, column);
			validation = true;
		}
		else // you must have given an incorrect coil location!! try again :)
		{
			cout << "Sorry, you entered an incorrect coil location, please retry: ";
			cin >> cLocation;
		}
	}
}

void vendingMachine::switchCoil(string cLocation, int &row, int &column)
{
	/////// row
	switch(cLocation[0])
	{
	case 'a':
		row = 0;
		break;
	case 'A':
		row = 0;
		break;

	case 'b':
		row = 1;
		break;
	case 'B':
		row = 1;
		break;

	case 'c':
		row = 2;
		break;
	case 'C':
		row = 2;
		break;
				
	case 'd':
		row = 3;
		break;
	case 'D':
		row = 3;
		break;

	case 'e':
		row = 4;
		break;
	case 'E':
		row = 4;
		break;

	case 'f':
		row = 5;
		break;
	case 'F':
		row = 5;
		break;

	case 'g':
		row = 6;
		break;
	case 'G':
		row = 6;
		break;

	case 'h':
		row = 7;
		break;
	case 'H':
		row = 7;
		break;
	}

	///// column
	switch(cLocation[1])
	{
		case '1':
			column = 0;
			break;

		case '2':
			column = 1;
			break;

		case '3':
			column = 2;
			break;
				
		case '4':
			column = 3;
			break;

		case '5':
			column = 4;
			break;
	}
}