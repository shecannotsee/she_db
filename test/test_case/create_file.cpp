//
// Created by shecannotsee on 24-2-6.
//

#include "create_file.h"

#include <she_db.h>
#include <sys/stat.h>

#include <string>

namespace {
template <long long file_size>
bool check_file_size(const std::string& file_name) {
  struct stat file_stat;

  if (stat(file_name.c_str(), &file_stat) != 0) {
    return false;
  }

  // check size
  return file_stat.st_size == file_size;
}
}  // namespace

bool create_file::test() {
  const auto file_name = she_db::create_file<5>("file_create");
  return check_file_size<5 * 1024>(she_db::prefix_path + file_name);
}