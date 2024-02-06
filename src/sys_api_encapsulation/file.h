//
// Created by shecannotsee on 24-2-6.
//

#ifndef OPEN_FILE_H
#define OPEN_FILE_H

#include <string>

namespace she_db {
namespace detail {

class file {
 public:
  static bool exist(const std::string&) noexcept;
};

}  // namespace detail
}  // namespace she_db

#endif  // OPEN_FILE_H
