#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <limits>
#include <iomanip>
#include "dataType.h"
#include "dataListType.h"

using namespace std;

void createDataList(ifstream& din, dataListType& dataList);
void displayMenu();
void addNew(dataListType& dataList, int choice);

int main()
{
	dataListType dataList;
	int choice;
	string date,data;

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
	cout << endl;
	system("cls");

	while (choice != 0)
	{
		switch (choice)
		{
		case 1:
			cin.ignore();
			addNew(dataList, choice);
			break;
			
		case 2:
			cout << "File Name: " << filename << endl;
			cout << endl;
			cout << "\t\t\t\t-----Data List-----\n" << endl;
				
			cout << "==========================================================================================" << endl;
			cout << setw(8) << "Date" << setw(17) << "Item" << setw(19) << "Quantity" << setw(21) << "Unitprice (RM)" << setw(15) << "Amount (RM)" << endl;
			cout << "==========================================================================================" << endl;
			dataList.print();
			cout << "==========================================================================================" << endl;
			dataList.infoAll();
			dataList.totalAll();
			cin.ignore();
			cin.get();
			system("cls");
			break;
				
		case 3:
			cout << "Select one of the following :" <<endl;
			cout << "(1) Daily Item Sales" << endl;
			cout << "(2) Monthly Item Sales" << endl;
			cout << "\nEnter your choice: ";
			cin >> choice;
				
				switch (choice)
				{
				case 1: //daily
					cout << "\nEnter date (yyyy-mm-dd) : ";
					cin.ignore();
					getline(cin, data);
					system("cls");	
						
					cout << "File Name: " << filename << endl;
					cout << endl;
					cout << "\t\t\t\t-----Daily Item Sales-----" << endl;
					
					cout << "\n==========================================================================================" << endl;
					cout << setw(8) << "Date" << setw(17) << "Item" << setw(19) << "Quantity" << setw(21) << "Unitprice (RM)" << setw(15) << "Amount (RM)" << endl;
					cout << "==========================================================================================" << endl;
					dataList.dailyReport(data);
					cout << "==========================================================================================" << endl;
					dataList.dailySalesInfo(data);
					dataList.totalDailyAmount(data);
					cin.ignore();
					cin.get();
					system("cls");	
					break;	
				
				case 2: //monthly
					cout << "\nEnter date (yyyy-mm) : " ;
					cin.ignore();
					getline(cin, data);
					system("cls");
						
					cout << "File Name: " << filename << endl;
					cout << endl;
					cout << "\t\t\t\t-----Monthly Item Sales-----" << endl;
					
					cout << "\n==========================================================================================" << endl;
					cout << setw(8) << "Date" << setw(17) << "Item" << setw(19) << "Quantity" << setw(21) << "Unitprice (RM)" << setw(15) << "Amount (RM)" << endl;
					cout << "==========================================================================================" << endl;
					dataList.monthlyReport(data);
					cout << "==========================================================================================" << endl;
					dataList.monthlySalesInfo(data);
					dataList.totalMonthlyAmount(data);
					cin.ignore();
					cin.get();
					system("cls");
					break;
						
				default:
					cout << "Invalid Selection! Please try again." << endl;
					break;
				}
				break;
				
		default:
			cout << "Invalid Selection! Please try again." << endl;

		}
		cout << endl;
		displayMenu();
		cout << "Enter your choice: ";
		cin >> choice;
		cout << endl;
		system("cls");
	}

	return 0;
}

/*void createDataList(ifstream& din, dataListType& dataList)
{
	string date;
	string item;
	int quantity;
	int unitprice;
	int amount;
	
	dataType newData;
	
	din.ignore(numeric_limits<streamsize>::max(), '\n');
	
	while (din >> date >> item >> quantity >> unitprice >> amount)
	{		
		newData.setDataInfo( date, item, quantity, unitprice, amount);
		dataList.insertLast(newData);
	}
}*/
void addNew(dataListType& dataList, int choice)
{
	string date,item,quantity,unitprice,amount;
	
	dataType newData;
	
	cout << "(1) Add to top" << endl;
	cout << "(2) Add to bottom" << endl;
	cout << "\nEnter your choice: ";
	cin >> choice;
	cin.ignore();
	
	switch(choice)
	{
		case 1:
        		cout << "\nEnter the date (yyyy-mm-dd) : ";
			getline(cin,date);
			cout << "Enter the item : ";
			getline(cin,item);
			cout << "Enter the quantity : ";
 			getline(cin,quantity);
   			cout << "Enter the unit price : ";
			getline(cin,unitprice);;
 			cout << "Enter the amount : ";
   			getline(cin,amount);
			newData.setDataInfo(date, item, quantity, unitprice, amount);
        		dataList.insertFirst(newData);
       		break;
       	 
   		case 2:
   			cout << "\nEnter the date (yyyy-mm-dd) : ";
			getline(cin,date);
			cout << "Enter the item : ";
			getline(cin,item);
			cout << "Enter the quantity : ";
 			getline(cin,quantity);
   			cout << "Enter the unit price : ";
			getline(cin,unitprice);;
 			cout << "Enter the amount : ";
   			getline(cin,amount);
        		newData.setDataInfo(date, item, quantity, unitprice, amount);
        		dataList.insertLast(newData);
       		break;
        
       		default:
			cout << "\nInvalid Selection! Please try again." << endl;
			break;
	}
}

void createDataList(ifstream& din, dataListType& dataList) //ignores commas
{
	string date;
	string item;
	string quantity;
	string unitprice;
	string amount;
	
	string line;
	
	dataType newData;
	
	din.ignore(numeric_limits<streamsize>::max(), '\n');
	
	while (getline(din, line))
	{
		stringstream ss(line);
		getline(ss, date, ',');
		getline(ss, item, ',');
		getline(ss, quantity, ',');
		getline(ss, unitprice, ',');
		getline(ss, amount, ',');
		newData.setDataInfo(date, item, quantity, unitprice, amount);
		dataList.insertLast(newData);
			
	}
	
}

void displayMenu()
{
	cout << "\nSelect one of the following :" << endl;
	cout << "(1) Add new data." << endl;
	cout << "(2) Print all the data." << endl;
	cout << "(3) Report Analysis." << endl;
	cout << "(0) Exit \n" << endl;
}
