
#include <fstream>
#include <gtest.h>
#include "Matrix.h"

TEST(TMatrix, can_create_matrix)
{
  ASSERT_NO_THROW(TMatrix<int> M(3));
}

TEST(TMatrix, throw_when_create_matrix_with_negative_size)
{
  ASSERT_ANY_THROW(TMatrix<int> M(-3));
}

TEST(TMatrix, can_plus_matrix_equal_size)
{
  const int size = 3;
  TMatrix<int>M1(size), M2(size), expM(size);
  for (int i = 0; i < size; i++)
    for (int j = i; j < size; j++)
    {
      M1[i][j] = 1;
      M2[i][j] = 2;
      expM[i][j] = 3;
    }
  TMatrix<int> M3 = M1 + M2;
  EXPECT_EQ(expM, M3);
}

TEST(TMatrix, can_plus_matrix_non_equal_size_low_high)
{
  const int size1 = 3, size2 = 4;
  TMatrix<int>M1(size1), M2(size2), expM(size1);
  for (int i = 0; i < size1; i++)
    for (int j = i; j < size1; j++)
    {
      M1[i][j] = 1;
      expM[i][j] = 3;
    }
  for (int i = 0; i < size2; i++)
    for (int j = i; j < size2; j++)
      M2[i][j] = 2;
  TMatrix<int> M3 = M1 + M2;
  EXPECT_EQ(expM, M3);
}

TEST(TMatrix, can_plus_matrix_non_equal_size_high_low)
{
  const int size1 = 3, size2 = 4;
  TMatrix<int>M1(size1), M2(size2), expM(size2);
  for (int i = 0; i < size1; i++)
    for (int j = i; j < size1; j++)
    {
      M1[i][j] = 1;
      expM[i][j] = 3;
    }
  expM[0][3] = 2;
  expM[1][3] = 2;
  expM[2][3] = 2;
  expM[3][3] = 2;
  for (int i = 0; i < size2; i++)
    for (int j = i; j < size2; j++)
      M2[i][j] = 2;
  TMatrix<int> M3 = M2 + M1;
  EXPECT_EQ(expM, M3);
}

TEST(TMatrix, can_add_matrix_equal_size)
{
  const int size = 3;
  TMatrix<int>M1(size), M2(size), expM(size);
  for (int i = 0; i < size; i++)
    for (int j = i; j < size; j++)
    {
      M1[i][j] = 1;
      M2[i][j] = 2;
      expM[i][j] = 3;
    }
  M1 += M2;
  EXPECT_EQ(expM, M1);
}

TEST(TMatrix, can_add_matrix_non_equal_size_low_high)
{
  const int size1 = 3, size2 = 4;
  TMatrix<int>M1(size1), M2(size2), expM(size1);
  for (int i = 0; i < size1; i++)
    for (int j = i; j < size1; j++)
    {
      M1[i][j] = 1;
      expM[i][j] = 3;
    }
  for (int i = 0; i < size2; i++)
    for (int j = i; j < size2; j++)
      M2[i][j] = 2;
  M1 += M2;
  EXPECT_EQ(expM, M1);
}

TEST(TMatrix, can_add_matrix_non_equal_size_high_low)
{
  const int size1 = 3, size2 = 4;
  TMatrix<int>M1(size1), M2(size2), expM(size2);
  for (int i = 0; i < size1; i++)
    for (int j = i; j < size1; j++)
    {
      M1[i][j] = 1;
      expM[i][j] = 3;
    }
  expM[0][3] = 2;
  expM[1][3] = 2;
  expM[2][3] = 2;
  expM[3][3] = 2;
  for (int i = 0; i < size2; i++)
    for (int j = i; j < size2; j++)
      M2[i][j] = 2;
  M2 += M1;
  EXPECT_EQ(expM, M2);
}

TEST(TMatrix, can_write_matrix_to_file)
{
  const int size = 4;
  int k = 0;
  TMatrix<int> M(size);
  for (int i = 0; i < size; i++)
    for (int j = i; j < size; j++)
    {
      M[i][j] = k;
      k++;
    }
  ofstream fout("output.txt");
  fout << M;
  fout.close();
  string expS = "0123456789";
  string S = "";
  ifstream fin("output.txt");
  fin >> S;
  fin.close();
  EXPECT_EQ(expS, S);
}
