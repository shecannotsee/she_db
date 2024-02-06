//
// Created by shecannotsee on 24-2-6.
//

#include "write.h"

#include "seek.h"

namespace she_db {
namespace detail {
write::write(const std::string& file_path) noexcept {
  file_ptr_ = std::move(std::unique_ptr<FILE>(fopen(file_path.c_str(), "r")));
  if (file_ptr_ == NULL) {
    throw std::runtime_error("fopen error: " + file_path);
  }
}
write::~write() noexcept {
  const auto fclose_result = fclose(file_ptr_.get());
  if (fclose_result == EOF) {
    throw std::runtime_error("fclose error");
  }
}
void write::content(const std::vector<bytes>& data, const uint32_t offset) const noexcept {
  // Move the file pointer to the specified location
  seek::move(file_ptr_.get(), offset);

  const auto len = data.size();
  // Read data from file
  if (std::fwrite(data.data(), sizeof(bytes), len, file_ptr_.get()) != len) {
    // Read failed
    throw std::runtime_error("fwrite failed");
  }

  seek::move_to_start(file_ptr_.get());
}
}  // namespace detail
}  // namespace she_db