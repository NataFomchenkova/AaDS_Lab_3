#include "stdafx.h"
#include "width_iterator.h"


int width_iterator::next() // ���������� ����
{
	int elem = head[current];
	current ++;
	return elem;
}

bool width_iterator::has_next() // ��������: �� ���� �� ����� �� ����
{
	if (current != size) 
		return true;
	return false;
}
