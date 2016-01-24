#include "stdafx.h"
#include <iostream>


class IntNode
{

public:
	IntNode() : NextNode(0) {};
	int Value() { return data; }
	IntNode *NextNode;
	int data;
	friend class IntList;
};

class IntList
{
public:

	IntList() : current_node(0), Head(0), Tail(0) {};
	void DisplayList();
	IntNode *Find(const int& i);
	IntNode &RecursiveFind(const int& i, IntNode *start);
	bool AddHead(int i);
	bool AddTail(int i);
	IntNode *Current() { return current_node; }
	IntNode *Head;
protected:
	IntNode *current_node;

	IntNode *Tail;
};

void IntList::DisplayList()
{
	current_node = Head;
	while (current_node != NULL)
	{
		std::cout << "Data :" << current_node->data << std::endl;
		current_node = current_node->NextNode;
	}
}

IntNode *IntList::Find(const int& i)
{
	current_node = Head;
	if (current_node->data == i)
	{
		return current_node;
	}
	else if (current_node->NextNode == NULL)
		return 0;
	else
		current_node = current_node->NextNode;
}

bool IntList::AddHead(int i)
{

	IntNode *NewHead = new IntNode;
	if (!NewHead)
	{
		return false;
	}
	if (Head)
	{
		NewHead->data = i;
		NewHead->NextNode = Head;
		Head = NewHead;
	}
	else
	{
		NewHead->data = i;
		Head = NewHead;
		Tail = NewHead;
	}

	return true;
}

bool IntList::AddTail(int i)
{
	IntNode *TempNode = new IntNode;
	if (TempNode == 0)
	{
		return false;
	}
	TempNode->data = i;
	Tail->NextNode = TempNode;
	Tail = TempNode;

	return true;
}






IntNode &IntList::RecursiveFind(const int& i, IntNode *start)
{
	IntNode *Temp = new IntNode;
	Temp->data = start->data;
	Temp->NextNode = start->NextNode;
	if (start->data == i)
	{
		return *Temp;
	}
	else
		return RecursiveFind(i, Temp->NextNode);
}






int main()
{
	IntList list;
	IntNode *Head = new IntNode;
	IntNode *Temp = new IntNode;
	list.AddHead(10);
	list.AddHead(2);
	list.AddTail(4);
	list.DisplayList();
	IntNode *a = list.Find(2);

	IntNode b = list.RecursiveFind(4, list.Head);

	return 0;
}

/*
node = new IntNode;
node->data = 2;
TempNode->NextNode = node;
TempNode = node;
*/