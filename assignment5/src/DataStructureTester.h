#include <iostream>
#include <time.h>

namespace ods {

template<class H>
class DataStructureTester {
protected:
  H list;

public:
  int DoRandomAdd(int);
  int DoSequentialAdd(int, int, int);
  int DoSequentialRemove(int, int, int);
  DataStructureTester();
};

template<class T>
DataStructureTester<T>::DataStructureTester() {
  srand(time(0));
}

template<class T>
int DataStructureTester<T>::DoSequentialRemove(int start, int end, int step) {
  clock_t start_time = clock();
  for (int i = start; i < end; i+=step) {
    list.remove(i);
  }
  clock_t end_time = clock();

  return (end_time - start_time) / (CLOCKS_PER_SEC / 1000);
}

template<class T>
int DataStructureTester<T>::DoSequentialAdd(int start, int end, int step) {
  clock_t start_time = clock();
  for (int i = start; i < end; i+=step) {
    list.add(i);
  }
  clock_t end_time = clock();

  return (end_time - start_time) / (CLOCKS_PER_SEC / 1000);
}

template<class T>
int DataStructureTester<T>::DoRandomAdd(int elements_to_add) {
  clock_t start_time = clock();
  for (int i = 0; i < elements_to_add; i++) {
    list.add(rand() % INT_MAX);
  }
  clock_t end_time = clock();

  return (end_time - start_time) / (CLOCKS_PER_SEC / 1000);
}

}
