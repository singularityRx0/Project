#include <iostream>
#include <fstream>
#include <string>
#include <limits>
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
	string data;

	ifstream din;

	string filename = "";
	cout << "Enter file name (Eg : File Name.txt) : ";
   	getline(cin, filename);
	system("cls");

	din.open(filename);
	if (!din)
	{
		cout << "Input file does not exist. " << endl;
		cout << "The program terminates!!!" << endl;
		return 1;
	}
	else
		cout << "\n\tInput file initializing. . ." << endl;

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
			cout << "Enter date (yyyy-mm-dd) : ";
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
				
		case 4:
			cout << "Report: " << endl;
			cout << "1: Daily Report " << endl;
			cout << "2: Monthly Report " << endl;
			cout << "Enter Choice: ";
			cin >> choice;
			cout << endl;

			switch (choice)
			{
			case 1: // Daily
				cout << "\nEnter date (yyyy-mm-dd) : ";
				cin.ignore();
				getline(cin, data);
				cout << endl;

				cout << "==========================================================================================" << endl;
				cout << setw(8) << "Date" << setw(15) << "Item" << setw(20) << "Quantity" << setw(18) << "Unitprice" << setw(15) << "Amount" << endl;
				cout << "==========================================================================================" << endl;
				dataList.dailyReport(data);
				cout << endl;
				cin.ignore();
				cin.get();
				system("cls");
				break;
					
			case 2: // Monthly
				cout << "Enter date: ";
				cin.ignore();
				getline(cin, data);
				cout << endl;

				cout << "==========================================================================================" << endl;
				cout << setw(8) << "Date" << setw(15) << "Item" << setw(20) << "Quantity" << setw(18) << "Unitprice" << setw(15) << "Amount" << endl;
				cout << "==========================================================================================" << endl;
				dataList.monthlyReport(data);
				cout << endl;
				cout << endl;
				cin.ignore();
				cin.get();
				system("cls");
				break;
			}

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
	
	din.ignore(numeric_limits<streamsize>::max(), '\n');
	
	while (din)
	{
		din >> date >> item >> quantity >> unitprice >> amount;
		newData.setDataInfo( date, item, quantity, unitprice, amount);
		dataList.insertLast(newData);
	}
}

void displayMenu()
{
	cout << "\nSelect one of the following :" << endl;
	cout << "(1) To check a particular date." << endl;
	cout << "(2) Print only the dates." << endl;
	cout << "(3) Print all the data." << endl;
	cout << "(4) Report Analysis." << endl;
	cout << "(0) Exit \n" << endl;
}
