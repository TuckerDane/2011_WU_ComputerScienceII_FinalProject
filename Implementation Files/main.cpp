#include <iostream>
#include <string>
#include "vendingMachine.h"

using namespace std;

bool runVend(vendingMachine &machine);
bool runRestock(vendingMachine &machine);
void choiceHandler(string choice, vendingMachine &machine);
void vendingMode(vendingMachine &machine);
void restockMode(vendingMachine &machine);

int main()
{
	vendingMachine machine;
	int choice;
	bool end = false;
	while(end == false)
	{
		cout << "1: Vending Mode" << endl;
		cout << "2: Restock Mode" << endl;
		cout << "3: Leave Vending Machine" << endl;
		cout << "Enter your choice: ";
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
			vendingMode(machine);

		else if(choice == 2)
			restockMode(machine);
	
		else if(choice == 3)
			end = true;

		else
			cout << "Invalid choice. Please try again." << endl << endl;
	}

	return 0;

}

void vendingMode(vendingMachine &machine)
{
	bool exit= false;

	while ( exit == false)
		exit = runVend(machine);
}

void restockMode(vendingMachine &machine)
{
	bool exit= false;

	while ( exit == false)
		exit = runRestock(machine);
}

bool runVend(vendingMachine &machine)
{
	cout << "WELCOME TO THE VENDING MACHINE"			<< endl << endl;
	machine.displayContents();							cout	<< endl;

	cout << "There is currently $" << machine.getTempMoney() << " in the vending machine" << endl << endl;

	cout << "Enter 'c' to insert a coin"				<< endl;
	cout << "Enter 'r' to hit the coin return"			<< endl;
	cout << "Enter 'e' to exit vending mode"			<< endl << endl;

	cout << "Press the letter and number associated"	<< endl;
	cout << "with the item you wish to purchase.  For"	<< endl;
	cout << "example, 'A1' or 'D3'"						<< endl << endl;

	cout << "Enter your choice: ";

	string choice;
	cin >> choice;
	cout << endl;

	if(choice == "e" || choice == "E")
		return true;
	
	else
	{
		choiceHandler(choice, machine);

		bool keepGoing = true;

		while (keepGoing == true)
		{
			cout << "1: Continue Vending"	<< endl;
			cout << "2: Exit Vending Mode"	<< endl;
			cout << "Enter your choice: ";

			int decision;
			cin >> decision;
			cout << endl << endl;

			if(cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid choice. Please try again" << endl << endl;
				continue;
			}

			if (decision == 1)
			{
				keepGoing = false;
				return false;
			}
			else if (decision == 2)
			{
				keepGoing = false;
				return true;
			}
			else
			{
				cout << "Invalid choice!  Please enter a correct input. " << endl << endl;
				keepGoing = true;
			}
		}
	}
}

bool runRestock(vendingMachine &machine)
{
	cout << "WELCOME TO RESTOCK MODE"			<< endl << endl;

	cout << "Press 1 to access the cash box"	<< endl;
	cout << "Press 2 to restock the machine"	<< endl;
	cout << "Press 3 to exit restock mode"		<< endl;

	cout << "Enter your choice: ";
	int choice;
	cin >> choice;
	cout << endl << endl;

	while(cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid choice. Please try again: ";
		cin >> choice;
		cout << endl << endl;
		continue;
	}

	if(choice == 1)
	{
		machine.cashBoxAccess();
		return false;
	}
	else if (choice == 2)
	{
		machine.restock();
		return false;
	}
	else if (choice == 3)
	{
		return true;
	}
	else
	{
		cout << "Wrong input, please try again" << endl << endl;
		return false;
	}

}

void choiceHandler(string choice, vendingMachine &machine)
{
	if(choice.size() == 1)
	{
		if (choice == "C" || choice == "c")
		{
			machine.insertMoney();
		}
		else if (choice == "R" || choice == "r")
		{
			cout << "The vending machine dispensed $" << machine.coinReturn() << " in coin return." << endl << endl;
		}
		else
		{
			cout << "Invalid input. Try again." << endl << endl;
		}
	}

	else if(choice.size() == 2)
	{
		int row = 0;							
		int column = 0;							

		machine.chooseCoil(choice, row, column);	

		machine.transaction(row, column);
	}

	else
	{
		cout << "Invalid input. Try again." << endl;
	}
}

