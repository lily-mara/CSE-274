#include <iostream>

namespace ods {

template<class H>
class DataStructureTester {
protected:
  H list;

public:
  void AddRandom(int i) {
    list.add(i);
    //std::cout << "find " << list.find(i) << std::endl;
  }
};

}
