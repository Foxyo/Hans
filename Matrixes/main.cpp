
#include "rational.h"
#include "matrix.h"

int main( int argc, char* argv [ ] )
{
   rational r1(1, 2);
   rational r2(-2, 7); 
   rational r3(1, 3);
   rational r4(2, 8);

   rational r5(-1, 3);
   rational r6(2, 5);
   rational r7(2, 7);
   rational r8(-1, 7);

   rational r9(2, 6);
   rational r10(4, 3);
   rational r11(5, 6);
   rational r12(1, 2);


   matrix m1 = { {r1, r2}, {r3, r4} };
   matrix m2 = { {r5, r6}, {r7,r8} };
   matrix m3 = { {r9, r10}, {r11, r12} };
   //std::cout << m1 << "\n" << m2 << "\n";
   std::cout << "Task 1" << "\n";
   std::cout << m1*m2 << "\n";

   std::cout << "Task 2" << "\n";
   std::cout << m1.inverse() << "\n";

   std::cout << "Task 3. Matrix mult. is associative" << "\n";
   matrix m4 = (m1*m2)*m3;
   matrix m5 = m1*(m2*m3);
   std::cout << "Left side\n" << m4 << "\n";
   std::cout << "Right side\n" << m5 << "\n";

   std::cout << "Task 4. Matrix mult. and add. are distr." << "\n";
   matrix m6 = m1*(m2+m3);
   matrix m7 = m1*m2 + m1*m3;
   matrix m8 = (m1+m2)*m3;
   matrix m9 = m1*m3 + m2*m3;
   std::cout << "Part 1 Left side\n" << m6 << "\n";
   std::cout << "Part 1 Right side\n" << m7 << "\n";
   std::cout << "Part 2 Left side\n" << m8 << "\n";
   std::cout << "Part 2 Right side\n" << m9 << "\n";
   
   std::cout << "Part 5. Matrix multiplication corresponds to composition of application\n";
   vector v(r1,r2);
   std::cout << "Left side\n" << m1(m2(v)) << "\n";
   std::cout << "Right side\n" << (m1*m2)(v) << "\n";

   std::cout << "Task 6. Determinant commutes over multiplication\n";
   std::cout << "Left side\n" << m1.determinant() * m2.determinant() << "\n";
   std::cout << "Right side\n" << (m1*m2).determinant() << "\n";

   std::cout << "Task 7. Inverse are indeed inverse\n";
   std::cout << "Left side\n";
   matrix m10 = m3.inverse();
   matrix m11 = m10.inverse();
   std::cout << m3 << "\n" << m11 << "\n";
   

}

