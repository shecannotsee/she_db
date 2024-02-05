//
// Created by shecannotsee on 24-2-5.
//

#ifndef CREATE_FILE_H
#define CREATE_FILE_H

#include <chrono>  // time to file name
#include <cstdio>
#include <iomanip>  // time to file name
#include <sstream>  // time to file name
#include <stdexcept>
#include <string>

#include "common_define.h"

namespace she_db {

/**
 * \brief Use the template to create a file of the appropriate size given the numbers
 * \tparam file_size_k file size,in k
 * \return file name
 */
template <int file_size_k>
static std::string createFile() noexcept {
  const std::string file_name = []() {
    auto now           = std::chrono::system_clock::now();
    std::time_t time   = std::chrono::system_clock::to_time_t(now);
    std::tm* localTime = std::localtime(&time);

    // 使用ostringstream进行字符串格式化
    std::ostringstream oss;
    oss << std::put_time(localTime, "%Y_%m_%d_%H_%M_%S");  // 年月日时分秒
    oss << "_";                                            // 添加下划线分隔
    oss << std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count() % 1000;  // 毫秒
    return oss.str();
  }();
  const std::string file_path = prefix_path + file_name;

  FILE* pFile = fopen(file_path.c_str(), "wb+");
  if (!pFile) {
    throw std::runtime_error("fopen error");
  }

  constexpr size_t size = 1024 * file_size_k / sizeof(char);

  const auto fseek_expand_size = fseek(pFile, size - 1, SEEK_SET);
  if (fseek_expand_size == -1) {
    throw std::runtime_error("fseek error: fseek_expand_size failed.");
  }
  // Move the file pointer back to the beginning
  const auto move_ptr_to_file_header = fseek(pFile, 0, SEEK_SET);
  if (move_ptr_to_file_header == -1) {
    throw std::runtime_error("fseek error: move_ptr_to_file_header failed.");
  }

  // init file content
  constexpr char buff[size]{0x00};
  const auto fwrite_to_init_file_bytes = fwrite(&buff, 1, size, pFile);
  if (fwrite_to_init_file_bytes != size) {
    const std::string error_message =
        "fwrite error:" + std::to_string(fwrite_to_init_file_bytes) + "/" + std::to_string(size);
    throw std::runtime_error(error_message);
  }

  const auto fclose_return_value_expect0 = fclose(pFile);
  if (fclose_return_value_expect0 != 0) {
    throw std::runtime_error("fclose error");
  }

  return file_name;
}

}  // namespace she_db

#endif  // CREATE_FILE_H
