//
// Created by shecannotsee on 24-2-6.
//

#include "file.h"

#include <sys_api_encapsulation/file.h>

bool file::test() {
  if (she_db::detail::file::exist("xxx") == false)
    return true;
  else
    return false;
}