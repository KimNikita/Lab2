#ifndef _MY_VECTOR_
#define _MY_VECTOR_

#include <iostream>
#include <algorithm>

using namespace std;

template <class T>
class TVector
{
protected:
  int length;
  int start_index;
  T* vec;
public:
  TVector(int l = 0, int si = 0);
  TVector(const TVector<T>& v);
  ~TVector();

  TVector<T>& operator=(const TVector<T>& a);
  TVector<T> operator+(const TVector<T>& a);
  TVector<T> operator-(const TVector<T>& a);
  TVector<T> operator*(const TVector<T>& a);
  TVector<T> operator/(const TVector<T>& a);
  TVector<T>& operator+=(const TVector<T>& a);
  TVector<T>& operator-=(const TVector<T>& a);

  bool operator==(const TVector<T> a)const;
  int Length();
  int StartIndex();
  T& operator[] (const int index);

  friend ostream& operator<<(ostream& ostr, const TVector<T>& A);
  friend istream& operator>>(istream& istr, TVector<T>& A);
};

template<class T>
inline TVector<T>::TVector(int l, int si)
{
  if (l < 0 || si < 0)
    throw exception();
  length = l;
  start_index = si;
  vec = new T[l];
}

template <class T>
inline TVector<T>::TVector(const TVector<T>& a)
{
  length = a.length;
  start_index = a.start_index;
  vec = new T[length];
  for (int i = 0; i < length; i++)
    vec[i] = a.vec[i];
}

template <class T>
inline TVector<T>::~TVector()
{
  length = 0;
  start_index = 0;
  if (vec != 0)
    delete[] vec;
  vec = 0;
}

template <class T>
inline TVector<T>& TVector<T>::operator=(const TVector<T>& a)
{
  if (this == &a)
    return *this;
  if (length != a.length)
  {
    delete[] vec;
    vec = new T[a.length];
  }
  length = a.length;
  start_index = a.start_index;
  for (int i = 0; i < length; i++)
    vec[i] = a.vec[i];
  return *this;
}

template <class T>
inline TVector<T> TVector<T>::operator+(const TVector<T>& a)
{
  int cur_length = min(length, a.length);
  TVector<T> res(*this);
  for (int i = 0; i < cur_length; i++)
    res.vec[i] = vec[i] + a.vec[i];
  return res;
}

template <class T>
inline TVector<T> TVector<T>::operator-(const TVector<T>& a)
{
  int cur_length = min(length, a.length);
  TVector<T> res(*this);
  for (int i = 0; i < cur_length; i++)
    res.vec[i] = vec[i] - a.vec[i];
  return res;
}

template <class T>
inline TVector<T> TVector<T>::operator*(const TVector<T>& a)
{
  int cur_length = min(length, a.length);
  TVector<T> res(*this);
  for (int i = 0; i < cur_length; i++)
    res.vec[i] = vec[i] * a.vec[i];
  return res;
}

template <class T>
inline TVector<T> TVector<T>::operator/(const TVector<T>& a)
{
  int cur_length = min(length, a.length);
  TVector<T> res(*this);
  for (int i = 0; i < cur_length; i++)
    res.vec[i] = vec[i] / a.vec[i];
  return res;
}

template <class T>
inline TVector<T>& TVector<T>::operator+=(const TVector<T>& a)
{
  int cur_length = min(length, a.length);
  for (int i = 0; i < cur_length; i++)
    vec[i] += a.vec[i];
  return *this;
}

template <class T>
inline TVector<T>& TVector<T>::operator-=(const TVector<T>& a)
{
  int cur_length = min(length, a.length);
  for (int i = 0; i < cur_length; i++)
    vec[i] -= a.vec[i];
  return *this;
}

template<class T>
inline bool TVector<T>::operator==(const TVector<T> a)const
{
  if (a.length != length || a.start_index != start_index)
    return false;
  for (int i = 0; i < length; i++)
    if (!(vec[i] == a.vec[i]))
      return false;
  return true;
}

template <class T>
inline int TVector<T>::Length()
{
  return length;
}

template <class T>
inline int TVector<T>::StartIndex()
{
  return start_index;
}

template<class T>
inline T& TVector<T>::operator[](const int index)
{
  if (index - start_index < 0 || index - start_index >= length)
    throw exception();
  return vec[index - start_index];
}

template <class T>
inline ostream& operator<<(ostream& ostr, const TVector<T>& A) {
  for (int i = 0; i < A.length; i++)
    ostr << A.vec[i] << ' ';
  return ostr;
}

template <class T>
inline istream& operator>>(istream& istr, TVector<T>& A) {
  for (int i = 0; i < A.length; i++)
    istr >> A.vec[i];
  return istr;
}
#endif