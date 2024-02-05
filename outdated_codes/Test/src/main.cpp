#include <stdio.h>
#include "storage_engine_test.h"

int main() {
  storage_engine_test test;
  test.t_write();
  test.t_read();
  test.t_find();
  test.create_file();
  return 0;
}