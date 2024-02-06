//
// Created by shecannotsee on 24-2-6.
//

#ifndef WRITE_H
#define WRITE_H
#include "read.h"

namespace she_db {
namespace detail {

#include <cstdio>
#include <memory>
#include <string>
#include <vector>

class write {
 public:
  write() = delete;
  explicit write(const std::string&) noexcept;
  ~write() noexcept;
  // copy:off
  write(const write&)            = delete;
  write& operator=(const write&) = delete;
  // move:on
  write(write&&)            = default;
  write& operator=(write&&) = default;

 private:
  std::unique_ptr<FILE> file_ptr_;

 public:
  using bytes = unsigned char;
  void content(const std::vector<bytes>&, uint32_t) const noexcept;
};

}  // namespace detail
}  // namespace she_db

#endif  // WRITE_H
