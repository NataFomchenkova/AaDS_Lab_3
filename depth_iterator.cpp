#include "stdafx.h"
#include "depth_iterator.h"



bool depth_iterator::has_next() // проверка: были ли во всех
{
	for (size_t i = 0; i < size; i++) // если есть непосещенные узлы, работаем дальше
		if (visited[i] == false)
			return true;
	return false;
}

int depth_iterator::next()
{
	int elem = head[current];
	while (true)
	{
		if (current * 2 + 1 < size) // обход в глубину по левым потомкам 
			if (visited[current * 2 + 1] == false)
			{
				visited[current] = true;
				current = current * 2 + 1;
				return elem;
			}
		if (current * 2 + 2 < size) // обход в глубину по правым потомкам 
			if (visited[current * 2 + 2] == false)
			{
				visited[current] = true;
				current = current * 2 + 2;
				return elem;
			}
		visited[current] = true; // отмечаем узел, чьих потомков посещали, как пройденный
		if (!(has_next())) 
			return head[current]; // возвращаем узел, чьих потомков посещали
		current = (current - 1) / 2; // поднимаемя на один уровень вверх 
	}
}
