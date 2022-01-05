#ifndef H_DataLinkedListType
#define H_DataLinkedListType

#include <string>
#include "unorderedLinkedList.h"
#include "dataType.h"

using namespace std;

class dataListType :public unorderedLinkedList<dataType>
{
public:
	void dataCheckList(string data);

	void dataPrintDate() const;
	
	void dailyReport(string data);
	
	void monthlyReport(string data);
	
	void totalDailyAmount(string data);
	
	void totalMonthlyAmount(string data);
	
	void dailySalesInfo(string data);
	
	void monthlySalesInfo(string data);
	
	void totalAll();
	
	void infoAll();

};

#endif

