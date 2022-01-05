#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct node //node structure
{
    string date;    //date
    string item;        //item
    int quantity;        //quantity
    float unitprice;    //unitprice
    float amount;     //amount
    node *next;   //pointer to next node
};      //end of node structure


class linkedlist    //Class for linked list
{
    private:    //private variables
        node *head;   //head pointer
        node *tail;  //tail pointer
        int count;  //count of nodes
    public:
        linkedlist();   //constructor
        void add(string, string, int, float, float);    //add function
        void delete_node(string);    //delete function
        void search(string);    //search function
        void display();   //display function
};


linkedlist::linkedlist()
{
    // constructor
    // initialize the head and tail to NULL
    head = NULL;
    tail = NULL;
    // initialize the count to 0
    count = 0;
    //write to file
    ofstream outfile;    //output file
    outfile.open("data.txt", ios::app);   //open file
    outfile << "Date, Item, Quantity, Unit Price, Amount" << endl;
    outfile.close();    //close file

}


void linkedlist::add(string date, string item, int quantity, float unitprice, float amount)
{
    // create a new node
    node *new_node = new node;
    // assign the data to the new node
    new_node->date = date;  // date
    new_node->item = item;  // item
    new_node->quantity = quantity;  // quantity
    new_node->unitprice = unitprice;    // unitprice
    new_node->amount = amount;  // amount
    // if the list is empty
    if (head == NULL)
    {
        // assign the new node to the head and tail
        head = new_node;    // head
        tail = new_node;    // tail
    }
    else
    {
        // assign the new node to the tail
        tail->next = new_node;  // tail->next
        tail = new_node;    // tail
    }
    // increment the count
    count++;

    //add to the file
    ofstream outfile;    //output file
    outfile.open("data.txt", ios::app);  //open file
    outfile << date << "," << item << "," << quantity << "," << unitprice << "," << amount << endl;
    outfile.close();    //close file

}


void linkedlist::delete_node(string date)
{
    // create a new node
    node *temp = new node;
    // assign the head to the temp
    temp = head;
    // if the head is the node to be deleted
    if (temp->date == date)
    {
        // assign the head to the next node
        head = temp->next;
        // delete the temp node
        delete temp;
        // decrement the count
        count--;
    }
    else
    {
        // while the temp is not the tail
        while (temp->next != tail)
        {
            // if the next node is the node to be deleted
            if (temp->next->date == date)
            {
                // assign the next node to the next next node
                temp->next = temp->next->next;
                // delete the temp node
                delete temp;
                // decrement the count
                count--;
                // break the loop
                break;
            }
            // assign the temp to the next node
            temp = temp->next;
        }
        // if the temp is the tail
        if (temp->next == tail)
        {
            // assign the tail to the temp
            tail = temp;
            // delete the temp node
            delete temp;
            // decrement the count
            count--;
        }
    }
}


void linkedlist::search(string date)
{
    // create a new node
    node *temp = new node;
    // assign the head to the temp
    temp = head;
    // while the temp is not the tail
    while (temp != NULL)
    {
        // if the date is found
        if (temp->date == date)
        {
            // print the data
            cout << "Date: " << temp->date << endl;
            cout << "Item: " << temp->item << endl;
            cout << "Quantity: " << temp->quantity << endl;
            cout << "Unit Price: " << temp->unitprice << endl;
            cout << "Amount: " << temp->amount << endl;
            // break the loop
            break;
        }
        // assign the temp to the next node
        temp = temp->next;
    }
    // if the temp is the tail
    if (temp == tail)
    {
        // print the data
        cout << "Date: " << temp->date << endl;
        cout << "Item: " << temp->item << endl;
        cout << "Quantity: " << temp->quantity << endl;
        cout << "Unit Price: " << temp->unitprice << endl;
        cout << "Amount: " << temp->amount << endl;
    }
}


void linkedlist::display()
{
    // create a new node
    node *temp = new node;
    // assign the head to the temp
    temp = head;
    // while the temp is not the tail
    while (temp != tail)
    {
        // print the data
        cout << "Date: " << temp->date << endl;
        cout << "Item: " << temp->item << endl;
        cout << "Quantity: " << temp->quantity << endl;
        cout << "Unit Price: " << temp->unitprice << endl;
        cout << "Amount: " << temp->amount << endl;
        // assign the temp to the next node
        temp = temp->next;
    }
    // if the temp is the tail
    if (temp == tail)
    {
        // print the data
        cout << "Date: " << temp->date << endl;
        cout << "Item: " << temp->item << endl;
        cout << "Quantity: " << temp->quantity << endl;
        cout << "Unit Price: " << temp->unitprice << endl;
        cout << "Amount: " << temp->amount << endl;
    }
}



void menu()
{
    cout << "1. Add a new record" << endl;
    cout << "2. Delete a record" << endl;
    cout << "3. Search for a record" << endl;
    cout << "4. Display all records" << endl;
    cout << "5. Exit" << endl;
}


int main()
{
    //Create new linked list
    linkedlist list;
    //Create a new node
    node *temp = new node;
    //Create a string to store the date
    string date;
    //Create a string to store the item
    string item;
    //Create an integer to store the quantity
    int quantity;
    //Create a double to store the unit price
    double unitprice;
    //Create a double to store the amount
    double amount;
    //Create an integer to store the choice
    int choice;


    //While the choice is not 5
    while (choice != 5)
    {
        //Display the menu
        menu();
        //Get the choice
        cin >> choice;
        //If the choice is 1
        if (choice == 1)
        {
            //Get the date
            cout << "Enter the date: ";
            cin >> date;
            //Get the item
            cout << "Enter the item: ";
            cin >> item;
            //Get the quantity
            cout << "Enter the quantity: ";
            cin >> quantity;
            //Get the unit price
            cout << "Enter the unit price: ";
            cin >> unitprice;
            //Calculate the amount
            amount = quantity * unitprice;
            //Create a new node
            temp = new node;
            //Assign the date to the date
            temp->date = date;
            //Assign the item to the item
            temp->item = item;
            //Assign the quantity to the quantity
            temp->quantity = quantity;
            //Assign the unit price to the unit price
            temp->unitprice = unitprice;
            //Assign the amount to the amount
            temp->amount = amount;
            //Add the node to the linked list

            list.add(date, item, quantity, unitprice, amount);
        }
        //If the choice is 2
        else if (choice == 2)
        {
            //Get the date
            cout << "Enter the date: ";
            cin >> date;
            //Delete the node from the linked list
            list.delete_node(date);
        }
        //If the choice is 3
        else if (choice == 3)
        {
            //Get the date
            cout << "Enter the date: ";
            cin >> date;
            //Search for the node in the linked list
            list.search(date);
        }
        //If the choice is 4
        else if (choice == 4)
        {
            //Display all the nodes in the linked list
            list.display();
        }
        //If the choice is 5
        else if (choice == 5)
        {
            //Exit the program
            exit (0);
        }
        //If the choice is not 1, 2, 3, 4, or 5
        else
        {
            //Display an error message
            cout << "Error: Invalid choice" << endl;
        }

    }

    return 0;
}
