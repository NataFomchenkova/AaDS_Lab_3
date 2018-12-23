#pragma once
#include "iterator.h"

class depth_iterator : public Iterator // класс depth_iterator наследник виртуального класса Iterator
{
public:
	int *head;
	int current;
	int size;
	bool *visited; // пометка были ли мы уже в этом узле или нет 

	bool has_next() override;
	int next() override;
};
