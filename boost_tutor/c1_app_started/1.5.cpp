#include <boost/array.hpp>
#include <algorithm>
#include <iostream>

//trick 6
struct add_1 : public std::unary_function<int, void>
{
  void operator()(int& c) const {
    ++ c;
  }
};

typedef boost::array<int, 4> array4_t;

void vector_advance(array4_t& val){
  std::for_each(val.begin(),val.end(), add_1());
  //return val;
}


int main(int argc, char* argv[])
{

  array4_t val = {{-5,3,2,19}};

  //array4_t val_res;
  vector_advance(val);

  assert(val.size() == 4);
  //assert(val[0] == 1);

  std::cout<<val[0]<<std::endl;
  std::cout<<val[1]<<std::endl;
  std::cout<<val[2]<<std::endl;
  std::cout<<val[3]<<std::endl;
  //<<val[1]<<val[2]<<val[3];

}
