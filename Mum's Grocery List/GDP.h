#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <list>
using namespace std;

class GDP
{
public:
	struct GDPnode
	{
		//All the info needed for the items
		int amount;
		double Cost;
		string ItemName;
		double Total = amount * Cost;
		//The ever important Next
		struct GDPnode *next;

	};
	GDPnode *head;
	GDP()
	{
		head = nullptr;
	};
	//Adding an item to the list, obviously
	void addItem(int, double, string);
	//Deleting an item from the list outright
	void deleteItem(string);
	//When you want to remove an item but not delete the whole thing
	void decreaseItem(int, string); 
	//Adding to an existing item
	void increaseItem(int, string);
	//Finding an item in the list, dummy
	void searchItem(string);
	//Show the list. Can you not read?
	void displayList() const;
	//Show the total of all items
	void displayTotal(double) const;
	~GDP();
};

