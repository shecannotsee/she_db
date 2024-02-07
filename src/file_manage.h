//
// Created by shecannotsee on 24-2-5.
//

#ifndef FILE_MANAGE_H
#define FILE_MANAGE_H

#include <memory>
#include <type_traits>

#include "sys_api_encapsulation/file.h"
#include "sys_api_encapsulation/read.h"
#include "sys_api_encapsulation/write.h"

namespace she_db {

enum class file_type : int8_t {
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
  std::unique_ptr<detail::read> read_;
  std::unique_ptr<detail::write> write_;

#if __cplusplus >= 201103L && __cplusplus < 201703L
  template <typename... Args>
  void add_sizes_impl(std::vector<int>& sizes, Args... args) {
    (sizes.push_back(args), ...);
  }

  template <typename... t>
  void add_size(std::vector<int>& sizes) {
    add_sizes_impl(sizes, t::size...);
  }
#endif

 public:
  // interface
  template <typename... t>
  void add_table() {
    std::vector<int> sizes;
#if __cplusplus >= 201703L
    (sizes.push_back(t::size), ...);  // 将每个参数的大小添加到向量中
#else
    add_size<t...>(sizes);
#endif

    // 可以在这里进行其他操作，比如输出大小
    printf("Sizes of parameters: ");
    for (auto size : sizes) {
      printf("%d ", size);
    }
    printf("\n");
  }
};

}  // namespace she_db

#endif  // FILE_MANAGE_H
