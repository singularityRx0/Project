#ifndef H_UnorderedLinkedList
#define H_UnorderedLinkedList

#include "linkedList.h"

using namespace std;

template <class Type>
class unorderedLinkedList : public linkedListType<Type>
{
public:
	bool search(const Type& searchItem) const;
	//Function to determine whether searchItem is in the list.
	//Postcondition: Returns true if searchItem is in the
	//               list, otherwise the value false is
	//               returned.

	void insertFirst(const Type& newItem);

	void insertLast(const Type& newItem);

	void deleteNode(const Type& deleteItem);
};


template <class Type>
bool unorderedLinkedList<Type>:: search(const Type& searchItem) const
{
	nodeType<Type>* current; //pointer to traverse the list
	bool found = false;

	current = linkedListType<Type>::first; //set current to point to the first node in the list

	while (current != nullptr && !found)    //search the list
		if (current->info == searchItem) //searchItem is found
			found = true;
		else
			current = current->link; //make current point to the next node
	return found;
}//end search

template <class Type>
void unorderedLinkedList<Type>::insertFirst(const Type& newItem)
{
	nodeType<Type>* newNode; //pointer to create the new node

	newNode = new nodeType<Type>; //create the new node

	newNode->info = newItem;    //store the new item in the node
	newNode->link = linkedListType<Type>::first;      //insert newNode before first
	linkedListType<Type>::first = newNode;            //make first point to the actual first node
	linkedListType<Type>::count++;                    //increment count

	if (linkedListType<Type>::last == nullptr)   //if the list was empty, newNode is also the last node in the list
		linkedListType<Type>::last = newNode;
}//end insertFirst

template <class Type>
void unorderedLinkedList<Type>::insertLast(const Type& newItem)
{
	nodeType<Type>* newNode; //pointer to create the new node

	newNode = new nodeType<Type>; //create the new node

	newNode->info = newItem; //store the new item in the node
	newNode->link = nullptr;     //set the link field of newNode to nullptr

	if (linkedListType<Type>::first == nullptr) //if the list is empty, newNode is both the first and last node
	{
		linkedListType<Type>::first = newNode;
		linkedListType<Type>::last = newNode;
		linkedListType<Type>::count++;        //increment count
	}
	else    //the list is not empty, insert newNode after last
	{
		linkedListType<Type>::last->link = newNode; //insert newNode after last
		linkedListType<Type>::last = newNode; //make last point to the actual last node in the list
		linkedListType<Type>::count++;        //increment count
	}
}//end insertLast


template <class Type>
void unorderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
	nodeType<Type>* current; //pointer to traverse the list
	nodeType<Type>* trailCurrent; //pointer just before current
	bool found;
	if (linkedListType<Type>::first == nullptr) //Case 1; the list is empty.
		cout << "Cannot delete from an empty list." << endl;
	else
	{
		if (linkedListType<Type>::first->info == deleteItem) //Case 2
		{
			current = linkedListType<Type>::first;
			linkedListType<Type>::first = linkedListType<Type>::first->link;
			linkedListType<Type>::count--;
			if (linkedListType<Type>::first == nullptr) //the list has only one node
				linkedListType<Type>::last = nullptr;
			delete current;
		}
		else //search the list for the node with the given info
		{
			found = false;
			trailCurrent = linkedListType<Type>::first; //set trailCurrent to point
			//to the first node
			current = linkedListType<Type>::first->link; //set current to point to
		   //the second node
			while (current != nullptr && !found)
			{
				if (current->info != deleteItem)
				{
					trailCurrent = current;
					current = current->link;
				}
				else
					found = true;
			}//end while
			if (found) //Case 3; if found, delete the node
			{
				trailCurrent->link = current->link;
				linkedListType<Type>::count--;
				if (linkedListType<Type>::last == current) //node to be deleted
				//was the last node
					linkedListType<Type>::last = trailCurrent; //update the value
					//of last
				delete current; //delete the node from the list
			}
			else
				cout << "The item to be deleted is not in " << "the list." << endl;
		}
	}
}

#endif
