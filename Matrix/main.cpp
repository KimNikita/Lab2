#include <iostream>
#include "MyVector.h"
#include "Matrix.h"

int main()
{
  int n;
  cin >> n;
  TMatrix<int> M(n);
  for (int i = 0; i < n; i++)
    for (int j = M[i].StartIndex(); j < n; j++)
      cin >> M[i][j];
  cout << M;
  return 0;
}
