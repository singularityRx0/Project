#include <iostream>
#include <string>
#include "dataListType.h"

using namespace std;

void dataListType::searchDataList(string date, bool& found, nodeType<dataType>*& current) const
{
	found = false;

	current = first;

	while (current != nullptr && !found)
	{
		if (current->info.checkDate(date))
			found = true;
		else
			current = current->link;
	}
}

bool dataListType::dataCheckDate(string date) const
{
	bool found = false;
	nodeType<dataType> *location;

	searchDataList(date, found, location);

	return found;
}

bool dataListType::dateSearch(string date) const
{
	bool found = false;
	nodeType<dataType> *location;

	searchDataList(date, found, location);

	return found;
}

void dataListType::dataPrintDate() const
{
	nodeType<dataType>* current;

	current = first;
	while (current != nullptr)
	{
		current->info.printDate();
		current = current->link;
	}
}