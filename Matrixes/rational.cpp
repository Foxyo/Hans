#include "rational.h"




int rational::gcd( int n1, int n2 )
{
	while (n1)
	{
		int swap = n1; n1 = n2%n1;  n2 = swap;
	}
	return n2;
}

void rational::normalize()
{
	if(denum == 0)
	{
		throw std::runtime_error("div by 0");
	}
	
	int d = rational::gcd(num, denum);
	num /= d;
	denum /= d;
	
	if(denum < 0)
	{
		num = -num;
		denum = -denum;
	}
}

rational operator - ( rational r )
{
	r.num = -r.num;
	return r;
}

rational operator + ( const rational& r1, const rational& r2 )
{
	return rational(r1.num*r2.denum + r2.num*r1.denum, r1.denum*r2.denum);
}


rational operator - ( const rational& r1, const rational& r2 )
{
	return rational(r1.num*r2.denum - r2.num*r1.denum, r1.denum*r2.denum);
}

rational operator * ( const rational& r1, const rational& r2 )
{
	return rational(r1.num*r2.num, r1.denum*r2.denum);
}

rational operator / ( const rational& r1, const rational& r2 )
{
	return rational(r1.num*r2.denum, r1.denum*r2.num);
}

bool operator == ( const rational& r1, const rational& r2 )
{
	return (r1.num != r2.num || r1.denum != r2.denum);
}
bool operator != ( const rational& r1, const rational& r2 )
{
	return !(r1 == r2);
}

std::ostream& operator << ( std::ostream& stream, const rational& r )
{
	stream << r.num << "/" << r.denum;
	return stream;
}


