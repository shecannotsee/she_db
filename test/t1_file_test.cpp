//
// Created by shecannotsee on 24-2-5.
//
#include "t1_file_test.h"

#include <sys/stat.h>

#include <iostream>

#include "data_types.h"
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
  std::string file_path = she_db::createFile<1>();
  std::cout << "Before move: " << file_path << std::endl;
  she_db::data_types test_target(std::move(file_path));
  std::cout << "After move: " << file_path << std::endl;

  return false;
}

bool write_data() {
  return false;
}

}  // namespace file
