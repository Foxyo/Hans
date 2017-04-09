#include "string.h"



std::ostream& operator << ( std::ostream& out, const string& s )
{
   for(char c : s)
      out << c;
   return out; 
}

char string::operator [] (size_t i) const {return p[i];}
char& string::operator [] (size_t i) {return p[i];}
string operator + (string s1, const string &s2)
{
		string s3 = s1;
		s3 += s2;
		return s3;
		
}

bool operator == ( const string& s1, const string& s2)
{
	if(s1.len != s2.len)
		return false;
	
	for(size_t i = 0; i < s1.len; ++i)
	{
		if(s1.p[i] != s2.p[i])
			return false;
	}
	return true;
	
}
bool operator != (const string& s1, const string& s2)
{
	return !(s1 == s2);
}
bool operator < (const string& s1, const string& s2)
{
	size_t tlen = std::min(s1.len, s2.len);
	for(size_t i = 0; i < tlen; ++i)
	{// b aa
		if(s1.p[i] < s2.p[i])
			return true;
		if(s1.p[i] > s2.p[i])
			return false;
	}
	if(s1.len < s2.len)
		return true;
	else return false;
}

	
bool operator > (const string& s1, const string& s2)
{
	/*size_t tlen = std::min(s1.len, s2.len);
	for(int i = 0; i < tlen; ++i)
	{
		if(s1.p[i] > s2.p[i])
			return true;
	}
	if(s1.len > s2.len)
		return true;
	else return false;*/
	return (s2<s1); // 
}
bool operator <= (const string& s1, const string& s2)
{
	return !(s1>s2);
}
bool operator >= (const string& s1, const string& s2)
{
	return !(s1<s2);
}

