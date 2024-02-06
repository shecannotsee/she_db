//
// Created by shecannotsee on 24-2-6.
//

#ifndef SEEK_H
#define SEEK_H

#include <cstdint>
#include <cstdio>

namespace she_db {
namespace detail {

class seek {
 public:
  static void move_to_start(FILE* file_ptr) noexcept;
  static void move(FILE* file_ptr, uint32_t offset) noexcept;
  static void move_to_tail(FILE* file_ptr) noexcept;
};

}  // namespace detail
}  // namespace she_db

#endif  // SEEK_H
