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
void selectFunc();

int main()
{
	dataListType dataList;
	int choice, c2;
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
	
	label:
		
	displayMenu();
	cout << "Enter your choice: ";
	cin >> choice;
	cout << endl;
	system("cls");

	while (choice != 0)
	{
		switch (choice) // daily
		{
			case 1:
				cout << "\nEnter date (yyyy-mm-dd) : ";
				cin.ignore();
				getline(cin, data);
				system("cls");	
					
				cout << "File Name: " << filename << endl;
				cout << endl;
				cout << "\t\t\t\t-----Daily Item Sales-----" << endl;
					
				cout << "\n==========================================================================================" << endl;
				cout << setw(8) << "Date" << setw(15) << "Item" << setw(20) << "Quantity" << setw(18) << "Unitprice" << setw(18) << "Amount (RM)" << endl;
				cout << "==========================================================================================" << endl;
				dataList.dailyReport(data);
				cout << "==========================================================================================" << endl;
				dataList.totalDailyAmount(data);
				dataList.dailySalesInfo(data);
				
				selectFunc();
				cin >> c2;
				
				for(;;)
				{
					while(c2 == 1) 
					{
						// add
						cout << "\nSelect one of the following :  " << endl;
						cout << "(1) Continue" << endl;
						cout << "(9) Return to function menu" << endl;
						cout << "(10) Return to main menu" << endl;
						cout << "(0) Exit" << endl;
						cout << "Enter your choice : " ;
						cin >> c2;
					}
					
					while(c2 == 2) 
					{
						// del
						cout << "\nSelect one of the following :  " << endl;
						cout << "(2) Continue" << endl;
						cout << "(9) Return to function menu" << endl;
						cout << "(10) Return to main menu" << endl;
						cout << "(0) Exit" << endl;
						cout << "Enter your choice : " ;
						cin >> c2;
					}
					
					while(c2 == 3) 
					{
						cout << "File Name : " << filename << endl;
						cout << endl;
						cout << "\t\t\t\t-----Data List-----\n" << endl;
				
						cout << "==========================================================================================" << endl;
						cout << setw(8) << "Date" << setw(15) << "Item" << setw(20) << "Quantity" << setw(18) << "Unitprice" << setw(18) << "Amount (RM)" << endl;
						cout << "==========================================================================================" << endl;
						dataList.print();
						cout << "==========================================================================================" << endl;
						dataList.totalAll();
	
						cout << "\nSelect one of the following :  " << endl;
						cout << "(3) Continue" << endl;
						cout << "(9) Return to function menu" << endl;
						cout << "(10) Return to main menu" << endl;
						cout << "(0) Exit" << endl;
						cout << "Enter your choice : " ;
						cin >> c2;
					}
					
					while(c2 == 9)
					{
						system("cls");
						selectFunc();
						cin >> c2;
					}
					
					while(c2 == 10)
					{
						system("cls");
						goto label;
					}
					
					while(c2 == 0)
					{
						exit (0);
					}
				}
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
				cout << setw(8) << "Date" << setw(15) << "Item" << setw(20) << "Quantity" << setw(18) << "Unitprice" << setw(18) << "Amount (RM)" << endl;
				cout << "==========================================================================================" << endl;
				dataList.monthlyReport(data);
				cout << "==========================================================================================" << endl;
				dataList.totalMonthlyAmount(data);
				dataList.monthlySalesInfo(data);
				
				selectFunc();
				cin >> c2;
				
				for(;;)
				{
					while(c2 == 1) 
					{
						// add
						cout << "\nSelect one of the following :  " << endl;
						cout << "(1) Continue" << endl;
						cout << "(9) Return to function menu" << endl;
						cout << "(10) Return to main menu" << endl;
						cout << "(0) Exit" << endl;
						cout << "Enter your choice : " ;
						cin >> c2;
					}
					
					while(c2 == 2) 
					{
						// del
						cout << "\nSelect one of the following :  " << endl;
						cout << "(2) Continue" << endl;
						cout << "(9) Return to function menu" << endl;
						cout << "(10) Return to main menu" << endl;
						cout << "(0) Exit" << endl;
						cout << "Enter your choice : " ;
						cin >> c2;
					}
					
					while(c2 == 3) 
					{
						cout << "File Name : " << filename << endl;
						cout << endl;
						cout << "\t\t\t\t-----Data List-----\n" << endl;
				
						cout << "==========================================================================================" << endl;
						cout << setw(8) << "Date" << setw(15) << "Item" << setw(20) << "Quantity" << setw(18) << "Unitprice" << setw(18) << "Amount (RM)" << endl;
						cout << "==========================================================================================" << endl;
						dataList.print();
						cout << "==========================================================================================" << endl;
						dataList.totalAll();
	
						cout << "\nSelect one of the following :  " << endl;
						cout << "(3) Continue" << endl;
						cout << "(9) Return to function menu" << endl;
						cout << "(10) Return to main menu" << endl;
						cout << "(0) Exit" << endl;
						cout << "Enter your choice : " ;
						cin >> c2;
					}
					
					while(c2 == 9)
					{
						system("cls");
						selectFunc();
						cin >> c2;
					}
					
					while(c2 == 10)
					{
						system("cls");
						goto label;
					}
					
					while(c2 == 0)
					{
						exit (0);
					}
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
	
	din.close();	
	return 0;
}

void createDataList(ifstream& din, dataListType& dataList)
{
	string date, item, quantity, unitprice, amount;
	
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
	cout << "\n==============================" << endl;
	cout << "\tMain menu" << endl;
	cout << "==============================" << endl;
	cout << "\nSelect one of the following :" << endl;
	cout << "(1) Daily Item Sales" << endl;
	cout << "(2) Monthly Item Sales" << endl;
	cout << "(0) Exit \n" << endl;
}

void selectFunc()
{
	cout << "\n==============================" << endl;
	cout << "\tFunction menu" << endl;
	cout << "==============================" << endl;
	cout << "\nSelect one of the following :" << endl;
	cout << "(1) Add" << endl;
	cout << "(2) Delete" << endl;
	cout << "(3) Display all data" << endl;
	cout << "(10) Return to main menu" << endl;
	cout << "(0) Exit" << endl;
	cout << "\nEnter your choice: ";
}
