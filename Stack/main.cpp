#include <iostream>
#include "stack.h"
using namespace std;
int main()
{
	stack s1 = { 1, 2, 3, 4, 5 };
	cout <<"Stack No. 1" << s1 <<  endl;
	stack s2 = s1;
	cout <<"Copying" << s2 << endl;
	// j is not size_t, because multiplying size_t with itself is
// unnatural:
	for(unsigned int j = 0; j < 20; ++j)
		s2.push(j * j);
	cout<<"Pushing to stack" << s2 << endl;
	s1 = s2;
	cout<<"Assignment:" << endl;
	cout<<"Stack 1:" << s1 << endl;
	cout<<"Stack 2:" << s2 << endl;
	s1 = s1;
	cout << "Self assignment" << s1 << endl;
	s1 = { 100,101,102,103 };
// Works because the compiler inserts constructor and
// calls assignment with the result.
#if 0
// Won’t compile. In order to get it compiled, remove const:
stack& sconst = s1;
sconst. top( ) = 20;
sconst. push(15);
#endif	
}
