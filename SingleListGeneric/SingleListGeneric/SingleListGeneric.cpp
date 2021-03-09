#include "stdafx.h"
#include <iostream>


template <class nT> class IntList;

template <class nT>
class IntNode
{

public:
	IntNode() : NextNode(0) {};
	nT Value() { return data; }
	std::shared_ptr<IntNode> NextNode;
	nT data;
	friend class IntList <nT>;
};



template <class nT>
class IntList
{
public:

	IntList() : current_node(0), Head(0), Tail(0) {};
	void DisplayList();

	std::shared_ptr<IntNode<nT>> Find(const nT& i);
	std::shared_ptr<IntNode<nT>> RecursiveFind(const nT& i, std::shared_ptr<IntNode<nT>> start);
	bool AddHead(const nT& t);
	bool AddTail(const nT& t);

	std::shared_ptr<IntNode<nT>> Current() { return current_node; }
	std::shared_ptr<IntNode<nT>> Head;
protected:
	std::shared_ptr<IntNode<nT>> current_node;
	std::shared_ptr<IntNode<nT>> Tail;
};



template <class nT>
void IntList<nT>::DisplayList()
{
	auto current_node = Head;
	while (current_node != NULL)
	{
		std::cout << "Data :" << current_node->data << std::endl;
		current_node = current_node->NextNode;
	}
}

template <class nT>
std::shared_ptr<IntNode<nT>> IntList<nT>::Find(const nT& i)
{
	auto current_node = Head;
	if (current_node->data == i)
	{
		return current_node;
	}
	else if (current_node->NextNode == NULL)
		return 0;
	else
		current_node = current_node->NextNode;
}

template <class nT>
bool IntList<nT>::AddHead(const nT& i)
{
	auto NewHead = std::make_shared<IntNode<nT>>();
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


template <class nT>
bool IntList<nT>::AddTail(const nT& i)
{
	auto TempNode = std::make_shared<IntNode<nT>>();
	if (TempNode == 0)
	{
		return false;
	}
	TempNode->data = i;
	Tail->NextNode = TempNode;
	Tail = TempNode;

	return true;
}


template <class nT>
std::shared_ptr<IntNode<nT>>IntList<nT>::RecursiveFind(const nT& i, std::shared_ptr<IntNode<nT>> start)
{
	auto Temp = std::make_shared<IntNode<nT>>();
	Temp->data = start->data;
	Temp->NextNode = start->NextNode;
	if (start->data == i)
	{
		return Temp;
	}
	else if (start->NextNode == nullptr)

	{
		Temp = nullptr;
		return Temp;
	}

	return RecursiveFind(i, Temp->NextNode);
}


int main()
{
	IntList<double> list;
	auto Head = std::make_shared<IntNode<double>>();
	auto Temp = std::make_shared<IntNode<double>>();
	list.AddHead(10);
	list.AddHead(2);
	list.AddTail(4.3);
	list.DisplayList();
	auto a = list.Find(2);

	auto b = &list.RecursiveFind(4.3, list.Head);

	return 0;
}
