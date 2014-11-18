#include <iostream>
#include <time.h>

namespace ods {

template<class H>
class DataStructureTester {
protected:
  H list;

public:
  int AddRandom(int);
  DataStructureTester();
};

template<class T>
DataStructureTester<T>::DataStructureTester() {
  srand(time(0));
}

template<class T>
int DataStructureTester<T>::AddRandom(int elements_to_add) {
  clock_t start_time = clock();
  for (int i = 0; i < elements_to_add; i++) {
    list.add(rand() % INT_MAX);
  }
  clock_t end_time = clock();

  return (end_time - start_time) / (CLOCKS_PER_SEC / 1000);
}

}
