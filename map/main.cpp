#include <iostream>
#include <fstream>
#include "map.h"

int main()
{
	std::fstream f;
	f.open("1.html");
	std::vector <std::string> v = readfile(f);
	std::map<std::string, unsigned int, case_insensitive_cmp> map= frequencytable( v);
	//std::cout << m;
	std::cout << "magnus => " << map.find("magnus")->second << "\n";
	std::cout << "hominum => " << map.find("hominum")->second << "\n";
	std::cout << "memoria => " << map.find("memoria")->second << "\n";
	std::map<std::string, unsigned int, case_insensitive_cmp> s;
	frequent_word(map);
	case_insensitive_hash h;
	std::cout << h( "xxx" ) << " " << h( "XXX" ) << "\n";
	std::cout << h( "Abc" ) << " " << h( "abC" ) << "\n";
	// Hash value should be case insensitive.
	case_insensitive_equality e;
	std::cout << e( "xxx", "XXX" ) << "\n";
	// Prints ’1’.
}
