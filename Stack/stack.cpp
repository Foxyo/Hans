#include <initializer_list>
#include "stack.h"

void stack::ensure_capacity(size_t c)
{
	if(current_capacity < c)
	{
		if(c < 2 * current_capacity)
			c = 2 * current_capacity;

		double* newtab = new double[c];

		for(size_t i = 0; i < current_size; ++i)
			 newtab[i] = tab[i];

		current_capacity = c;
		delete[] tab;
		tab = newtab;
	}
}

void stack::push(double d)
{
	ensure_capacity(current_size + 1);
	tab[current_size]=d;
	current_size++;
}

void stack::pop()
{
	current_size--;
}

void stack::reset(size_t s)
{
	current_size = s;
}	

stack::stack():
	current_size{0},
	current_capacity{0},
	tab{new double [0]} {}

stack::stack(const stack &s):
	current_size{s.current_size},
	current_capacity{s.current_capacity}, 
	tab{new double[s.current_capacity]}
	{
		for(size_t i = 0; i < s.current_size; i++)
			tab[i] = s.tab[i];
	}

stack::stack(std::initializer_list<double> d):
	current_size{d.size()},
	current_capacity{d.size()}, 
	tab{new double [d.size()]}
	{
		std::copy(d.begin(), d.end(), tab);
	}

void stack::operator = (const stack &s)
{
	if(s.tab!=tab)
	{	
		delete[] tab;
		tab = new double[s.current_capacity];
		current_size = s.current_size;
		current_capacity = s.current_capacity;
		for(size_t i = 0; i < s.current_size; i++)
			tab[i] = s.tab[i]; 
	}
}

std::ostream& operator << ( std::ostream& stream, const stack& s )
{
	for(size_t i=0; i<s.current_size; i++)
			stream << " " << s.tab[i];
	return stream;
}
