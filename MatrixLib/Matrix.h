#pragma once
#include "MyVector.h"

template <class T>
class TMatrix : public Vector<Vector<T>>
{
public:
  TMatrix(int _size = 0);
  TMatrix(const TMatrix<T>& A);
  ~TMatrix();
};

template<class T>
inline TMatrix<T>::TMatrix(int _size) : Vector<Vector<T>>(_size)
{

}

template<class T>
inline TMatrix<T>::TMatrix(const TMatrix<T>& A) : Vector<Vector<T>>(A)
{

}

template<class T>
inline TMatrix<T>::~TMatrix()
{

}
