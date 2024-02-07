//
// Created by shecannotsee on 24-2-6.
//

#include "read.h"

#include <print_color.h>
#include <she_db.h>
#include <sys_api_encapsulation/read.h>
#include <sys_api_encapsulation/file.h>

bool read::test() {
  using namespace she_test::print_color;
  using namespace she_db;
  const std::string file_path = prefix_path + "sys_api_encapsulation__read_test";
  if (detail::file::exist(file_path) == false) {
    create_file<1>(file_path);
  }

  const detail::read test_file(file_path);
  for (int i = 0; i < 1024; i++) {
    const auto bytes = test_file.get(0, i);
    if (bytes.size() != i) {
      std::cout << RED_COLOR << "read return size error:" << bytes.size() << "/" << i << std::endl << RESET_COLOR;
      return false;
    }
  }
  return true;
}