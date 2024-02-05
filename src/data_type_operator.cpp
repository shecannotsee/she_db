//
// Created by shecannotsee on 24-2-5.
//

#include "data_type_operator.h"

namespace she_db {

data_type_operator::data_type_operator(std::string&& file_path) noexcept
    : file_path_(std::move(file_path)), p_file_(fopen(file_path_.c_str(), "rb+"), &fclose) {
  if (!p_file_) {
    throw std::runtime_error("File pointer is null," + file_path_);
  }
}

}  // namespace she_db