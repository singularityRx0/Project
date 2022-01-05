#include <iostream>
#include <string>
#include "dataListType.h"

using namespace std;

void dataListType::dataCheckList(string data)
{
	nodeType<dataType>* current;
	
	int count = 0;
	
	current = first;
	
	while(current != nullptr)
	{
		if (current->info.getDate() == data)
		{
			count++;
			current = current->link;
		}
		else
		{
			current = current->link;
		}
	}
	cout << count << "Similar Data Found.(By Date)" << endl;
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
	nodeType<dataType>* current;
	
	string s1,s2;

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
	
	cout << "\t\t\t\t\tAll in total amount made is:\t" << "RM " << totalamount << endl;
	cout << "==========================================================================================" << endl;
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
	cout << "\t\t\t\t\tAll in total amount made is:\t" << "RM " << totalAmount << endl;
	cout << "==========================================================================================" << endl;
}

void dataListType::dailySalesInfo(string data)
{
	nodeType<dataType>* current;

	string s1,s2,s3;

	int ayam = 0, ikan = 0, nasi = 0;
	int ayamT = 0, ikanT = 0, nasiT = 0;

	current = first;
	while (current != nullptr)
	{
		if (current->info.getDate() == data)
		{
			if (current->info.getItem() == "Ayam")
			{
				s1 = current->info.getQuantity();
				ayam = stoi(s1);
				ayamT = ayamT + ayam;
				current = current->link;
			}
			else if (current->info.getItem() == "Ikan")
			{
				s2 = current->info.getQuantity();
				ikan = stoi(s2);
				ikanT = ikanT + ikan;
				current = current->link;
			}
			else if (current->info.getItem() == "Nasi")
			{
				s3 = current->info.getQuantity();
				nasi = stoi(s3);
				nasiT = nasiT + nasi;
				current = current->link;
			}
		}
		else
		{
			current = current->link;
		}
	}
	
	cout << endl;
	cout << "\t\tTotal Number of Item Sold : " << endl;
	cout << "\t\t__________________________" << endl;
	cout << endl;
	cout << "\t\tAyam: \t" << ayamT << endl;
	cout << "\t\tIkan: \t" << ikanT << endl;
	cout << "\t\tNasi: \t" << nasiT << endl;
	cout << "==========================================================================================" << endl;
}

void dataListType::monthlySalesInfo(string data)
{
	nodeType<dataType>* current;
	
	string str1, str2;

	string s1, s2, s3;

	int ayam = 0, ikan = 0, nasi = 0;
	int ayamT = 0, ikanT = 0, nasiT = 0;

	current = first;
	while (current != nullptr)
	{
		str1 = current->info.getDate();
		str2 = str1.substr(0, 7);
		if (str2 == data)
		{
			if (current->info.getItem() == "Ayam")
			{
				s1 = current->info.getQuantity();
				ayam = stoi(s1);
				ayamT = ayamT + ayam;
				current = current->link;
			}
			else if (current->info.getItem() == "Ikan")
			{
				s2 = current->info.getQuantity();
				ikan = stoi(s2);
				ikanT = ikanT + ikan;
				current = current->link;
			}
			else if (current->info.getItem() == "Nasi")
			{
				s3 = current->info.getQuantity();
				nasi = stoi(s3);
				nasiT = nasiT + nasi;
				current = current->link;
			}
		}
		else
		{
			current=current->link;
		}
	}
	
	cout << endl;
	cout << "\t\tTotal Number of Item Sold : " << endl;
	cout << "\t\t__________________________" << endl;
	cout << endl;
	cout << "\t\tAyam: \t" << ayamT << endl;
	cout << "\t\tIkan: \t" << ikanT << endl;
	cout << "\t\tNasi: \t" << nasiT << endl;
	cout << "==========================================================================================" << endl;
}

void dataListType::totalAll()
{
	nodeType<dataType>* current;

	string s3;
	int Amount = 0, totalAmount = 0;

	current = first;

	while (current != nullptr)
	{
		
		s3 = current->info.getAmount();

		Amount = stoi(s3); // string to int
		totalAmount = Amount + totalAmount;
		current = current->link;
	}

	cout << "\t\t\t\t\tAll in total amount made is:\t" << "RM " <<  totalAmount << endl;
	cout << "==========================================================================================" << endl;
}

void dataListType::infoAll()
{
	nodeType<dataType>* current;

	string s1, s2, s3;

	int ayam = 0, ikan = 0, nasi = 0;
	int ayamT = 0, ikanT = 0, nasiT = 0;

	current = first;

	while (current != nullptr)
	{
		current->info.getItem();
		if (current->info.getItem() == "Ayam")
		{
			s1 = current->info.getQuantity();
			ayam = stoi(s1);
			ayamT = ayam + ayamT;
			current = current->link;
		}
		else if (current->info.getItem() == "Ikan")
		{
			s2 = current->info.getQuantity();
			ikan = stoi(s2);
			ikanT = ikan + ikanT;
			current = current->link;
		}
		else if (current->info.getItem() == "Nasi")
		{
			s3 = current->info.getQuantity();
			nasi = stoi(s3);
			nasiT = nasi + nasiT;
			current = current->link;
		}
		else
		{
			current = current->link;
		}
	}

	cout << endl;
	cout << "\t\tTotal Number of Item Sold : " << endl;
	cout << "\t\t__________________________" << endl;
	cout << endl;
	cout << "\t\tAyam: \t" << ayamT << endl;
	cout << "\t\tIkan: \t" << ikanT << endl;
	cout << "\t\tNasi: \t" << nasiT << endl;
	cout << "==========================================================================================" << endl;
}
