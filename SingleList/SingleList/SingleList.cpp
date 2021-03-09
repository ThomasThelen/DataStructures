#include "stdafx.h"
#include <iostream>
#include <memory>

class IntNode
{

public:
	IntNode() : NextNode(0), data(0) {};
	int Value() { return data; }
	std::shared_ptr<IntNode> NextNode;
	int data;
	friend class IntList;
};

class IntList
{
public:
	IntList() : current_node(0), Head(0), Tail(0) {};
	void DisplayList();
	std::shared_ptr<IntNode> Find(const int& i);
	std::shared_ptr<IntNode> RecursiveFind(const int& i, std::shared_ptr<IntNode> start);
	bool AddHead(int i);
	bool AddTail(int i);
	std::shared_ptr<IntNode> Current() { return current_node; }
	std::shared_ptr<IntNode> Head;

protected:
	std::shared_ptr<IntNode> current_node;
	std::shared_ptr<IntNode> Tail;
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

std::shared_ptr<IntNode> IntList::Find(const int& i)
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

	std::shared_ptr<IntNode> NewHead = std::make_shared<IntNode> ();
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
	std::shared_ptr<IntNode> TempNode = std::make_shared<IntNode>();
	if (TempNode == 0)
	{
		return false;
	}
	TempNode->data = i;
	Tail->NextNode = TempNode;
	Tail = TempNode;

	return true;
}






std::shared_ptr<IntNode> IntList::RecursiveFind(const int& i, std::shared_ptr<IntNode> start)
{
	auto Temp = std::make_shared<IntNode>();
	Temp->data = start->data;
	Temp->NextNode = start->NextNode;
	if (start->data == i)
	{
		return Temp;
	}
	else
		return RecursiveFind(i, Temp->NextNode);
}




int main()
{
	IntList list;
	auto Head = std::make_shared<IntNode>();
	auto Temp = std::make_shared<IntNode>();
	list.AddHead(10);
	list.AddHead(2);
	list.AddTail(4);
	list.DisplayList();
	auto firstFind = list.Find(2);
	auto secondFind = list.RecursiveFind(4, list.Head);

	return 0;
}

/*
node = new IntNode;
node->data = 2;
TempNode->NextNode = node;
TempNode = node;
*/