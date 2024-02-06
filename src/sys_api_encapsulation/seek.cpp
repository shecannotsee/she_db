//
// Created by shecannotsee on 24-2-6.
//

#include "seek.h"

#include <stdexcept>

namespace she_db {
namespace detail {
void seek::move_to_start(FILE* file_ptr) noexcept {
  const auto fseek_result = ::fseek(file_ptr, 0, SEEK_SET);
  if (fseek_result != 0) {
    throw std::runtime_error("fseek failed");
  }
}
void seek::move(FILE* file_ptr, const uint32_t offset) noexcept {
  const auto fseek_result = ::fseek(file_ptr, offset, SEEK_SET);
  if (fseek_result != 0) {
    throw std::runtime_error("fseek failed");
  }
}
void seek::move_to_tail(FILE* file_ptr) noexcept {
  const auto fseek_result = ::fseek(file_ptr, 0, SEEK_END);
  if (fseek_result != 0) {
    throw std::runtime_error("fseek failed");
  }
}
}  // namespace detail
}  // namespace she_db