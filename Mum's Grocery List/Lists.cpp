#include "Lists.h"


Lists::Lists()
{
}
//Creating a new file
void Lists::NewList()
{
	fstream CreateFile;
	cout << "Creating SavedList.txt\n";
	CreateFile.open("SavedList.txt", ios::out);
}
//Load an old file
void Lists::LoadList(string ItemName, double Cost, int amount, GDP Shopping)
{
	fstream LoadFile;
	LoadFile.open("SavedList.txt", ios::in);
	if (LoadFile.fail())
	{
		cout << "You have no saved lists\n Please try creating a new one.";
	}
	else
	{
		while (LoadFile >> amount >> Cost >> ItemName)
		{
			Shopping.addItem(amount, Cost, ItemName); //Not using GDP.cpp?
		}
		cout << "List loaded:\n\n";
		GDP displayList(); //See also-
		LoadFile.close();
	}
}
//Find and replace prices
void Lists::SearchDeals(string ItemName, double Cost, fstream DealsList)
{

}
//Saving the list
void Lists::SaveList(string ItemName, double Cost, int amount, GDP Shopping)
{
	fstream SaveList;
	GDP::GDPnode *nodePtr = nullptr;
	nodePtr = Shopping.head;

	SaveList.open("SavedList.txt", ios::out);
	while (nodePtr != nullptr)
	{
		SaveList << nodePtr->ItemName << " " << nodePtr->Cost << " " << nodePtr->amount << endl;
		nodePtr->next;
		if (nodePtr = nullptr)
		{
			break;
		}
	}
	SaveList.close();
}

Lists::~Lists()
{

}
