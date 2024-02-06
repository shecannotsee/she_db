//
// Created by shecannotsee on 24-2-6.
//

#ifndef READ_H
#define READ_H

#include <cstdio>
#include <memory>
#include <string>
#include <vector>

namespace she_db {
namespace detail {

class read {
 public:
  read() = delete;
  explicit read(const std::string&) noexcept;
  ~read() noexcept;
  // copy:off
  read(const read&)            = delete;
  read& operator=(const read&) = delete;
  // move:on
  read(read&&)            = default;
  read& operator=(read&&) = default;

 private:
  std::unique_ptr<FILE> file_ptr_;

 public:
  using bytes = unsigned char;
  auto get(uint32_t offset, uint32_t len) const noexcept -> std::vector<bytes>;
};

}  // namespace detail
}  // namespace she_db

#endif  // READ_H
