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
  const she_db::data_type_operator test_target(std::move(file_path));

  /* bool:0, size1 */ {
    bool a = true;
    test_target.write_boolean(0, a);
    auto res = test_target.read_boolean(0);
    if (a != res) {
      std::cout << "bool(false) failed\n";
      throw std::runtime_error("");
    }

    a = false;
    test_target.write_boolean(0, a);
    res = test_target.read_boolean(0);
    if (a != res) {
      std::cout << "bool(false) failed\n";
      throw std::runtime_error("");
    }
  }
  /* int8:1, size1 */ {
    int8_t target = 0;
    auto res      = test_target.read_int8(1);
    if (target != res) {
      std::cout << "int8_t(0) failed\n";
      throw;
    }

    for (int i = 0; i < 128; i++) {
      target = i;
      test_target.write_int8(1, target);
      res = test_target.read_int8(1);
      if (target != res) {
        std::cout << "int8_t(" << i << ") failed\n";
        throw std::runtime_error("");
      }
    }
  }
  /* int16:2, size2*/ {
    int16_t target = 0;
    auto res       = test_target.read_int16(2);
    if (target != res) {
      std::cout << "int16_t(0) failed\n" << target << "?" << res << "\n";
      throw std::runtime_error("");
    }

    for (int i = 0; i < 32768; i++) {
      target = i;
      test_target.write_int16(2, target);
      res = test_target.read_int16(2);
      if (target != res) {
        std::cout << "int16_t(" << i << ") failed\n";
        throw std::runtime_error("");
      }
    }
  }

  return true;
}

bool write_data() {
  return true;
}

}  // namespace file
