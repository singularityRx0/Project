#ifndef H_dataType
#define H_dataType

#include<iostream>
#include<string>

using namespace std;

class dataType
{
	friend ostream& operator<< (ostream&, const dataType&);

public:
	void setDataInfo(string date, string item, int quantity, int unitprice, int amount);

	void printDate() const;

	void printInfo() const;

	bool checkDate(string date);

	string getDate() const;

	dataType(string date = "", string item = "", int quantity = 0, int unitprice = 0, int amount = 0);

	bool operator==(const dataType&) const;
	bool operator!=(const dataType&) const;
	bool operator>=(const dataType&) const;
	bool operator<=(const dataType&) const;

private:
	string Date;

	string Item;

	int Quantity;

	int Unitprice;

	int Amount;



};


#endif
