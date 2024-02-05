//
// Created by shecannotsee on 24-2-5.
//

#ifndef FILE_MANAGE_H
#define FILE_MANAGE_H

namespace she_db {

/**
 * \brief This class to manage to file
 */
class file_manage {
 public:
  // copy:off
  file_manage(const file_manage&)            = delete;
  file_manage& operator=(const file_manage&) = delete;
  // move:off
  file_manage(file_manage&&)            = delete;
  file_manage& operator=(file_manage&&) = delete;
  // destructors
  ~file_manage() = default;
  // constructors
  file_manage() = default;

 private:
  // data
 public:
  // interface
};

}  // namespace she_db

#endif  // FILE_MANAGE_H
