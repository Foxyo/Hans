#ifndef LISTTEST_INCLUDED
#define LISTTEST_INCLUDED   1

#include <list>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>


namespace listtest
{

   std::list<std::string> readfile( std::istream& input );


   std::list<std::string> randomstrings( size_t nr, size_t s );

   void sort_assign( std::list< std::string > & v );

   void sort_move( std::list< std::string > & v );

   void sort_list( std::list< std::string > & v );

}

std::list<std::string> vectorToList(std::vector<std::string>& vect);

std::ostream&
operator << ( std::ostream& stream, const std::list< std::string > & list);

   // Must be not in namespace.

#endif
