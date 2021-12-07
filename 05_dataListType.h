#ifndef H_DataLinkedListType
#define H_DataLinkedListType

#include <string>
#include "unorderedLinkedList.h"
#include "dataType.h"

using namespace std;

class dataListType :public unorderedLinkedList<dataType>
{
public:
	bool dateSearch(string date) const;

	bool dataCheckDate(string date) const;

	void dataPrintDate() const;

private:
	void searchDataList(string date, bool& found, nodeType<dataType>* &current) const;

};

#endif

