#include <boost/tuple/tuple.hpp>
#include <string>

#include <boost/tuple/tuple_comparison.hpp>
#include <assert.h>
#include <set>

//trick 7
void foo1(void){
  boost::tuple<int,std::string> almost_a_pair(10,"Hello");
  boost::tuple<int,float,double,int> quad(10,1.0f,10.0,1);

  int i = boost::get<0>(almost_a_pair);
  const std::string& str = boost::get<1>(almost_a_pair);;
  double d = boost::get<2>(quad);

  (void)i;
  (void)str;
  (void)d;

  using namespace boost;

  std::set<tuple<int, double, int>> s;
  s.insert(make_tuple(1,1.0,2));
  s.insert(make_tuple(2,10.0,2));
  s.insert(make_tuple(3,100.0,2));

}
void foo2(void){

}
void foo3(void){

}

int main(int argc, char* argv[])
{

}
