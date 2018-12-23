#pragma once
#include "iterator.h"

class width_iterator : public Iterator  // ����� width_iterator ��������� ������������ ������ Iterator
{
public:

	int *head;
	int current;
	int size;

	int next() override;
	bool has_next() override;
};
