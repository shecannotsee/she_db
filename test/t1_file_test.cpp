//
// Created by shecannotsee on 24-2-5.
//
#include "t1_file_test.h"

#include <sys/stat.h>

#include "she_db.h"

namespace file {
namespace {
template <int file_size>
bool check_file_size(const std::string& file_name) {
  struct stat file_stat;

  // 使用 stat 获取文件信息
  if (stat(file_name.c_str(), &file_stat) != 0) {
    // 如果获取失败，返回false
    return false;
  }

  // 检查文件大小是否符合要求
  return file_stat.st_size == file_size;
}
}  // namespace

bool create() {
  const auto file_name = she_db::createFile<5>();

  return check_file_size<5>(she_db::prefix_path+file_name);
}
}  // namespace file
