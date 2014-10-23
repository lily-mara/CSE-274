/*
 * LinearHashTable.h
 *
 *  Created on: 2011-12-16
 *      Author: morin
 */

#ifndef LINEARHASHTABLE_H_
#define LINEARHASHTABLE_H_
#include <climits>
#include <iostream>
using namespace std;
#include "array.h"
namespace ods {

extern unsigned int tab[4][256];

template<class T>
class LinearHashTable {

  static const int w = 32;
  static const int r = 8;
  array<T> front;
  array<T> back;
  int n;   // number of values in T
  int q;   // number of non-null entries in T
  int d;   // t.length = 2^d
  T null, del;
  void resize();
  int hash(T x) {
    return (unsigned) (x % (1 << d));
  }
  // Sample code for the book only -- never use this
  /*
   int idealHash(T x) {
   return tab[hashCode(x) >> w-d];
   }
   */

public:
  // FIXME: get rid of default constructor
  LinearHashTable();
  LinearHashTable(T null, T del);
  virtual ~LinearHashTable();
  bool add(T x);
  bool addSlow(T x);
  T remove(T x);
  T find(T x);
  int size() {
    return n;
  }
  void clear();
  // FIXME: yuck
  void setNull(T null) {
    this->null = null;
    front.fill(null);
    back.fill(null);
  }
  void setDel(T del) {
    this->del = del;
  }
};

/**
 * FIXME: Dangerous - leaves null and del uninitialized
 */
template<class T>
LinearHashTable<T>::LinearHashTable() :
    front(2), back(2) {
  /*
   this->null = null;
   this->del = del;
   */
  n = 0;
  q = 0;
  d = 2;
}

template<class T>
LinearHashTable<T>::LinearHashTable(T null, T del) :
    front(2, null), back(2, null) {
  this->null = null;
  this->del = del;
  n = 0;
  q = 0;
  d = 2;
}

template<class T>
LinearHashTable<T>::~LinearHashTable() {
}

template<class T>
void LinearHashTable<T>::resize() {
  d = 1;
  while ((1 << d) < 3 * n)
    d++;
  array<T> new_front(1 << d, null);
  q = n;
  // insert everything into tnew
  for (int k = 0; k < front.length; k++) {
    if (front[k] != null && front[k] != del) {
      int i = hash(front[k]);
      while (new_front[i] != null)
        i = (i == new_front.length - 1) ? 0 : i + 1;
      new_front[i] = front[k];
    }
  }
  front = new_front;
}

template<class T>
void LinearHashTable<T>::clear() {
  n = 0;
  q = 0;
  d = 1;
  array<T> tnew(2, null);
  front = tnew;
}

template<class T>
bool LinearHashTable<T>::add(T x) {
  if (find(x) != null)
    return false;
  if (2 * (q + 1) > front.length)
    resize();   // max 50% occupancy
  int i = hash(x);
  while (front[i] != null && front[i] != del)
    i = (i == front.length - 1) ? 0 : i + 1; // increment i
  if (front[i] == null)
    q++;
  n++;
  front[i] = x;
  return true;
}

template<class T>
T LinearHashTable<T>::find(T x) {
  int i = hash(x);
  while (front[i] != null) {
    if (front[i] != del && front[i] == x)
      return front[i];
    i = (i == front.length - 1) ? 0 : i + 1; // increment i
  }
  return null;
}

template<class T>
T LinearHashTable<T>::remove(T x) {
  int i = hash(x);
  while (front[i] != null) {
    T y = front[i];
    if (y != del && x == y) {
      front[i] = del;
      n--;
      if (8 * n < front.length)
        resize(); // min 12.5% occupancy
      return y;
    }
    i = (i == front.length - 1) ? 0 : i + 1;  // increment i
  }
  return null;
}

template<class T>
bool LinearHashTable<T>::addSlow(T x) {
  if (2 * (q + 1) > front.length)
    resize();   // max 50% occupancy
  int i = hash(x);
  while (front[i] != null) {
    if (front[i] != del && x.equals(front[i]))
      return false;
    i = (i == front.length - 1) ? 0 : i + 1; // increment i
  }
  front[i] = x;
  n++;
  q++;
  return true;
}

} /* namespace ods */
#endif /* LINEARHASHTABLE_H_ */
