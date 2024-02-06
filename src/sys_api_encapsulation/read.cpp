//
// Created by shecannotsee on 24-2-6.
//

#include "read.h"

#include "seek.h"

namespace she_db {
namespace detail {
read::read(const std::string& file_path) noexcept : file_ptr_(fopen(file_path.c_str(), "r"), &fclose) {
  if (file_ptr_ == NULL) {
    throw std::runtime_error("fopen error: " + file_path);
  }
}

auto read::get(uint32_t offset, uint32_t len) const noexcept -> std::vector<bytes> {
  // Move the file pointer to the specified location
  seek::move(file_ptr_.get(), offset);

  std::vector<bytes> data(len);
  // Read data from file
  if (std::fread(data.data(), sizeof(bytes), len, file_ptr_.get()) != len) {
    // Read failed
    throw std::runtime_error("fread failed");
  }
  seek::move_to_start(file_ptr_.get());
  return data;
}

}  // namespace detail
}  // namespace she_db