#include <iostream>
using namespace std;
class Node
{
	friend class List;
private:
	int value;
	Node* next;
	Node(int v, Node* n)
	{
		value = v;
		next = n;
	}
	Node()
	{
		value = 0;
		next = NULL;
	}
};
class List
{
private:
	Node* head;
	Node* tail;
	int size;

public:
	
	List(int);
	void insertHead(int);
	void insertTail(int);
	void insert(int, int);
	void deleteHead();
	void print();
	~List();
};
List::List(int value)
{
	head = tail = new Node(value, NULL);
	size = 1;
}
void List::insertHead(int value)
{
	Node* newNode = new Node(value, NULL);
	if (head == NULL)
	{
		
		tail = newNode;
	}
	else
	{
		newNode->next = head;
	}
	head = newNode;
	size++;
}
void List::insertTail(int value)
{
	Node* newNode = new Node(value, NULL);
	if (head == NULL)
	{
		
		head = newNode;
	}
	else
	{
		tail->next = newNode;
	}
	tail = newNode;
	size++;
}
void List::insert(int value, int idx)
{
	/* 리스트의 시작점(Head)은 0으로 간주함 */
	Node* current = head;
	if (idx >= size || idx < 0)
	{
		cout << "인덱스 초과" << endl;
		return;
	}
	else
	{
		if (idx == 0)
		{
			insertHead(value);
		}
		else if (idx == size - 1)
		{
			insertTail(value);
		}
		else {
			Node* newNode = new Node(value, NULL);
			int i = 0;
			while (i < idx - 1)
			{
				current = current->next;
				i++;
			}
			newNode->next = current->next;
			current->next = newNode;
		}
	}
	size++;
}
void List::deleteHead()
{
	if (head != NULL)
	{
		Node* remove = head;
		head = head->next;
		delete remove;
		size--;
	}
}
void List::print()
{
	Node* current = head;
	while (current != NULL)
	{
		if (current->next == NULL)
		{
			cout << current->value << endl;
		}
		else
		{
			cout << current->value << " -> ";
		}
		current = current->next;
	}
}
List::~List()
{
	Node* current = head;
	while (current != NULL)
	{
		deleteHead();
	}
}
int main()
{

	
	
	List* list = new List(1);
	for (int i = 5; i <= 10; i++)
	{
		list->insertHead(i);
	}
	list->print();
	list->deleteHead();
	list->deleteHead();
	list->insert(100, 0);
	list->print();
	for (int i = 15; i <= 20; i++)
	{
		list->insertTail(i);
	}
	list->print();

}

