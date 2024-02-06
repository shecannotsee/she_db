//
// Created by shecannotsee on 24-2-6.
//

#include "file.h"

#include <cstdio>
#include <stdexcept>

namespace she_db {
namespace detail {

bool file::exist(const std::string& file_path) noexcept {
  const auto file_ptr = fopen(file_path.c_str(), "r");
  if (file_ptr == NULL) {
    return false;
  }
  const auto fclose_result = fclose(file_ptr);
  if (fclose_result == EOF) {
    throw std::runtime_error("fclose error");
  }
  return true;
}

}  // namespace detail
}  // namespace she_db