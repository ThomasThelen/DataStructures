
#include "stdafx.h"
#include <iostream>

using std::cout;
using std::endl;

class Node
{
public:
	Node() :Previous(0), Next(0), Data(0) {};
	Node(const Node& copy)
	{
		this->Data = copy.Data;
		this->Next = copy.Next;
		this->Previous = copy.Previous;
	}
	~Node();
	friend class List;


protected:
	std::shared_ptr<Node> Previous; // Pointer to the previous node
	std::shared_ptr<Node> Next; // Pointer to the next node
	int Data; // Data in the Node
};


class List
{
public:
	List() : nHead(0), nTail(0), Size(0) {};
	void AddHead(const int& i);
	void AddTail(const int& i);
	void Display();
	Node Find(const int& to_find);
	Node& At(const int& i);
	void Insert(Node &add_at_node, const int node_value);
	void Swap(Node&, Node&);
	void BubbleSort();
	void QuickSort();
	void RecursiveBubbleSort();
	void RecursiveQuickSort();
	//void Delete();
	std::shared_ptr<Node> Head();
	std::shared_ptr<Node> Tail();


protected:
	std::shared_ptr<Node> nHead;
	std::shared_ptr<Node> nTail;
	int Size;
};

void List::Display()
{
	auto node = std::make_shared<Node>();
	node = nHead;
	int j = 0;
	while (node != nullptr)
	{
		cout<<" Node: "<<j<< " Data: "<<node->Data<<endl;
		node = node->Next;
		++j;
	}
}
void List::AddHead(const int& i)
{
	auto node = std::make_shared<Node>();
	node->Data = i;

	if (!nHead)
	{
		node->Next == NULL;
		node->Previous == NULL;
		nTail = node;
	}
	else
	{
		node->Next = nHead;
		node->Next->Previous = node;
	}
	++Size;
	nHead = node;
}
void List::AddTail(const int& i)
{
	auto node = std::make_shared<Node>();
	//Check if there is a head
	node->Data = i;
	if (!nHead)
	{
		nHead = node;
		nTail = node;
	}
	else
	{
		nTail->Next = node;
		node->Previous = nTail;
		nTail = node;
	}
	++Size;
}
Node List::Find(const int& to_find)
{
	auto node = std::make_shared<Node>();
	node = nHead;
	while (node != NULL)
	{
		if (node->Data == to_find)
		{
			return *node;
		}
		else
			node = node->Next;
	}
}
Node& List::At(const int& i)
{
	int j = 0;
	auto node = std::make_shared<Node>();;
	node = nHead;
	while (i != j)
	{
		node = node->Next;
		++j;
	}
	return *node;
}
void List::Insert(Node &add_at_node, const int node_value)
{
	auto node = std::make_shared<Node>();;
	node->Data = node_value;
	node->Next = add_at_node.Next;
	node->Previous = std::make_shared<Node>(add_at_node);
	add_at_node.Next->Previous = node;
	add_at_node.Next = node;
	++Size;
}
void List::Swap(Node& N1, Node& N2)
{
	auto node = std::make_shared<Node>(N1);
	
	N2.Next->Previous = std::make_shared<Node>(N1);
	N1.Previous->Next = std::make_shared<Node>(N2);
	N1.Next = N2.Next;
	N2.Previous = N1.Previous;
	N1.Previous = std::make_shared<Node>(N2);

	N2.Next = std::make_shared<Node>(N1);


//	N2.Next->Previous = node;
	//N1.Previous->Next = &N2;

	//N2.Next = node->Next;
	//N2.Previous = node->Previous;


}

void List::BubbleSort()

{
	auto next = std::make_shared<Node>();
	next = nHead->Next;
	if (next->Data > next->Next->Data)
	{

		Swap(*next, *next->Next);
	}
}



/*
Node List::*Head()
{
	return nHead;
}

*/


Node::~Node() {
	//while (Next)
//	{
//		delete this;
//	}
}

int main()
{
	// Create List
	List list;
	list.AddHead(10);
	list.AddHead(9);
	list.AddHead(8);
	list.AddTail(666);
	list.Display();
	//Perform List Operations
	cout << endl<<"Inserting Node..." << endl << "List is now :" << endl;
	Node find;
	find = list.Find(9);
	list.Insert(list.At(0), 55);
	list.Display();
	cout << endl << "Swapping ..." << endl << "List is now :" << endl;
	list.Swap(list.At(1), list.At(2));
	list.Display();

    return 0;
}

