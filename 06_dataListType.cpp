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

void dataListType::dailyReport(string data)
{
	nodeType<dataType>* current;
		
	current = first;
	while (current != nullptr)
	{
		if (current->info.getDate() == data)
		{
			current->info.printInfo();
			current = current->link;
		}
		else
		{
			current = current->link;
		}
	}
}

void dataListType::monthlyReport(string data)
{
	string s1,s2;
	
	nodeType<dataType>* current;

	current = first;
	
	while (current != nullptr)
	{
		s1 = current->info.getDate();
		s2 = s1.substr(0,7);
		
		if (s2 == data)
		{
			current->info.printInfo();
			current = current->link;
		}
		else
		{
			current = current->link;
		}
	}
}

void dataListType::totalDailyAmount(string data)
{
	nodeType<dataType>* current;
	
	string s1;
	
	int amount=0;
	int totalamount=0;
	
	current = first;
	while (current != nullptr)
	{
		if (current->info.getDate() == data)
		{
			s1 = current->info.getAmount();
			amount = stoi(s1);
			totalamount = amount + totalamount;
			current = current->link;
		}
		else
		{
			current = current->link;
		}
	}
	
	cout << "Total amount made on " << data << endl;
	cout << "Total: " << totalamount << endl;
}

void dataListType::totalMonthlyAmount(string data)
{
	nodeType<dataType>* current;
	
	string s1;
	string s2;
	string s3;
	
	int Amount=0;
	int totalAmount=0;
	
	current = first;
	while (current != nullptr)
	{
		s1 = current->info.getDate();
		s2= s1.substr(0,7);
		if(s2 == data)
		{
			s3 = current->info.getAmount();
			Amount = stoi(s3);
			totalAmount = Amount + totalAmount;
			current = current->link;
		}
		else
		{
			current = current->link;
		}
	}
	cout << "Total amount made on " << data << endl;
	cout << "Total: " << totalAmount << endl;
}



















