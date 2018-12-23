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
	int get_index(int elem); // получение индекса элемента по ключу 
	void print_rec(int len, int x, int y, int cur); // вспомогательная для вывода 
	void sorting(int index); // сортировка


public:
	Heap();
	~Heap();
	bool contains(int elem);  // поиск элемента в дереве по ключу
	void insert(int elem);  // добавление элемента в дерево по ключу
	void remove(int elem); // удаление элемента дерева по ключу
	size_t get_size();
	int at(size_t  index); // получение элемента по индексу
	void printf();


	Iterator* create_width_iterator(); 
	Iterator* create_depth_iterator();

	void print_complete(); // вывод дерева на экран 

	//bool is_equal(int *array1, const size_t size_array1, int *array2, const size_t size_array2);


};
