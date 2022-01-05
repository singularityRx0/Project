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
void addData(dataListType& dataList, int c2);
void deleteData(dataListType& dataList, int c2);

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
	din.close();
	
	label:
		
	displayMenu();
	cout << "Enter your choice: ";
	cin >> choice;
	cout << endl;
	system("cls");

	while (choice != 0)
	{
		switch (choice) 
		{
			case 1: // daily
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
				cout << "\t\t\t\t\t\t\tpress any ENTER to continue....." << endl;
				cin.get();
				
				selectFunc();
				cin >> c2;
				
				for(;;)
				{
					while(c2 == 1) 
					{
						// add
						cout << "\nSelect one of the following :  " << endl;
						cout << "(1) Add to bottom" << endl;
						cout << "(2) Add to top" << endl;
						cout << "\nEnter your choice : ";
						cin >> c2;
						addData(dataList, c2);
						cout << "\nSelect one of the following :  " << endl;
						cout << "(1) Continue" << endl;
						cout << "(9) Return to function menu" << endl;
						cout << "(10) Return to main menu" << endl;
						cout << "(0) Exit" << endl;
						cout << "\nEnter your choice : ";
						cin >> c2;
					}
					
					while(c2 == 2) 
					{
						// del
						deleteData(dataList, c2);
						system("cls");
						cout << "\nSelect one of the following :  " << endl;
						cout << "(2) Continue" << endl;
						cout << "(9) Return to function menu" << endl;
						cout << "(10) Return to main menu" << endl;
						cout << "(0) Exit" << endl;
						cout << "\nEnter your choice : " ;
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
				cout << setw(8) << "Date" << setw(17) << "Item" << setw(19) << "Quantity" << setw(21) << "Unitprice (RM)" << setw(15) << "Amount (RM)" << endl;
				cout << "==========================================================================================" << endl;
				dataList.monthlyReport(data);
				cout << "==========================================================================================" << endl;
				dataList.monthlySalesInfo(data);
				dataList.totalMonthlyAmount(data);
				cout << "\t\t\t\t\t\t\tpress any ENTER to continue....." << endl;
				cin.get();
				
				selectFunc();
				cin >> c2;
				
				for(;;)
				{
					while(c2 == 1) 
					{
						// add
						cout << "\nSelect one of the following :  " << endl;
						cout << "(1) Add to bottom" << endl;
						cout << "(2) Add to top" << endl;
						cout << "\nEnter your choice : ";
						cin >> c2;
						addData(dataList, c2);
						cout << "\nSelect one of the following :  " << endl;
						cout << "(1) Continue" << endl;
						cout << "(9) Return to function menu" << endl;
						cout << "(10) Return to main menu" << endl;
						cout << "(0) Exit" << endl;
						cout << "\nEnter your choice : ";
						cin >> c2;
					}
					
					while(c2 == 2) 
					{
						// del
						deleteData(dataList, c2);
						system("cls");
						cout << "\nSelect one of the following :  " << endl;
						cout << "(2) Continue" << endl;
						cout << "(9) Return to function menu" << endl;
						cout << "(10) Return to main menu" << endl;
						cout << "(0) Exit" << endl;
						cout << "\nEnter your choice : " ;
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
				
			case 3: // display
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
				
				selectFunc();
				cin >> c2;
				
				for(;;)
				{
					while(c2 == 1) 
					{
						// add
						cout << "\nSelect one of the following :  " << endl;
						cout << "(1) Add to bottom" << endl;
						cout << "(2) Add to top" << endl;
						cout << "\nEnter your choice : ";
						cin >> c2;
						addData(dataList, c2);
						cout << "\nSelect one of the following :  " << endl;
						cout << "(1) Continue" << endl;
						cout << "(9) Return to function menu" << endl;
						cout << "(10) Return to main menu" << endl;
						cout << "(0) Exit" << endl;
						cout << "\nEnter your choice : ";
						cin >> c2;
					}
					
					while(c2 == 2) 
					{
						// del
						deleteData(dataList, c2);
						system("cls");
						cout << "\nSelect one of the following :  " << endl;
						cout << "(2) Continue" << endl;
						cout << "(9) Return to function menu" << endl;
						cout << "(10) Return to main menu" << endl;
						cout << "(0) Exit" << endl;
						cout << "\nEnter your choice : " ;
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
				
			case 4: // add
				cout << "\nSelect one of the following :  " << endl;
				cout << "(1) Add to bottom" << endl;
				cout << "(2) Add to top" << endl;
				cout << "(10) Return to main menu" << endl;
				cout << "(0) Exit" << endl;
				cout << "\nEnter your choice : ";
				cin >> c2;
				addData(dataList, c2);
				system("cls");
				break;
				
			case 5: // delete
				cout << "\nSelect one of the following :  " << endl;
				cout << "(2) Continue" << endl;
				cout << "(9) Return to function menu" << endl;
				cout << "(10) Return to main menu" << endl;
				cout << "(0) Exit" << endl;
				cout << "\nEnter your choice : ";
				cin >> c2;
				deleteData(dataList, c2);
				system("cls");
				break;
				
			case 6: // check
				cin.ignore();
				cout << "\nCheck for same data: " << endl;
				cout << "\nEnter date: ";
				getline(cin,data);
				cout << "\nSearching for similar " << data << " in " << filename << "..." << endl;
				dataList.dataCheckList(data);
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
	cout << "(3) Display All Data" << endl;
	cout << "(4) Add Data to List" << endl;
	cout << "(5) Delete Data" << endl;
	cout << "(6) Check Number of Same Data in List" << endl;
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
	cout << "(10) Return to main menu" << endl;
	cout << "(0) Exit" << endl;
	cout << "\nEnter your choice: ";
}

void addData(dataListType& dataList, int c2)
{
	string date, item, quantity, unitprice, amount;

	dataType newData;

	cin.ignore();

	switch (c2)
	{
	case 1: //add to bottom
		cout << "\n\t\t Input data into the list." << endl;
		cout << "\nEnter date (yyyy-mm-dd) : " ;
		getline(cin, date);
		cout << endl;
		cout << "Enter item : ";
		getline(cin, item);
		cout << endl;
		cout << "Enter quantity : ";
		getline(cin, quantity);
		cout << endl;
		cout << "Enter unitprice : ";
		getline(cin, unitprice);
		cout << endl;
		cout << "Enter amount : ";
		getline(cin, amount);
		cout << endl;
		newData.setDataInfo(date, item, quantity, unitprice, amount);
		dataList.insertLast(newData);
		cout << "\tData successfully added to the list! Press any ENTER to continue....." << endl;
		cin.ignore();
		break;
			
	case 2: //add to top
		cout << "\n\t\t Input data to be entered." << endl;
		cout << "\nEnter date (yyyy-mm-dd) : ";
		getline(cin, date);
		cout << endl;
		cout << "Enter item : ";
		getline(cin, item);
		cout << endl;
		cout << "Enter quantity : ";
		getline(cin, quantity);
		cout << endl;
		cout << "Enter unitprice : ";
		getline(cin, unitprice);
		cout << endl;
		cout << "Enter amount : ";
		getline(cin, amount);
		cout << endl;
		newData.setDataInfo(date, item, quantity, unitprice, amount);
		dataList.insertFirst(newData);
		cout << "\tData successfully added to the list! Press any ENTER to continue....." << endl;
		cin.ignore();
		break;
		
	default:
		cout << "\nInvalid Selection! Please try again." << endl;
		break;
	}
}

void deleteData(dataListType& dataList, int c2)
{
	string date, item, quantity, unitprice, amount;

	dataType newData;

	cin.ignore();

	if (c2 == 2)
	{
		cout << "\n\t\t Input data to be deleted." << endl;
		cout << "Enter date (yyyy-mm-dd) : ";
		getline(cin, date);
		cout << endl;
		cout << "Enter item : ";
		getline(cin, item);
		cout << endl;
		cout << "Enter quantity : ";
		getline(cin, quantity);
		cout << endl;
		cout << "Enter unitprice : ";
		getline(cin, unitprice);
		cout << endl;
		cout << "Enter amount : ";
		getline(cin, amount);
		cout << endl;
		newData.setDataInfo(date, item, quantity, unitprice, amount);
		dataList.deleteNode(newData);
	}
}
