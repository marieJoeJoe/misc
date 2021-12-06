#include <iostream>
#include <memory>  // std::make_unique
#include <utility> // std::move

int main(void) 
{
  int value = 1;
  auto copy_value = [value] {
    return value;
  };

  value = 100;
  
  auto stored_copy_value = copy_value();
  std::cout << "stored_value = " << stored_copy_value << std::endl;
  // 这时, stored_value == 1, 而 value == 100.
  // 因为 copy_value 在创建时就保存了一份 value 的拷贝

  value = 1;

  auto ref_value = [&value] {
    return value;
  };

  value = 100;

  auto stored_ref_value = ref_value();
  std::cout << "stored_value = " << stored_ref_value << std::endl;
  // 这时, stored_value == 100, value == 100.
  // 因为 copy_value 保存的是引用

  auto important = std::make_unique<int>(-10);
  auto add = [v1 = 1, v2 = std::move(important)](int x, int y) -> int {
    return x+y+v1+(*v2);
  };
  std::cout << add(3,4) << std::endl;

  auto addx = [](auto x, auto y) {
    return x+y;
  };
  std::cout << addx(3.1,4.23) << std::endl;
  std::cout << addx(13,-4) << std::endl;


}

