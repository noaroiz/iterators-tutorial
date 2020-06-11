#ifndef ALG_H_
#define ALG_H_

#include<stdio.h>
#include<iostream>
using namespace std;
template<class itr>
itr Add_n(itr b, itr e, int n)
{
	if (b == e)
		return e;
	typename std::iterator_traits<itr>::value_type sum;
	int place_in_contaner = 0;
	auto it_in = b;
	bool isOver=false;
	for (auto it = b; it != e; ++it)
	{
		it_in = b + (place_in_contaner * n);
		if (it_in != e)
			sum = *it_in;
		else return it;
		for (int i = 1; i < n; i++)
		{
			if ((it_in + i) == e)
			{
				isOver = true;
				break;
			}
			sum += *(it_in + i);
		}
		*it = sum;
		if (isOver)
			return (it + 1);
		place_in_contaner++;
	}
	return e;
	}

template<class itr>

itr transpose(itr b, itr e)
{
	for (auto it = b; it != e; ++it)
	{
		if ((it + 1) == e)
			return it;
		iter_swap(it, it + 1);
		it++;
	}
	return e;
}

template<class itr,class iter_o, typename T>
iter_o transform(itr b, itr e,iter_o o,T func)
{
	if (distance(b, e) % 2 != 0)
		return o;
	for (auto it = b; it != e; ++it)
	{
		if ((it + 1) == e)
			return o;
		*o=func(*it, *(it+1));
		it++;
		o++;
	}
	return (o);
}
#endif // !ALG_H_