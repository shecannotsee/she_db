//
// Created by shecannotsee on 24-2-6.
//

#include "file_manage.h"

#include <she_db.h>

bool file_manage::test() {
  she_db::file_manage test_target;

  test_target.create_table<she_db::she_boolean,she_db::she_int64>("");
  return true;
}