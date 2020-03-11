#include <iostream>
#include <string>
#include "GDP.h"
#include "Lists.h"
using namespace std;

void startMenu();
void mainMenu();
void helpMenu();

//Default tax rate for Utah
const double TAX = .073;

int main()
{
	//Your main decision maker
	int Option;
	//Close program clause
	bool Close = false;
	bool backToMenu = false;
	//Object parts
	string ItemName;
	double Cost;
	int amount;
	//GDP object
	GDP Shopping = GDP();

	//List structure and fstream
	Lists List;
	fstream makeList;
	//A nifty little menu to get started


	//To keep things running
	while (!Close)
	{
		startMenu();
		cin >> Option;
		//Run help menu
		if (Option == 0)
		{
			helpMenu();
			cin >> Option;
		}
		switch (Option)
		{
		case 1://Create a new list in List.CPP
			List.NewList();
			break;
		case 2://Load saved list in List.CPP
			List.LoadList(ItemName, Cost, amount, Shopping);
			break;
		case 3:// Save List
			List.SaveList(ItemName, Cost, amount, Shopping);
			break;
		case 4: cout << "Goodbye! I hope I see you soon!\n";
			Close = true;
			break;
		default: cout << "Please follow the menu system\n";
		}
		while (!backToMenu)
		{
			mainMenu();
			cin >> Option;
			switch (Option)
			{
			case 1://Add Item
				cout << "Enter the Item Name, Cost of the Item, and the Amount you wish to purchase:\n";
				cout << "Item Name: ";
				cin >> ItemName;
				cout << "Cost of Item: ";
				cin >> Cost;
				cout << "Amount of Item(s): ";
				cin >> amount;
				Shopping.addItem(amount, Cost, ItemName);
				break;
			case 2://Delete Item
				cout << "Enter the name of the item you wish to delete\n";
				cin >> ItemName;
				Shopping.deleteItem(ItemName);
				break;
			case 3:// Remove Item
				cout << "Enter the Item you wish to decrease\n";
				cout << "Name: ";
				cin >> ItemName;
				cout << "Amount: ";
				cin >> amount;
				Shopping.decreaseItem(amount, ItemName);
				break;
			case 4:// Increase Item
				cout << "Enter the Item you wish to increase\n";
				cout << "Name: ";
				cin >> ItemName;
				cout << "Amount: ";
				cin >> amount;
				Shopping.increaseItem(amount, ItemName);
				break;
			case 5:// Search for item
				cout << "Enter item name:\n";
				cin >> ItemName;
				Shopping.searchItem(ItemName);
				break;
			case 6://Display List
				Shopping.displayList();
				break;
			case 7://Close
				cout << "Your total is:\n";
				Shopping.displayTotal(TAX);
				backToMenu = true;
				break;
			default: cout << "Please follow the menu system\n";
			}
		}
	}




	system("PAUSE");
	return 0;
}

void startMenu()
{
	cout << "Welcome to Mum's Grocery App!\n";
	cout << "What would you like to start with?\n"
		<< "0. HELP! I don't know where to start!\n"
		<< "1. Start New List\n"
		<< "2. Open Saved List\n"
		<< "3. Save List\n"
		<< "4. Close Program\n";
}

void mainMenu()
{
	cout << "What would you like to do?\n";
	cout << "1. Add Item\n"
		<< "2. Delete Item\n"
		<< "3. Remove Item\n"
		<< "4. Increase Item\n"
		<< "5. Search for an Item\n"
		<< "6. Display List\n"
		<< "7. Display Total and Exit Menu\n";
}

void helpMenu()
{
	int Choice;

	cout << "What would you like help with?\n"
		<< "0. How far along is this app?\n"
		<< "1. What does it mean to start a new list?\n"
		<< "2. Where is my saved list?\n"
		<< "3. How do I add items to my list?\n"
		<< "4. How do I delete items from my list?\n"
		<< "5. How do I change the number of items I buy?\n"
		<< "6. How is the total price added up?\n"
		<< "7. Where do I get savings?\n"
		<< "8. Do I have to change my list if the price is better at a store I don't like?\n"
		<< "9. Why won't my kids behave?\n";
	cin >> Choice;

	switch (Choice)
	{
	case 0:
		cout << "This app is in what I would call an early alpha. It has no real GUI and is only using a sudo savings system.";
		break;
	case 1:
		cout << "To start a new list means a BRAND NEW list will be made, erasing your old list and starting from scratch.";
		break;
	case 2:
		cout << "Your saved lists will be placed in the folder with the app. It can be transfered by any means.";
		break;
	case 3:
		cout << "Adding an item to a list is as simple as following the 'Add Item' option. You will be prompted to add an item name, the cost, and the amount you want of the product.";
		break;
	case 4:
		cout << "Deleting an item is simple! All you have to do is choose 'Remove Item' and then type the name of the item you want to delete. ITEMS ARE CAPS SENSATIVE!";
		break;
	case 5:
		cout << "Changing the amount of only requires picking the option to reduce items and choosing how many you want to take off. If you end up removing all items, it will delete the item.";
		break;
	case 6:
		cout << "The total cost is calculated by taking all the items in your list, multiplying the cost by the amount of each and then adding the tax by using a global tax rate for your state.";
		break;
	case 7:
		cout << "Savings are cross reffrenced by a database of different stores with alternate prices.";
		break;
	case 8:
		cout << "You may choose if you want to change the prices or not (Don't want to drive to Walmart?, understandable)";
		break;
	case 9:
		cout << "I'd say not enough fatal beatings.";
		break;
	default: cout << "Well that wasn't a choice. How'd you do that?\n";
		break;
	}
	cout << endl << endl;
	system("PAUSE");
	startMenu();
}