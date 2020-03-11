#include "GDP.h"



void GDP::addItem(int quant, double price, string name)
{
	GDPnode *newNode;
	GDPnode *nodePtr;

	newNode = new GDPnode;
	newNode->Cost = price;
	newNode->amount = quant;
	newNode->ItemName = name;
	newNode->next = nullptr;

	if (!head)
		head = newNode;
	else
	{
		nodePtr = head;

		while (nodePtr->next)
			nodePtr = nodePtr->next;
		nodePtr->next = newNode;
	}
}

void GDP::deleteItem(string name)
{
	GDPnode *nodePtr;
	GDPnode *previouseNode = nullptr;
	
	if (!head)
		return;
	if (head->ItemName == name)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else
	{
		nodePtr = head;
		while (nodePtr != nullptr && nodePtr->ItemName != name)
		{
			previouseNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		if (nodePtr)
		{
			previouseNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
}

void GDP::decreaseItem(int quant, string name)
{
	GDPnode *nodePtr = nullptr;
	nodePtr = head;

	while (nodePtr->next != nullptr)
	{
		if (nodePtr->ItemName == name)
		{
			nodePtr->amount = nodePtr->amount - quant;
			break;
		}
	}

	if (quant <= 0)
	{
		deleteItem(name);
	}
}

void GDP::increaseItem(int quant, string name)
{
	GDPnode *nodePtr = nullptr;
	nodePtr = head;

	while (nodePtr->next != nullptr)
	{
		if (nodePtr->ItemName == name)
		{
			nodePtr->amount = nodePtr->amount + quant;
			break;
		}
	}
}

void GDP::searchItem(string name)
{
	int Choice; //Reduce, Reuse, Recycle, you know what im sayin'?
	bool found = false;
	GDPnode *nodePtr = nullptr;
	nodePtr = head;
	while (nodePtr->next != nullptr)
	{
		if (nodePtr->ItemName == name)
		{
			found = true;
			//Link to other functions
			cout << "What would you like to do to " << name << "?\n";
			cout << "1. Increase the quantity of items\n"
				<< "2. Decrease the quantity of items\n"
				<< "3. Delete item\n"
				<< "4. I changed my mind, go back.\n";
			cin >> Choice;
			switch (Choice)
			{
			case 1: cout << "How many would you like to add?\n";
				cin >> Choice;
				increaseItem(Choice, name);
				break;
			case 2: cout << "How many would you like to remove?\n";
				cin >> Choice;
				decreaseItem(Choice, name);
				break;
			case 3: cout << "Deleting item.\n";
				deleteItem(name);
				break;
			case 4: cout << "Backing out now.\n";
				break;
			default: cout << "Well you didn't pick any of the correct numbers. For shame.\n";

			}
			break;
		}

	}
	if (found == false)
	{
		cout << name << " was not on the list\n";
	}
}

void GDP::displayList() const
{
	GDPnode *nodePtr;

	nodePtr = head;

	while (nodePtr)
	{
		cout << nodePtr->ItemName << " " << nodePtr->amount << " $" << (nodePtr->Cost * nodePtr->amount) << endl;
		nodePtr = nodePtr->next;
	}
}

void GDP::displayTotal(double tax) const
{
	GDPnode *nodePtr;
	double totalCost = 0.0;

	nodePtr = head;
	//Come back to this one
	while (nodePtr)
	{
		totalCost += (nodePtr->Cost * nodePtr->amount);
		nodePtr = nodePtr->next;
	}
	cout << setprecision(2) << fixed;
	cout << "Total: $" << totalCost + (totalCost * tax) << endl;

}

GDP::~GDP()
{
	GDPnode *nodePtr;
	GDPnode *nextNode;

	nodePtr = head;
	while (nodePtr != nullptr)
	{
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
}
