//
// Created by shecannotsee on 24-2-5.
//

#ifndef TEST_SUITE_H
#define TEST_SUITE_H

#include <she_test.h>

#include "t1_file_test.h"
#include "t2_table.h"

namespace she_test {
class test_suite {
 public:
  static void init() {
    using namespace test_case_manager;
    add("file", "create", file::create);
    add("file", "read_and_write_data", file::read_and_write_data);
    add("file", "manage", file::manage);
    add("table", "store", table::store);
  }
};
}  // namespace she_test

#endif  // TEST_SUITE_H
