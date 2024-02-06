//
// Created by shecannotsee on 24-2-5.
//

#ifndef FILE_MANAGE_H
#define FILE_MANAGE_H

#include <memory>

namespace she_db {

enum class file_type : int {
  initial         = 1,
  operator_logger = 2,
  table_struct    = 3,
  data_storage    = 4,

  test = 127,
};

/**
 * \brief This class to manage to file
 */
class file_manage {
 public:
  // dtor
  file_manage();
  // ctor
  ~file_manage() = default;
  // copy:off
  file_manage(const file_manage&)            = delete;
  file_manage& operator=(const file_manage&) = delete;
  // move:off
  file_manage(file_manage&&)            = delete;
  file_manage& operator=(file_manage&&) = delete;

 private:
  std::unique_ptr<FILE, decltype(&fclose)> p_file_;

 public:
  // interface
};

}  // namespace she_db

#endif  // FILE_MANAGE_H
