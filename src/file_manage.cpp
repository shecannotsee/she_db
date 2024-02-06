//
// Created by shecannotsee on 24-2-5.
//

#include "file_manage.h"

#include "common_define.h"
#include "create_file.h"

namespace she_db {
file_manage::file_manage() : p_file_(fopen((prefix_path + initial_file_name).c_str(), "r"), &fclose) {
  if (!p_file_) {
    p_file_ = std::move(std::unique_ptr<FILE, decltype(&fclose)>(
        fopen((create_file<1>(prefix_path + initial_file_name)).c_str(), "rb+"), &fclose));
  }
  if (!p_file_) {
    throw std::runtime_error("File pointer is null," + (prefix_path + initial_file_name));
  }
}

}  // namespace she_db