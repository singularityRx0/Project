#include <iostream>
#include <fstream>
using namespace std;

class Node
{
public:
    // Constructors
    Node();
    Node(string date, string item, string quantity, string unitprice, string amount);
    Node(Node& node);
    ~Node();

    bool readData();
    void setNext(Node* next);
    void print() ;

private:
    // Variables
    string Date;
    string Item;
    string Quantity;
    string Unitprice;
    string Amount;
    Node* Next;
};


Node::Node()
{
    Date = "";
    Item = "";
    Quantity = "";
    Unitprice = "";
    Amount = "";
    Next = NULL;
}


Node::Node(string date, string item, string quantity, string unitprice, string amount)
{
    Date = date;
    Item = item;
    Quantity = quantity;
    Unitprice = unitprice;
    Amount = amount;
    Next = NULL;
}


Node::Node( Node& node)
{
    Date = node.Date;
    Item = node.Item;
    Quantity = node.Quantity;
    Unitprice = node.Unitprice;
    Amount = node.Amount;
    Next = NULL;
}


Node::~Node()
{
}


// Read data from file into linked list, and print contents of the list.
bool Node::readData()
{
    // Declare local variables
    string date, item, quantity, unitprice, amount;
    date = item = quantity = unitprice = amount = "";
    

    // Get file name
    string filename = "";
    cout << "Enter file name: ";
    getline(cin, filename);

    // Open input file
    ifstream din;
    din.open(filename.c_str());
    if (din.fail())
    {
        cout << "Could not open file: " << filename << endl;
        return false;
    }

    // Read data
    cout << "Date" << "\t\tItem" << "\tQuantity" << "\tUnitprice" << "\tAmount" << endl;
    Node* head = NULL;
    while (!din.eof())
    {
        din >> date  >> item >> quantity >> unitprice >> amount;

        Node* temp = new Node(date, item, quantity, unitprice, amount);
        temp->setNext(head);
        head = temp;
    }

    din.close();
    head -> print();
    return true;
}


void Node::setNext(Node* next)
{
    Next = next;
}


void Node::print() 
{
    cout << Date << "    " << Item << "    " << Quantity << "\t \t   " << Unitprice << "\t\t    " << Amount << "\t\t    " << endl;
    if (Next != NULL)
        Next->print();
}


int main()
{
    Node list;
    if (list.readData())
        cout << "Read Success......." << endl;
    else
        cout << "Read Fail......." << endl;

    return 0;
}
