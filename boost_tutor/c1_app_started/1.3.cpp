#include <boost/variant.hpp>
#include <boost/any.hpp>
#include <iostream>
#include <vector>
#include <string>

//trick 4

typedef boost::any cell_t;
typedef std::vector<cell_t> db_row_t;

db_row_t get_row(const char*){
  db_row_t row;
  row.push_back(10);
  row.push_back(10.12f);
  row.push_back(std::string("hello again!"));
  row.push_back(5);
  row.push_back(2.78f);
  row.push_back(std::string("abc"));
  row.push_back(1.78f);
  return row;
};


struct db_sum: std::unary_function<boost::any,void>{
private:
  double& sum_;
public:
  explicit db_sum(double& sum):sum_(sum){}
  void operator()(const cell_t& value){
    const std::type_info& ti = value.type();
    if(ti == typeid(int)){
      sum_ += boost::any_cast<int>(value);
    }
    else if(ti == typeid(float)){
      sum_ += boost::any_cast<float>(value);  
    }
  }
};


int main(int argc, char* argv[])
{

  //trick 3
  typedef boost::variant<int, const char*, std::string> my_var_t;

  std::vector<my_var_t> some_values;

  some_values.push_back(10);
  some_values.push_back(std::string("Hello there!"));
  //some_values.push_back(std::string("Wow!"));

  std::string& s = boost::get<std::string>(some_values.back());

  s += " THis is great!\n";

  std::cout <<  s;

  my_var_t variable(10);

  std::cout << boost::get<int>(variable)<<std::endl;  
  std::cout << boost::get<int>(&variable)<<std::endl;  
  std::cout << *boost::get<int>(&variable)<<std::endl;  


  //trick 4

  db_row_t row = get_row("Query: Give me some row, please!");

  double res = 0.0;
  std::for_each(row.begin(), row.end(), db_sum(res));

  std::cout << "Sum of arithmetic types in database row is: "<<res<<std::endl;

  return 0;
}