#include <fstream>
#include <iostream>
#include <random>

#include "listtest.h"
#include "vectortest.h"
#include "timer.h"

void testVecSorts(std::vector< std::string > vect, int sort)
{
   if(sort == 0)
   {
   for(int i = 1; i <= 3; i++)
       testVecSorts(vect, i);
   }

   if(sort != 0)
   {
       auto t1 = std::chrono::high_resolution_clock::now( );

       if(sort == 1)
       {
           vectortest::sort_assign(vect);
           std::cout << "vector sort_assign" << std::endl;
       }
       else if(sort == 2)
       {
           vectortest::sort_move(vect);
           std::cout << "vector sort_move" << std::endl;
       }
       else {
           vectortest::sort_std (vect);
           std::cout << "vector sort_std" << std::endl;
       }

       auto t2 = std::chrono::high_resolution_clock::now( );
       std::chrono::duration< double > d = ( t2 - t1 );
       std::cout << "sorting took " << d.count( ) << " seconds\n" << std::endl;
   }
}

void testListSorts(std::list<std::string> list, int sort)
{
   if(sort == 0)
   {
       for(int i = 1; i <= 3; i++)
           testListSorts(list, i);
   }

   if(sort != 0)
   {
       auto t1 = std::chrono::high_resolution_clock::now( );

       if(sort == 1)
       {
           listtest::sort_assign(list);
           std::cout << "list sort_assign" << std::endl;
       }
       else if(sort == 2)
       {
           listtest::sort_move(list);
           std::cout << "list sort_move" << std::endl;
       }
       else {
           listtest::sort_list(list);
           std::cout << "list sort_list" << std::endl;
       }

       auto t2 = std::chrono::high_resolution_clock::now( );
       std::chrono::duration< double > d = ( t2 - t1 );
       std::cout << "sorting took " << d.count( ) << " seconds\n" << std::endl;
   }

}

int main()
{

   std::vector<std::string> test = vectortest::randomstrings(5500, 5500);
   std::vector<std::string> test2 = vectortest::randomstrings(5500, 5500);
   std::vector<std::string> test3 = vectortest::randomstrings(10, 10);
   std::list<std::string> test4 = vectorToList(test2);
   std::list<std::string> test5 = vectorToList(test3);

   listtest::sort_assign(test5);


   std::cout << test5 << std::endl;



   testVecSorts(test, 0);
   testListSorts(test4, 0);
   return 0;
}
