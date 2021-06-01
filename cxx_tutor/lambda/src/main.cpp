#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

#include "Log.h"


void ForEach0(const std::vector<int>& values, void (*func)(int)){
  for(int value : values)
    func(value);
}

void ForEach1(const std::vector<int>& values, std::function<void(int)>& func){
  for(int value : values) func(value);
}

int main(){

  std::vector<int> values = {1,5,4,2,3};

  auto it = std::find_if(values.begin(), values.end(), [](int value){ return value > 3; });

  std::cout << *it << std::endl;

  ForEach0(values,[](int value){ std::cout <<"value:"<<value<<std::endl; });

  auto lambda0 = [](int value){ std::cout <<"value:"<<value<<std::endl; };

  ForEach0(values,lambda0);
}
