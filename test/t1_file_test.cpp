//
// Created by shecannotsee on 24-2-5.
//
#include "t1_file_test.h"

#include "create_file.h"

namespace file {
bool create() {
  she_db::createFile<5>();
  return true;
}
}  // namespace file
