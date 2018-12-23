#include "stdafx.h"
#include "width_iterator.h"


int width_iterator::next() // возвращает ключ
{
	int elem = head[current];
	current ++;
	return elem;
}

bool width_iterator::has_next() // проверка: во всех ли узлах мы были
{
	if (current != size) 
		return true;
	return false;
}
