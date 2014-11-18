#include <iostream>
#include <time.h>

namespace ods {

template<class H>
class DataStructureTester {
protected:
  H list;

private:
  int TotalTime(int);
public:
  int DoRandomAdd(int);
  int DoSequentialAdd(int, int, int);
  int DoSequentialRemove(int, int, int);
  int DoSequentialFind(int, int, int);
  DataStructureTester();
};

template<class T> inline
int DataStructureTester<T>::TotalTime(int start_time) {
  return (clock() - start_time) / (CLOCKS_PER_SEC / 1000);
}

template<class T>
DataStructureTester<T>::DataStructureTester() {
  srand(time(0));
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
  clock_t start_time = clock();
  for (int i = 0; i < elements_to_add; i++) {
    list.add(rand() % INT_MAX);
  }

  return TotalTime(start_time);
}

}
