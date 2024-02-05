//
// Created by shecannotsee on 24-2-5.
//
#include "t1_file_test.h"

#include <sys/stat.h>

#include <iostream>
#include <limits>

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
    bool expect = true;
    test_target.write_boolean(0, expect);
    auto res = test_target.read_boolean(0);
    if (expect != res) {
      std::cout << "bool(false) failed\n";
      throw std::runtime_error("");
    }

    expect = false;
    test_target.write_boolean(0, expect);
    res = test_target.read_boolean(0);
    if (expect != res) {
      std::cout << "bool(false) failed\n";
      throw std::runtime_error("");
    }
    // template
    expect = true;
    test_target.write<she_db::boolean>(0, expect);
    res = test_target.read<she_db::boolean>(0);
    if (expect != res) {
      std::cout << "bool(false) failed\n";
      throw std::runtime_error("");
    }

    expect = false;
    test_target.write<she_db::boolean>(0, expect);
    res = test_target.read<she_db::boolean>(0);
    if (expect != res) {
      std::cout << "bool(false) failed\n";
      throw std::runtime_error("");
    }
  }
  /* int8:1, size1 */ {
    using test_type = she_db::int8;
    //
    auto min             = std::numeric_limits<test_type::type>::min();
    auto max             = std::numeric_limits<test_type::type>::max();
    constexpr int offset = 1;
    // test
    test_type::type target = 0;
    test_type::type res;

    for (test_type::type i = min; i < max; i++) {
      target = i;
      test_target.write<test_type>(offset, target);
      res = test_target.read<test_type>(offset);
      if (target != res) {
        std::cout << "int8_t(" << i << ") failed\n";
        throw std::runtime_error("");
      }
    }
  }
  /* int16:2, size2*/ {
    using test_type = she_db::int16;
    //
    auto min             = std::numeric_limits<test_type::type>::min();
    auto max             = std::numeric_limits<test_type::type>::max();
    constexpr int offset = 1;
    // test
    test_type::type target = 0;
    test_type::type res;

    for (test_type::type i = min; i < max; i++) {
      target = i;
      test_target.write<test_type>(offset, target);
      res = test_target.read<test_type>(offset);
      if (target != res) {
        std::cout << "int16_t(" << i << ") failed\n";
        throw std::runtime_error("");
      }
    }
  }
  /* int32:4, size4*/ {
    using test_type = she_db::int32;
    //
    auto min             = std::numeric_limits<test_type::type>::min();
    auto max             = std::numeric_limits<test_type::type>::max();
    constexpr int offset = 1;
    // test
    test_type::type target = 0;
    test_type::type res;

    for (test_type::type i = min; i < max; i++) {
      target = i;
      test_target.write<test_type>(offset, target);
      res = test_target.read<test_type>(offset);
      if (target != res) {
        std::cout << "int32_t(" << i << ") failed\n";
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
