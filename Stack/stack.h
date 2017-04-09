#ifndef STACK_INCLUDED
#define STACK_INCLUDED 1

#include <initializer_list>
#include <iostream>

class stack
{
	size_t current_size;
	size_t current_capacity;
	double* tab;

	friend std::ostream& operator << ( std::ostream& stream, const stack& s );

	void ensure_capacity(size_t c);
	
	public:

	stack();
	stack(std::initializer_list<double> d);
	stack(const stack& s);	
	~stack()
	{
		delete[] tab; 
	}
	void operator = (const stack& s);
	void push(double d);	
	void pop();
	void reset(size_t s);
	double& top() 
	{ 
		return tab[current_size-1];
	}
	double top() const 
	{
		return tab[current_size-1];
	}
	size_t size() const
	{ 
		return current_size;
	}
	bool empty( ) const 
	{
		return current_size == 0;
	}
};

#endif
