#pragma once

#include "depth_Iterator.h"
#include "width_Iterator.h"
#include "gotoxy.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

class Heap
{
	int *elements; 
	size_t size; 
	int get_index(int elem); // ��������� ������� �������� �� ����� 
	void print_rec(int len, int x, int y, int cur); // ��������������� ��� ������ 
	void sorting(int index); // ����������


public:
	Heap();
	~Heap();
	bool contains(int elem);  // ����� �������� � ������ �� �����
	void insert(int elem);  // ���������� �������� � ������ �� �����
	void remove(int elem); // �������� �������� ������ �� �����
	size_t get_size();
	int at(size_t  index); // ��������� �������� �� �������
	void printf();


	Iterator* create_width_iterator(); 
	Iterator* create_depth_iterator();

	void print_complete(); // ����� ������ �� ����� 

	//bool is_equal(int *array1, const size_t size_array1, int *array2, const size_t size_array2);


};
