#pragma once
#include "iterator.h"

class width_iterator : public Iterator  // класс width_iterator наследник виртуального класса Iterator
{
public:

	int *head;
	int current;
	int size;

	int next() override;
	bool has_next() override;
};
