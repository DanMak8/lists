#include <iostream>
using namespace std;


struct List
{
	int value;
	List* next;
};

void addToHead(List*& phead, int value) {
	List* newNode = new(List);
	newNode->value = value;
	newNode->next = phead;
	phead = newNode;
}

/*void main()
{
	int i;
	List* phead, * t;
	phead = new (List);
	t = phead;
	t->value = 1;
	t->next = new (List);
	t = (*t).next;
	(*t).value = 2;
	(*t).next = new (List);
	t = (*t).next;
	(*t).value = 6;
	(*t).next = new (List);
	t = (*t).next;
	(*t).value = 17;
	(*t).next = new (List);
	(*t).next = nullptr;
	addToHead(phead, 17);
	// Вывод содержимого информационных полей списка
	for (t = phead; t != nullptr; t = (*t).next)
		cout << (*t).value << " ";
}
*/