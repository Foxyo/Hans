
#ifndef STRING_INCLUDED 
#define STRING_INCLUDED 1

#include <iostream> 
#include <cstring>

class string
{
   size_t len;
   char *p; 

public: 
	
	string( ): 
	len(0),
	p(nullptr){}   // Works, see the slides. 

	string(const char* s): 
	len{strlen(s)},
	p{new char[len]}
	{
		for(size_t i = 0; i < len; ++i)
	 		p[i] = s[i]; 
	}

	string(const string& s): 
	len{s.len},
	p{new char[ len ]}
	{
		for(size_t i = 0; i < len; ++i)
			p[i] = s.p[i]; 
	}

	void operator = (const string& s)
	{ 
	if(len != s.len)
	{
		delete[] p; 
		len = s.len;
		p = new char[len];
	}

	for(size_t i = 0; i < len; ++i)
		p[i] = s.p[i];
	}

	size_t size() const {return len;}

	~string( )
	{
	delete[] p;
	}

	char operator [] (size_t i) const;
	char& operator [] (size_t i);
	void operator += (char c)
	{
		char *t = new char[len+1];
		for(size_t i = 0; i < len; ++i)
			t[i] = p[i];
		delete[] p;
                t[len] = c;
                p = t;
	}
	void operator += (const string& s)
	{
		char *t;
		t = new char[len + s.len];
		for(size_t i = 0; i < len; ++i)
		{	t[i] = p[i];
			//std::cout << t[i] << std::endl;
			//std::cout << p[i] << std::endl;
		}

		for(size_t i = 0; i < s.len; ++i)
		{	t[i + len] = s.p[i];
			//std::cout << t[i + slen] << std::endl;
			//std::cout << s.p[i] << std::endl;
		}
		delete[] p;
		len += s.len;		
		p = t;
		
	}

	using iterator = char* ;
	using const_iterator = const char* ;
	const_iterator begin( ) const { return p; }
	const_iterator end( ) const { return p + len; }
	iterator begin( ) { return p; }
	iterator end( ) { return p + len; }
	
	friend bool operator == (const string& s1, const string& s2);
	friend bool operator != (const string& s1, const string& s2);
	friend bool operator < (const string& s1, const string& s2);
	friend bool operator > (const string& s1, const string& s2);
	friend bool operator <= (const string& s1, const string& s2);
	friend bool operator >= (const string& s1, const string& s2);

	
		
	

};

std::ostream& operator << (std::ostream& out, const string& s);
string operator + (string s1, const string &s2);



#endif

