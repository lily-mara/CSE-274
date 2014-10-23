/*
 * DualArray.h
 *
 *  Created on: Oct 23, 2014
 *      Author: nate
 */

#ifndef DUALARRAY_H_
#define DUALARRAY_H_
#include "array.h"

namespace ods {

template<class T>
class DualArray {
protected:
  array<T> front;
  array<T> back;
public:
  T get(int i);
  void set(int i, int x);
  int size();
  DualArray(int, T);
};

template<class T>
DualArray<T>::DualArray(int size, T initial) :
    front(size / 2, initial), back(size / 2, initial) {

}

template <class T>
T DualArray<T>::get(int i) {
  if (i < front.size) {
    return front[i];
  } else {
    return back[i-front.size];
  }
}

template <class T>
void DualArray<T>::set(int i, int x) {
  if (i < front.size) {
    front[i] = x;
  } else {
    back[i-front.size] = x;
  }
}

}
/* namespace ods */
#endif /* DUALARRAY_H_ */
