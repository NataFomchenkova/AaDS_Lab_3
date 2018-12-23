
#include "stdafx.h"
#include "heap.h"

Heap::Heap()
{
	elements = nullptr;
	size = 0;
}


Heap::~Heap()
{
	delete[] elements;
	size = 0;
}

bool Heap::contains(int elem) // ����� �������� � ������ �� �����
{
	if (size == 0)
		return false;
	for (size_t i = 0; i < size; i++)
	{
		if (elements[i] == elem) //����� �� �������� ��������
			return true;
	}
	return false;
}

int Heap::at(size_t  index) // ��������� �������� �� �������
{
	if (index < 0)
		throw out_of_range("Error");
	else
	{
		if (index >= size) {
			throw out_of_range("Index is greater than list size");
		}
		else {
			return elements[index];
		}
	}
}

size_t Heap::get_size()
{
	return size;
}

void Heap::insert(int elem) // ���������� �������� � ������ �� �����
{
	if (size == 0)  
	{
		elements = new int[1];	// �������� ������� ��������
	}
	else
	{
		int *prev = elements;  
		elements = new int[size + 1]; // �������� ������� �� 1 ������� ������ �����������
		for (size_t i = 0; i < size; i++) // ���������� �������
			elements[i] = prev[i];
		delete[] prev; // �������� ������ ������
	}
	size ++;
	elements[size - 1] = elem; // ������ ������ �������� � ����� �������
	sorting(size - 1); // ����� ���������� ��� ������ �������
}

void Heap::remove(int elem) // �������� �������� ������ �� �����
{
	if (size == 0)
		return;
	/*bool temp = false;
	int index = -1;*/
	int	index = 0;
	while (elements[index] != elem && index < size)
		index++;
	if (index == size)
		throw out_of_range("There is no such elem in tne heap"); 
		/*for (size_t i = 0;temp == false, i < size; i++)
		{
			if (elements[temp] == elem)
				temp = true;
			index++;
		}*/
		/*if (temp == false)
			throw out_of_range("There is no such elem in tne heap");*/
			/*int help_elem = elements[index];
			elements[index] = elements[size - 1];
			elements[size - 1] = help_elem;*/
		swap(elements[index], elements[size - 1]); // ������� ��������, ������� ����� ������� �� ��������� ����� 
	size--;
	/*for (int i = size - 1; i >= index; i--)
		sorting(i);*/
	int *prev = elements; // ������ ����� ������ ������� �� 1 ������
	elements = new int[size];
	for (size_t i = 0; i < size; i++) // �������������� ������ ������ � �����
		elements[i] = prev[i];
	delete[] prev;
	for (size_t  i = 0; i < size; i++) // ��������� ����� ������
		sorting(i);
}

int Heap::get_index(int elem) // ��������� ������� �������� �� �����
{
	if (size == 0)
		throw out_of_range("Heap is empty");
	for (size_t i = 0; i < size; i++)
		if (elements[i] == elem)
			return i;
	throw out_of_range("Elem missing");
}

void Heap::sorting(int index) //����������
{
	if (elements[index] > elements[(index - 1) / 2])
	{
		/*int help_var = elements[index];
		elements[index] = elements[(index - 1) / 2];
		elements[(index - 1) / 2] = help_var;*/
		swap(elements[index], elements[(index - 1) / 2]); 
		sorting((index - 1) / 2);
	}
}

Iterator* Heap::create_width_iterator() // ����� � ������ 
{
	width_iterator* t = new width_iterator;
	t->head = &(elements[0]); 
	t->size = size;
	t->current = 0;
	return t;
}

Iterator* Heap::create_depth_iterator()  // ����� � �������
{
	depth_iterator* t = new depth_iterator;
	t->head = &(elements[0]);
	t->size = size;
	t->current = 0;
	t->visited = new bool[t->size];
	for (int i = 0; i < t->size; i++)
		t->visited[i] = false;
	return t;
}

void Heap::print_complete()
{
	if (size == 0)
		throw out_of_range("Heap is empty");
	system("cls");
	int len = 25; // ����� ������ ������ �������� ����� 
	int x = 60; // ����������, ��� ����� ��������� ������ ����� ���� �� ������ (�� ������ ���� ������ � ������)
	int y = 1; // �� �� �����, ������ � ������ (�� �������� ����)
	int cur = 0; // ������, ������� � �������� ������������ ����� 
	print_rec(len, x, y, cur);
}

void Heap::printf()
{
	int *t = &(elements[0]);
	for (int i = 0; i < size; i++)
		cout << t[i]<<' ';
}


void Heap::print_rec(int len, int x, int y, int cur)
{
	gotoxy(x - len, y); // �������, ���������� ������ � ����� � ������������ (�,�)
	if (cur * 2 + 1 < size)
		for (int i = 0; i < len; i++)
			cout << '_';
	else
		for (int i = 0; i < len; i++)
			cout << ' ';
	cout << elements[cur];
	if (cur * 2 + 1 < size)
		for (int i = 0; i < len; i++)
			cout << '_';
	else
		for (int i = 0; i < len; i++)
			cout << ' ';
	if (cur * 2 + 1 < size) // ���� ������� ����� ������� ���������� �������� �������� �����
		print_rec(len / 2, x - len, y + 1, cur * 2 + 1);
	if (cur * 2 + 2 < size)// ���� ������� ������ ������� ���������� �������� �������� �����
		print_rec(len / 2, x + len, y + 1, cur * 2 + 2);
}

/*
bool Heap::is_equal(int *array1, const size_t size_array1, int *array2, const size_t size_array2)
{

	if (size_array1 != size_array2) return false;
	for (size_t i = 0; i<size_array1; i++)
	{
		if (array2[i] != array1[i])
			return false;
	}
	return true;
}*/