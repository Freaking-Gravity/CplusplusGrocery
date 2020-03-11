#pragma once
#include <fstream>
#include "GDP.h"
using namespace std;

class Lists
{
public:
	fstream File;
	Lists();
	void NewList();
	void LoadList(string, double, int, GDP);
	void SearchDeals(string, double, fstream);
	void SaveList(string, double, int, GDP);
	~Lists();
};

