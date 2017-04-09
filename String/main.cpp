#include "string.h"
#include <iostream>



int main()
{
   // Add more tests by yourself. Untested code = unwritten code. 

	string s;
	string s2 = "hello";
	std::cout << s << std::endl;
	std::cout << s2 << std::endl;
	std::cout << s2[0] << std::endl;
	std::cout << s2[1] << std::endl;
	std::cout << s2[2] << std::endl;
	std::cout << s2[3] << std::endl;
	std::cout << s2[4] << std::endl;


	s = s2;  // Assignment, not initialization.
	std::cout << "	Assignment of a string" << std::endl;
	std::cout << s << std::endl;
	std::cout << "	Self assignment" << std::endl;
	s = s;
	std::cout << s << std::endl;
	
	char c = 's';
	//std::cout << s.len << std::endl;
	std::cout << "	Adding a character to string" << std::endl;
	s+=c;
	//std::cout << s.len << std::endl;
	std::cout << s << std::endl;
	std::cout << "	Self-adding string" << std::endl;
	s+=s;
	//std::cout << s.len << std::endl;
	std::cout << s << std::endl;
	string s3 = "witam";
	std::cout << "	Adding a string to string" << std::endl;
	std::cout << s2+s3 << std::endl;
	s = "this is a string";
	std::cout << s << "\n";
	for( char& c : s )
	c = toupper(c);
	std::cout << s << "\n";

	
	string row1 = "row";
	string row2 = row1;
	string row3 = "wor";
	std::cout << "s1: " << row1 << " s2: " << row2 << " s3: " << row3 << std::endl;
	std::cout << "s1 == s2" << std::endl;
	std::cout << (row1==row2) << std::endl;
	std::cout << "s1 == s3" << std::endl;
	std::cout << (row1==row3) << std::endl;
	std::cout << "s1 != s2" << std::endl;
	std::cout << (row1!=row2) << std::endl;
	std::cout << "s1 != s3" << std::endl;
	std::cout << (row1!=row3) << std::endl;
	std::cout << "s1 < s2" << std::endl;
	std::cout << (row1<row2) << std::endl;
	std::cout << "s1 > s2" << std::endl;
	std::cout << (row1>row2) << std::endl;
	
	string eq1 = "aaa";
	string eq2 = "abb";
	std::cout << "s1: " << eq1 << " s2: " << eq2 << std::endl;
	
	std::cout << "s1 < s2" << std::endl;
	std::cout << (eq1<eq2) << std::endl;
	std::cout << "s2 < s1" << std::endl;
	std::cout << (eq2<eq1) << std::endl;
	std::cout << "s1 > s2" << std::endl;
	std::cout << (eq1>eq2) << std::endl;
	std::cout << "s2 > s1" << std::endl;
	std::cout << (eq2>eq1) << std::endl;
	std::cout << "s1 <= s2" << std::endl;
	std::cout << (eq1<=eq2) << std::endl;
	std::cout << "s2 <= s1" << std::endl;
	std::cout << (eq2<=eq1) << std::endl;
	std::cout << "s1 >= s2" << std::endl;
	std::cout << (eq1>=eq2) << std::endl;
	std::cout << "s2 >= s1" << std::endl;
	std::cout << (eq2>=eq1) << std::endl;

	string aa = "aa";
	string b = "b";
	std::cout << (aa<eq1) << std::endl;
	std::cout << (b<aa) << std::endl;
	
	
	
	
   // std::cout << "s = " << s << "\n";
}

