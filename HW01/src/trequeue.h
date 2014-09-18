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
private:
  ods::ArrayDeque<T> front;
  ods::ArrayDeque<T> back;
public:
  Trequeue();
  ~Trequeue();
  int size();
  T get(int);
  void set(int, T);
  void add(int, T);
  T remove(int);
  void clear();
  void balance();
};

template <class T>
Trequeue<T>::Trequeue() {
}

template <class T>
Trequeue<T>::~Trequeue() {
}

template <class T>
void Trequeue<T>::clear() {
  this->front.clear();
  this->back.clear();
}

template <class T>
int Trequeue<T>::size() {
  return this->front.size() + this->back.size();
}

template <class T>
T Trequeue<T>::get(int index) {
  if (index >= this->front.size()) {
    return this->back.get(index - this->front.size());
  }

  return this->front.get(index);
}

template <class T>
void Trequeue<T>::set(int index, T value) {
  if (index > this->size() / 2) {
    this->back.set(index - this->front.size(), value);
  } else {
    this->front.set(index, value);
  }

  this->balance();
}

template <class T>
void Trequeue<T>::add(int index, T value) {
  if (index > this->front.size()) {
    this->back.add(index - this->front.size(), value);
  } else {
    this->front.add(index, value);
  }

  // this->balance();
}

template <class T>
T Trequeue<T>::remove(int index) {
  if (index > this->front.size()) {
    this->back.remove(index - this->front.size());
  } else {
    this->front.remove(index);
  }

  this->balance();
}

template <class T>
void Trequeue<T>::balance() {
  bool bigFront = this->back.size() * 3 < this->front.size();
  bool bigBack = this->front.size() * 3 < this->back.size();

  if (!(bigFront || bigBack)) {
    return;
  }

  int frontSize = this->size() / 2;
  int backSize = this->size() - frontSize;

  ods::ArrayDeque<T> newFront;
  ods::ArrayDeque<T> newBack;

  for (int i = 0; i < frontSize; i++) {
    newFront.add(i, this->get(i));
  }

  for (int i = 0; i < backSize; i++) {
    newBack.add(i, this->get(frontSize + i));
  }

  this->front = newFront;
  this->back = newBack;
}

#endif
