//
// Created by shecannotsee on 24-2-6.
//

#ifndef TABLE_H
#define TABLE_H

#include <iostream>

namespace she_db {

class table {
  // 递归终止条件
  template<typename T>
  static void print(T value) {
    std::cout << T::size << std::endl;
  }

  // 递归调用
  template<typename T, typename... Args>
  static void print(T first, Args... args) {
    std::cout << T::size << std::endl;
    print(args...);
  }


};

}  // namespace she_db

#endif  // TABLE_H
