//
// Created by shecannotsee on 24-2-5.
//
#include "t1_file_test.h"

#include <sys/stat.h>

#include <iostream>

#include "data_type_operator.h"
#include "she_db.h"

namespace file {
namespace {
template <long long file_size>
bool check_file_size(const std::string& file_name) {
  struct stat file_stat;

  if (stat(file_name.c_str(), &file_stat) != 0) {
    return false;
  }

  // check size
  return file_stat.st_size == file_size;
}
}  // namespace

bool create() {
  const auto file_name = she_db::createFile<5>();
  return check_file_size<5 * 1024>(she_db::prefix_path + file_name);
}

bool read_data() {
  std::string file_path = she_db::prefix_path + she_db::createFile<1>();
  std::cout << "Before move: " << file_path << std::endl;
  she_db::data_type_operator test_target(std::move(file_path));
  std::cout << "After move: " << file_path << std::endl;
  /* bool:0 */ {
    bool a = true;
    test_target.write_boolean(0, a);
    auto res = test_target.read_boolean(0);
    if (a != res) {
      std::cout << "bool(false) failed\n";
      throw;
    }

    a = false;
    test_target.write_boolean(0, a);
    res = test_target.read_boolean(0);
    if (a != res) {
      std::cout << "bool(false) failed\n";
      throw;
    }
  }

  return true;
}

bool write_data() {
  return true;
}

}  // namespace file
