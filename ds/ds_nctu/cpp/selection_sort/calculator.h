#include <iostream>
using namespace std;
const unsigned int array_cnt = 100;

class calculator
{
public:

  calculator():c_array_cnt(array_cnt),p_arr(new unsigned int[array_cnt]){
    //cout<<"addr: "<<this<<"arr size: "<<sizeof(*p_arr)<<"\n"<<endl;
    initRandomArr();
  };
  virtual ~calculator(){

  };
  void dataListing(unsigned int nclum);
  virtual void algorithm() = 0;

public:
    unsigned int c_array_cnt;
    unsigned int *p_arr;

private:


    void initRandomArr();
};

class selectsortcalculator : public calculator
{
public:
  selectsortcalculator(){};
  virtual ~selectsortcalculator(){};
  virtual void algorithm();
  
};
