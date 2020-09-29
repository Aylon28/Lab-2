//
//
//
//Пуня Илона. Вариант 10.
//Задание. Создать класс типа «Односвязный список».
//Функции-члены добавляют элемент к списку, удаляют элемент из списка, печатают элементы с начала списка. Найти элемент в списке.
//
//
//

#include "pch.h"
#include <iostream>

using namespace std;

class List {
	int value;
	List *next;

	public: static void AddItem(List *&top, int value);
			static void PrintList(List *top);
			static void FindAndDel(List *top, int value);
};

void List::AddItem(List *&top, int value) {
	List *newItem, *previous = top;
	newItem = new List;
	newItem->value = value;

	if (top == NULL) {
		newItem->next = top;
		top = newItem;
	}
	else {
		newItem->next = previous->next;
		previous->next = newItem;
	}
}

void List::PrintList(List *top) {
	List *previous = top;
	while (previous != NULL)
	{
		cout << previous->value << " ";
		previous = previous->next;
	}
	cout << endl;
}

void List::FindAndDel(List *top, int value) {
	List *previous = top;

	if (previous->value == value)
	{
		*top = *previous->next;
	}
	else {
		while (previous->next != NULL)
		{
			if (previous->next->value == value)
			{
				previous->next = previous->next->next;
				break;
			}
			else {
				previous = previous->next;
			}
		}
	}

	cout << endl;
}

int main() {
	setlocale(LC_ALL, "Russian");
	
	List *top = NULL;
	int n, value;

	cout << "Введите количество элементов в списке: ";
	cin >> n;
	if (n != 0 && n > 0) {
		for (int i = 0; i < n; i++)
		{
			value = rand() % 100;
			List::AddItem(top, value);
		}
	}
	List::PrintList(top);

	cout << "Введите значение элемента для удаления: ";
	cin >> value;

	List::FindAndDel(top, value);
	List::PrintList(top);
}
