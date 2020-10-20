#include <iostream>
#include "MyVector.h"
#include "Matrix.h"

int main()
{
  Vector<int> a(3, 3);
  TMatrix<int> A(3);

  std::cout << a << "\nHi\n";
  return 0;
}
