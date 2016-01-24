#include "stdafx.h"
#include <iostream>



template <class nT> class IntList;

template <class nT>
class IntNode
{

public:
	IntNode() : NextNode(0) {};
	nT Value() { return data; }
	IntNode *NextNode;
	nT data;
	friend class IntList <nT>;
};



template <class nT>
class IntList
{
public:

	IntList() : current_node(0), Head(0), Tail(0) {};
	void DisplayList();

	IntNode<nT> *Find(const nT& i);
	IntNode<nT> &RecursiveFind(const nT& i, IntNode<nT> *start);
	bool AddHead(const nT& t);
	bool AddTail(const nT& t);

	IntNode<nT> *Current() { return current_node; }
	IntNode<nT> *Head;
protected:
	IntNode<nT> *current_node;
	IntNode<nT> *Tail;
};



template <class nT>
void IntList<nT>::DisplayList()
{
	current_node = Head;
	while (current_node != NULL)
	{
		std::cout << "Data :" << current_node->data << std::endl;
		current_node = current_node->NextNode;
	}
}

template <class nT>
IntNode<nT> *IntList<nT>::Find(const nT& i)
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

template <class nT>
bool IntList<nT>::AddHead(const nT& i)
{
	IntNode<nT> *NewHead = new IntNode<nT>;
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
	IntNode<nT> *TempNode = new IntNode<nT>;
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
IntNode<nT> &IntList<nT>::RecursiveFind(const nT& i, IntNode<nT> *start)
{
	IntNode<nT> *Temp = new IntNode<nT>;
	Temp->data = start->data;
	Temp->NextNode = start->NextNode;
	if (start->data == i)
	{
		return *Temp;
	}
	else if (start->NextNode == nullptr)

	{
		Temp = nullptr;
		return *Temp;
	}

	return RecursiveFind(i, Temp->NextNode);
}


int main()
{
	IntList<double> list;
	IntNode<double> *Head = new IntNode<double>;
	IntNode<double> *Temp = new IntNode<double>;
	list.AddHead(10);
	list.AddHead(2);
	list.AddTail(4.3);
	list.DisplayList();
	IntNode<double> *a = list.Find(2);

	IntNode<double> *b = &list.RecursiveFind(4.3, list.Head);

	return 0;
}
