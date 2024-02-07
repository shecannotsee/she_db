//
// Created by shecannotsee on 24-2-5.
//

#include "file_manage.h"

#include "common_define.h"
#include "create_file.h"

namespace she_db {

file_manage::file_manage() : read_(nullptr), write_(nullptr) {
  const std::string initial_file_path = prefix_path + initial_file_name;
  if (!detail::file::exist(initial_file_path)) {
    create_file<1>(initial_file_path);
  }
}
}  // namespace she_db