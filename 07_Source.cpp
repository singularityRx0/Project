#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "dataType.h"
#include "dataListType.h"

using namespace std;

void createDataList(ifstream& din, dataListType& dataList);
void displayMenu();

int main()
{
	dataListType dataList;
	int choice;
	char ch;
	string date;

	ifstream din;

	string filename = "";
	cout << "Enter file name (Eg : File Name.txt) : ";
    getline(cin, filename);

	din.open(filename);
	if (!din)
	{
		cout << "Input file does not exist. " << endl;
		cout << "The program terminates!!!" << endl;
		return 1;
	}
	else
		cout << "\nInput file initializing. . ." << endl;

	createDataList(din, dataList);
	din.close();

	displayMenu();
	cout << "Enter your choice: ";
	cin >> choice;
	cin.get(ch);
	cout << endl;

	while (choice != 0)
	{
		switch (choice)
		{
		case 1:
			cout << "Enter date : ";
			getline(cin, date);
			cout << endl;

			if (dataList.dateSearch(date))
				cout << "Data Exist: " << date << endl;
			else
				cout << "The Data Does Not Exist : " << date << endl;
			break;

		case 2:
			dataList.dataPrintDate();
			break;
			
		case 3:
			cout << "==========================================================================================" << endl;
			cout << setw(8) << "Date" << setw(15) << "Item" << setw(20) << "Quantity" << setw(18) << "Unitprice" << setw(15) << "Amount" << endl;
			cout << "==========================================================================================" << endl;
			dataList.print();
			break;

		default:
			cout << "Invalid Selection! Please try again." << endl;

		}
		cout << endl;
		displayMenu();
		cout << "Enter your choice: ";
		cin >> choice;
		cin.get(ch);
		cout << endl;
	}

	return 0;
}

void createDataList(ifstream& din, dataListType& dataList)
{
	string date;
	string item;
	int quantity;
	int unitprice;
	int amount;
	
	dataType newData;
	while (din)
	{
		din >> date >> item >> quantity >> unitprice >> amount;
		newData.setDataInfo( date, item, quantity, unitprice, amount);
		dataList.insertLast(newData);
	}
}

void displayMenu()
{
	cout << "\nSelect one of the following:" << endl;
	cout << "1: To check a particular date." << endl;
	cout << "2: print only the dates." << endl;
	cout << "3: Print all the data." << endl;
	cout << "0: To exit \n" << endl;
}
