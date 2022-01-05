#ifndef H_UnorderedLinkedList
#define H_UnorderedLinkedList

#include "linkedList.h"

using namespace std;

template <class Type>
class unorderedLinkedList : public linkedListType<Type>
{
public:
	bool search(const Type& searchItem) const;

	void insertFirst(const Type& newItem);

	void insertLast(const Type& newItem);

	void deleteNode(const Type& deleteItem);
};

//=========================================================================================================
// Search constructor
//=========================================================================================================
template <class Type>
bool unorderedLinkedList<Type>:: search(const Type& searchItem) const
{
	nodeType<Type>* current; //pointer to traverse the list
	bool found = false;

	current = linkedListType<Type>::first; 

	while (current != nullptr && !found)    //search the list
		if (current->info == searchItem) 
			found = true;
		else
			current = current->link;
	return found;
}

//=========================================================================================================
// Insert to first node
//=========================================================================================================
template <class Type>
void unorderedLinkedList<Type>::insertFirst(const Type& newItem)
{
	nodeType<Type>* newNode; 

	newNode = new nodeType<Type>; 

	newNode->info = newItem;                          
	newNode->link = linkedListType<Type>::first;      
	linkedListType<Type>::first = newNode;            
	linkedListType<Type>::count++;                    

	if (linkedListType<Type>::last == nullptr)   
		linkedListType<Type>::last = newNode;
}

//=========================================================================================================
// Isert to last node
//=========================================================================================================
template <class Type>
void unorderedLinkedList<Type>::insertLast(const Type& newItem)
{
	nodeType<Type>* newNode; 

	newNode = new nodeType<Type>; 

	newNode->info = newItem;     
	newNode->link = nullptr; 
	
	if (linkedListType<Type>::first == nullptr)
	{
		linkedListType<Type>::first = newNode;
		linkedListType<Type>::last = newNode;
		linkedListType<Type>::count++;        
	}
	else    
	{
		linkedListType<Type>::last->link = newNode; 
		linkedListType<Type>::last = newNode; 
		linkedListType<Type>::count++;        
	}
}

//=========================================================================================================
// Delete a node
//=========================================================================================================
template <class Type>
void unorderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
	nodeType<Type>* current; 
	nodeType<Type>* trailCurrent; 
	bool found;
	if (linkedListType<Type>::first == nullptr) 
		cout << "Cannot delete from an empty list." << endl;
	else
	{
		if (linkedListType<Type>::first->info == deleteItem) 
		{
			current = linkedListType<Type>::first;
			linkedListType<Type>::first = linkedListType<Type>::first->link;
			linkedListType<Type>::count--;
			if (linkedListType<Type>::first == nullptr) //the list has only one node
				linkedListType<Type>::last = nullptr;
			delete current;
		}
		else 
		{
			found = false;
			trailCurrent = linkedListType<Type>::first; 
			
			current = linkedListType<Type>::first->link; 
		  
			while (current != nullptr && !found)
			{
				if (current->info != deleteItem)
				{
					trailCurrent = current;
					current = current->link;
				}
				else
					found = true;
			}
			if (found) 
			{
				trailCurrent->link = current->link;
				linkedListType<Type>::count--;
				if (linkedListType<Type>::last == current) 
					linkedListType<Type>::last = trailCurrent; 
				delete current;
				cout << "The data is done deleting in the list." << endl;
			}
			else
				cout << "The item to be deleted is not in the list. Press any ENTER to continue....." << endl;
				cin.ignore();
		}
	}
}

#endif
