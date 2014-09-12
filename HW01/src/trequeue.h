/*
 * trequeue.h
 *
 *  Created on: Sep 11, 2014
 *      Author: Nate Mara
 */

#ifndef TREQUEUE_H_
#define TREQUEUE_H_
#include "ArrayDeque.h"

template <class T>
class Trequeue {
protected:
  ods::ArrayDeque<T> front;
  ods::ArrayDeque<T> back;
public:
  Trequeue();
  ~Trequeue();
  int size();
  T get(int);
  T set(int, int);
  void add(int, int);
  T remove(int);
};

template <class T>
Trequeue<T>::Trequeue() {
}

template <class T>
Trequeue<T>::~Trequeue() {
}

template <class T>
int Trequeue<T>::size() {
  return this->front.size() + this->back.size();
}

template <class T>
T Trequeue<T>::get(int index) {
  if (index > this->front.size()) {
	return this->back.get(index - this->front.size());
  }
  return this->front.get(index);
}

template <class T>
T Trequeue<T>::set(int index, int value) {
  if (index > this->size() / 2) {
	return this->back.set(index - this->front.size(), value);
  }
  return this->front.set(index, value);
}

template <class T>
void Trequeue<T>::add(int index, int value) {
}

template <class T>
T Trequeue<T>::remove(int index, int value) {

}

#endif
