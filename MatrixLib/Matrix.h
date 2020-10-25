#pragma once
#include "MyVector.h"

template <class T>
class TMatrix : public TVector<TVector<T> >
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

  template <class T1>
  friend ostream& operator<<(ostream& ostr, const TMatrix<T1>& M);
  template <class T1>
  friend istream& operator>>(istream& istr, TMatrix<T1>& M);
  template <class T1>
  friend ofstream& operator<<(ofstream& ofstr, const TMatrix<T1>& M);
};

template<class T>
inline TMatrix<T>::TMatrix(int size) : TVector<TVector<T> >(size)
{
  if (size < 0)
    throw exception();
  for (int i = 0; i < size; i++)
    this->vec[i] = TVector<T>(size - i, i);
}

template<class T>
inline TMatrix<T>::TMatrix(const TMatrix<T>& m) : TVector<TVector<T> >(m)
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
    TVector<TVector<T> >::operator =(m);
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
  int cur_length = min(this->length, m.length);
  for (int i = 0; i < cur_length; i++)
    this->vec[i] += m.vec[i];
  return *this;
}

template<class T>
inline TMatrix<T>& TMatrix<T>::operator-=(const TMatrix<T>& m)
{
  int cur_length = min(this->length, m.length);
  for (int i = 0; i < cur_length; i++)
    this->vec[i] -= m.vec[i];
  return *this;
}

template<class T1>
inline ostream& operator<<(ostream& ostr, const TMatrix<T1>& M)
{
  TMatrix<T1> temp(M);
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

template<class T1>
inline istream& operator>>(istream& istr, TMatrix<T1>& M)
{
  for (int i = 0; i < M.Length(); i++)
    for (int j = M[i].StartIndex(); j < M.Length(); j++)
      istr >> M[i][j];
  return istr;
}

template <class T1>
inline ofstream& operator<<(ofstream& ofstr, const TMatrix<T1>& M)
{
  TMatrix<T1> temp(M);
  for (int i = 0; i < temp.Length(); i++)
    for (int j = temp[i].StartIndex(); j < temp.Length(); j++)
      ofstr << temp[i][j];
  return ofstr;
}
