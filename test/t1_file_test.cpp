//
// Created by shecannotsee on 24-2-5.
//
#include "t1_file_test.h"

#include <sys/stat.h>

#include <iostream>
#include <limits>

#include "data_type_operator.h"
#include "file_manage.h"
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
  const auto file_name = she_db::create_file<5>("file_create");
  return check_file_size<5 * 1024>(she_db::prefix_path + file_name);
}

bool read_and_write_data() {
  std::string file_path = she_db::prefix_path + she_db::create_file<1>("file_read_and_write_data");
  const she_db::data_type_operator test_target(std::move(file_path));
  /* 0 1  2  2  4  5  6  7  8  9 10 11 12 13 14 15 16 17 */
  /* 0 0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0 */
  /* b 8 16 16 32 32 32 32 64 64 64 64 64 64 64 64 f3 f3 */
  /* bool:0, size1 */ {
    using test_type      = she_db::she_boolean;
    constexpr int offset = 0;
    // test
    test_type::type target;
    test_type::type res;

    target = true;
    test_target.write<test_type>(offset, target);
    res = test_target.read<test_type>(offset);
    if (target != res) {
      std::cout << "boolean(true) failed\n";
      throw std::runtime_error("");
    }

    target = false;
    test_target.write<test_type>(offset, target);
    res = test_target.read<test_type>(offset);
    if (target != res) {
      std::cout << "boolean(false) failed\n";
      throw std::runtime_error("");
    }
  }
  /* int8:1, size1 */ {
    using test_type = she_db::she_int8;
    //
    auto min             = std::numeric_limits<test_type::type>::min();
    auto max             = std::numeric_limits<test_type::type>::max();
    constexpr int offset = 1;
    // test
    test_type::type target = 0;
    test_type::type res;

    for (test_type::type i = min; i < max - 1; i++) {
      target = i;
      test_target.write<test_type>(offset, target);
      res = test_target.read<test_type>(offset);
      if (target != res) {
        std::cout << "int8_t(" << i << ") failed\n";
        throw std::runtime_error("");
      }
    }
  }
  /* int16:2, size2 */ {
    using test_type      = she_db::she_int16;
    auto min             = std::numeric_limits<test_type::type>::min();
    auto max             = std::numeric_limits<test_type::type>::max();
    constexpr int offset = 2;
    // test
    test_type::type target = 0;
    test_type::type res;

    for (test_type::type i = -10; i < 10; i++) {
      target = i;
      test_target.write<test_type>(offset, target);
      res = test_target.read<test_type>(offset);
      if (target != res) {
        std::cout << "int16_t(" << i << ") failed\n";
        throw std::runtime_error("");
      }
    }
  }
  /* int32:4, size4 */ {
    using test_type = she_db::she_int32;

    auto min             = std::numeric_limits<test_type::type>::min();
    auto max             = std::numeric_limits<test_type::type>::max();
    constexpr int offset = 4;
    // test
    test_type::type target = 0;
    test_type::type res;

    for (test_type::type i = -10; i < 10; i++) {
      target = i;
      test_target.write<test_type>(offset, target);
      res = test_target.read<test_type>(offset);
      if (target != res) {
        std::cout << "int32_t(" << i << ") failed\n";
        throw std::runtime_error("");
      }
    }
  }
  /* int64:8, size8 */ {
    using test_type = she_db::she_int32;
    //
    auto min             = std::numeric_limits<test_type::type>::min();
    auto max             = std::numeric_limits<test_type::type>::max();
    constexpr int offset = 8;
    // test
    test_type::type target = 0;
    test_type::type res;

    for (test_type::type i = -10; i < 10; i++) {
      target = i;
      test_target.write<test_type>(offset, target);
      res = test_target.read<test_type>(offset);
      if (target != res) {
        std::cout << "int64_t(" << i << ") failed\n";
        throw std::runtime_error("");
      }
    }
  }
  /* float32:16, size4 */ {
    using test_type = she_db::she_float32;
    //
    auto min             = std::numeric_limits<test_type::type>::min();
    auto max             = std::numeric_limits<test_type::type>::max();
    constexpr int offset = 16;
    // test
    test_type::type target = 0;
    test_type::type res;

    for (test_type::type i = -1.0; i < 10.0; i = i + 1.0) {
      target = i;
      test_target.write<test_type>(offset, target);
      res = test_target.read<test_type>(offset);
      if (target != res) {
        std::cout << "int64_t(" << i << ") failed\n";
        throw std::runtime_error("");
      }
    }
  }
  /* float64:20, size8 */ {
    using test_type = she_db::she_float64;
    //
    auto min             = std::numeric_limits<test_type::type>::min();
    auto max             = std::numeric_limits<test_type::type>::max();
    constexpr int offset = 20;
    // test
    test_type::type target = 0;
    test_type::type res;

    for (test_type::type i = -10; i < 10; i++) {
      target = i;
      test_target.write<test_type>(offset, target);
      res = test_target.read<test_type>(offset);
      if (target != res) {
        std::cout << "int64_t(" << i << ") failed\n";
        throw std::runtime_error("");
      }
    }
  }

  return true;
}

bool manage() {
  using namespace she_db;
  file_manage test_target;
  return true;
}

}  // namespace file
