//
// Created by shecannotsee on 24-2-5.
//
#include <interface.h>  // she_log

#include "test_suite.h"

int main() {
  using namespace she_test::print_color;
  using log = she_log::interface;
  log test_log("test_log.txt");
  test_log.TRACE("TRACE test");
  std::cout << YELLOW_COLOR << "test start\n" << RESET_COLOR;
  she_test::test_suite::init();
  she_test::test_case_manager::init();
  std::cout << YELLOW_COLOR << "test start\n" << RESET_COLOR;
  return 0;
}
