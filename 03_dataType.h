#ifndef H_dataType
#define H_dataType

#include<iostream>
#include<string>

using namespace std;

class dataType
{
	friend ostream& operator<< (ostream&, const dataType&);

public:
	void setDataInfo(string date, string item, string quantity, string unitprice, string amount);

	void printDate() const;

	void printInfo() const;

	bool checkDate(string date);

	string getDate() const;

	dataType(string date = "", string item = "", string quantity = "", string unitprice = "", string amount = "");

	bool operator==(const dataType&) const;
	bool operator!=(const dataType&) const;
	bool operator>=(const dataType&) const;
	bool operator<=(const dataType&) const;

private:
	string Date;

	string Item;

	string Quantity;

	string Unitprice;

	string Amount;



};


#endif
