#include <iostream>
#include <string>
#include "dataType.h"

using namespace std;

void dataType::setDataInfo(string date, string item, string quantity, string unitprice, string amount)
{
	Date = date;
	Item = item;
	Quantity = quantity;
	Unitprice = unitprice;
	Amount = amount;
}

dataType::dataType(string date, string item, string quantity, string unitprice, string amount)
{
	setDataInfo(date, item, quantity, unitprice, amount);
}

void dataType::printInfo() const
{
	cout << Date << "\t |" << Item << "\t\t |" << Quantity << "\t\t |" << Unitprice << "\t\t |" << Amount << "\t\t |" << endl;
}


string dataType::getDate() const
{
	return Date;
}

string dataType::getAmount() const
{
	return Amount;
}

string dataType::getItem() const
{
	return Item;
}

string dataType::getQuantity() const
{
	return Quantity;
}

string dataType::getUnitprice() const
{
	return Unitprice;
}

bool dataType::operator==(const dataType& other) const
{
	return (Date == other.Date);
}

bool dataType::operator!=(const dataType& other) const
{
	return (Date != other.Date);
}

bool dataType::operator>=(const dataType& other) const
{
	return (Date >= other.Date);
}

bool dataType::operator<=(const dataType& other) const
{
	return (Date <= other.Date);
}

bool dataType::operator==(const dataType& other) 
{
	return (Item == other.Item);
}

ostream& operator<< (ostream& osObject, const dataType& data)
{
	osObject << data.Date << "\t |" << data.Item << "\t\t |" << data.Quantity << "\t\t |" << data.Unitprice << "\t\t |" << data.Amount << "\t\t |" << endl;
	
	return osObject;
}
