#pragma once
#include "iterator.h"

class depth_iterator : public Iterator // ����� depth_iterator ��������� ������������ ������ Iterator
{
public:
	int *head;
	int current;
	int size;
	bool *visited; // ������� ���� �� �� ��� � ���� ���� ��� ��� 

	bool has_next() override;
	int next() override;
};
