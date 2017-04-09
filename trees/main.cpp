#include "tree.h"


int main()
{
   tree t1( string( "a" ));
   tree t2( string( "b" ));
   tree t3 = tree( string( "f" ), { t1, t2 } );

   std::vector< tree > arguments = { t1, t2, t3 };
   std::cout << tree( "F", std::move( arguments )) << "\n";

   t2 = t3;
   t2 = std::move(t3);

   tree t4(string("123"));
   tree t5(string("456"));
   tree t6(string("789"));
   tree val(string("777"));

   string var = "789";
   string var2 = "683";


   tree t7 = tree(string("Test1"), {t4, t5, t6});
   std::cout << t7;

   tree test2 = subst(t7, var, val);
   std::cout << test2;
   tree test3 = subst(t7, var2, val);
   std::cout << test3;


   tree a(string("a"));
   tree b(string("b"));
   tree g(string("g"), {a, b});
   tree f(string("f"), {g});

   std::cout << f << std::endl;
   std::cout << subst(f, "c", val) << std::endl;
   std::cout << subst(f, "b", val) << std::endl;



}
