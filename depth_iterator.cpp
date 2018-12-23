#include "stdafx.h"
#include "depth_iterator.h"



bool depth_iterator::has_next() // ��������: ���� �� �� ����
{
	for (size_t i = 0; i < size; i++) // ���� ���� ������������ ����, �������� ������
		if (visited[i] == false)
			return true;
	return false;
}

int depth_iterator::next()
{
	int elem = head[current];
	while (true)
	{
		if (current * 2 + 1 < size) // ����� � ������� �� ����� �������� 
			if (visited[current * 2 + 1] == false)
			{
				visited[current] = true;
				current = current * 2 + 1;
				return elem;
			}
		if (current * 2 + 2 < size) // ����� � ������� �� ������ �������� 
			if (visited[current * 2 + 2] == false)
			{
				visited[current] = true;
				current = current * 2 + 2;
				return elem;
			}
		visited[current] = true; // �������� ����, ���� �������� ��������, ��� ����������
		if (!(has_next())) 
			return head[current]; // ���������� ����, ���� �������� ��������
		current = (current - 1) / 2; // ���������� �� ���� ������� ����� 
	}
}