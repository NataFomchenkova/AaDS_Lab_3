#pragma once


class Iterator
{
public:

	virtual bool has_next() = 0; // есть ли еще необойденный элемент
	virtual int next() = 0; // обход
};
