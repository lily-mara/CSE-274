#ifndef DATA_STRUCTURE_TESTER_H_
#define DATA_STRUCTURE_TESTER_H_

#include <iostream>
#include <time.h>

namespace ods {

template<class H>
class DataStructureTester {
protected:
  H list;

private:
  int TotalTime(int);
  int* randomNums;
public:
  int DoRandomAdd(int);
  int DoRandomRemove(int);
  int DoRandomFind(int);
  int DoSequentialAdd(int, int, int);
  int DoSequentialRemove(int, int, int);
  int DoSequentialFind(int, int, int);
  DataStructureTester();
  ~DataStructureTester();
};

template<class T> inline
int DataStructureTester<T>::TotalTime(int start_time) {
  return (clock() - start_time) / (CLOCKS_PER_SEC / 1000);
}

template<class T>
int DataStructureTester<T>::DoRandomRemove(int n) {
  clock_t start_time = clock();

  for (int i = 0; i < n; i++) {
    list.remove(randomNums[i]);
  }

  return TotalTime(start_time);
}

template<class T>
int DataStructureTester<T>::DoRandomFind(int n) {
  clock_t start_time = clock();

  for (int i = 0; i < n; i++) {
    list.find(randomNums[i]);
  }

  return TotalTime(start_time);
}

template<class T>
DataStructureTester<T>::DataStructureTester() {
  srand(time(0));
  randomNums = new int[0];
}

template<class T>
DataStructureTester<T>::~DataStructureTester() {
  delete[] randomNums;
}

template<class T>
int DataStructureTester<T>::DoSequentialFind(int start, int end, int step) {
  clock_t start_time = clock();
  for (int i = start; i < end; i += step) {
    list.find(i);
  }

  return TotalTime(start_time);
}

template<class T>
int DataStructureTester<T>::DoSequentialRemove(int start, int end, int step) {
  clock_t start_time = clock();
  for (int i = start; i < end; i += step) {
    list.remove(i);
  }

  return TotalTime(start_time);
}

template<class T>
int DataStructureTester<T>::DoSequentialAdd(int start, int end, int step) {
  clock_t start_time = clock();
  for (int i = start; i < end; i += step) {
    list.add(i);
  }

  return TotalTime(start_time);
}

template<class T>
int DataStructureTester<T>::DoRandomAdd(int elements_to_add) {
  delete[] randomNums;
  randomNums = new int[elements_to_add];

  clock_t start_time = clock();
  for (int i = 0; i < elements_to_add; i++) {
    int random = rand() % INT_MAX;

    list.add(random);
    randomNums[i] = random;
  }

  return TotalTime(start_time);
}

}

#endif
