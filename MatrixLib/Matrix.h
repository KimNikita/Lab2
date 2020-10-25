#pragma once
#include "MyVector.h"

template <class T>
class TMatrix : public TVector<TVector<T>>
{
public:
  TMatrix(int size = 0);
  TMatrix(const TMatrix<T>& m);
  ~TMatrix();

  TMatrix<T>& operator=(const TMatrix<T>& m);
  TMatrix<T> operator+(const TMatrix<T>& m);
  TMatrix<T> operator-(const TMatrix<T>& m);
  TMatrix<T> operator*(const TMatrix<T>& m);
  TMatrix<T> operator/(const TMatrix<T>& m);
  TMatrix<T>& operator+=(const TMatrix<T>& m);
  TMatrix<T>& operator-=(const TMatrix<T>& m);

  template <class T>
  friend ostream& operator<<(ostream& ostr, const TMatrix<T>& M);
  template <class T>
  friend istream& operator>>(istream& istr, TMatrix<T>& M);
  template <class T>
  friend ofstream& operator<<(ofstream& ofstr, const TMatrix<T>& M);

};

template<class T>
inline TMatrix<T>::TMatrix(int size) : TVector<TVector<T>>(size)
{
  if (size < 0)
    throw exception();
  for (int i = 0; i < size; i++)
    vec[i] = TVector<T>(size - i, i);
}

template<class T>
inline TMatrix<T>::TMatrix(const TMatrix<T>& m) : TVector<TVector<T>>(m)
{
}

template<class T>
inline TMatrix<T>::~TMatrix()
{
}

template<class T>
inline TMatrix<T>& TMatrix<T>::operator=(const TMatrix<T>& m)
{
  if (this != &m)
    TVector<TVector<T>>::operator =(m);
  return *this;
}

template<class T>
inline TMatrix<T> TMatrix<T>::operator+(const TMatrix<T>& m)
{
  TMatrix<T> temp(*this);
  int cur_length = min(temp.length, m.length);
  for (int i = 0; i < cur_length; i++)
    temp.vec[i] = temp.vec[i] + m.vec[i];
  return temp;
}

template<class T>
inline TMatrix<T> TMatrix<T>::operator-(const TMatrix<T>& m)
{
  TMatrix<T> temp(*this);
  int cur_length = min(temp.length, m.length);
  for (int i = 0; i < cur_length; i++)
    temp.vec[i] = temp.vec[i] - m.vec[i];
  return temp;
}

template<class T>
inline TMatrix<T> TMatrix<T>::operator*(const TMatrix<T>& m)
{
  TMatrix<T> temp(*this);
  int cur_length = min(temp.length, m.length);
  for (int i = 0; i < cur_length; i++)
    temp.vec[i] = temp.vec[i] * m.vec[i];
  return temp;
}

template<class T>
inline TMatrix<T> TMatrix<T>::operator/(const TMatrix<T>& m)
{
  TMatrix<T> temp(*this);
  int cur_length = min(temp.length, m.length);
  for (int i = 0; i < cur_length; i++)
    temp.vec[i] = temp.vec[i] / m.vec[i];
  return temp;
}

template<class T>
inline TMatrix<T>& TMatrix<T>::operator+=(const TMatrix<T>& m)
{
  int cur_length = min(length, m.length);
  for (int i = 0; i < cur_length; i++)
    vec[i] += m.vec[i];
  return *this;
}

template<class T>
inline TMatrix<T>& TMatrix<T>::operator-=(const TMatrix<T>& m)
{
  int cur_length = min(length, m.length);
  for (int i = 0; i < cur_length; i++)
    vec[i] -= m.vec[i];
  return *this;
}

template<class T>
inline ostream& operator<<(ostream& ostr, const TMatrix<T>& M)
{
  TMatrix<T> temp(M);
  for (int i = 0; i < temp.Length(); i++)
  {
    for (int k = 0; k < i; k++)
      ostr << ' ' << ' ';
    for (int j = temp[i].StartIndex(); j < temp.Length(); j++)
      ostr << temp[i][j] << ' ';
    ostr << endl;
  }
  return ostr;
}

template<class T>
inline istream& operator>>(istream& istr, TMatrix<T>& M)
{
  for (int i = 0; i < M.Length(); i++)
    for (int j = M[i].StartIndex(); j < M.Length(); j++)
      istr >> M[i][j];
  return istr;
}

template <class T>
inline ofstream& operator<<(ofstream& ofstr, const TMatrix<T>& M)
{
  TMatrix<T> temp(M);
  for (int i = 0; i < temp.Length(); i++)
    for (int j = temp[i].StartIndex(); j < temp.Length(); j++)
      ofstr << temp[i][j];
  return ofstr;
}
