//
// Created by shecannotsee on 24-2-5.
//

#ifndef TEST_SUITE_H
#define TEST_SUITE_H

#include <she_test.h>

#include "test_case/create_file.h"
#include "test_case/data_type_operator.h"
#include "test_case/file_manage.h"
#include "test_case/sys_api_encapsulation/file.h"
#include "test_case/sys_api_encapsulation/read.h"
#include "test_case/sys_api_encapsulation/seek.h"
#include "test_case/sys_api_encapsulation/write.h"

namespace she_test {
class test_suite {
 public:
  static void init() {
    using namespace test_case_manager;
    add("create_file", "test", create_file::test);
    add("data_type_operator", "read_and_write_data", data_type_operator::read_and_write_data);
    add("file_manage", "test", file_manage::test);
  }
};
}  // namespace she_test

#endif  // TEST_SUITE_H
