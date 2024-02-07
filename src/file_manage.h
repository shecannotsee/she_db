//
// Created by shecannotsee on 24-2-5.
//

#ifndef FILE_MANAGE_H
#define FILE_MANAGE_H

#include <memory>
#include <type_traits>

#include "common_define.h"
#include "create_file.h"
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
  void create_table(const std::string& table_name) {
    uint32_t offset = 0;
    /* get offset */ {
      auto read_something      = std::make_unique<detail::read>(prefix_path + initial_file_name);
      constexpr int type_index = 0;
      constexpr int len_index  = 1;
      // read
      auto type_and_len = read_something->get(offset, 2);
      while (type_and_len.at(type_index) != 0) {
        offset += static_cast<decltype(offset)>(type_and_len.at(len_index)) + 2;
        type_and_len = read_something->get(offset, 2);
      }
    }
    /* write table file information */ {
      auto write_something = std::make_unique<detail::write>(prefix_path + initial_file_name);
      std::vector<uint8_t> content;
      /* Add data to the content */ {
        auto table_struct_info = create_file<1>();
        content.emplace_back(static_cast<uint8_t>(file_type::table_struct));
        content.emplace_back(static_cast<uint8_t>(table_struct_info.size()));
        for (const auto& c : table_struct_info) {
          content.emplace_back(static_cast<uint8_t>(c));
        }
        auto data_storage_info = create_file<4>();
        content.emplace_back(static_cast<uint8_t>(file_type::data_storage));
        content.emplace_back(static_cast<uint8_t>(data_storage_info.size()));
        for (const auto& c : data_storage_info) {
          content.emplace_back(static_cast<uint8_t>(c));
        }
      }
      write_something->content(content, offset);
    }

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
