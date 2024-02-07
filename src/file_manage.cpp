//
// Created by shecannotsee on 24-2-5.
//

#include "file_manage.h"

#include "common_define.h"
#include "create_file.h"

namespace she_db {

file_manage::file_manage() : read_(nullptr), write_(nullptr) {
  const std::string initial_file_path = prefix_path + initial_file_name;
  if (!detail::file::exist(initial_file_path)) {
    create_file<1>(initial_file_path);
  }
  bool init = false;
  /* self-checking */ {
    const auto read_something = std::make_unique<detail::read>(initial_file_path);
    // 1(type) + 1(name size) + 14
    const uint32_t read_size = 1 + 1 + initial_file_name.size();
    // exec
    auto content = read_something->get(0, read_size);
    if (static_cast<file_type>(content.at(0)) != file_type::initial) {
      goto init_false;
    }
    if (content.at(1) != 0x0e) {
      goto init_false;
    }
    for (int index = 0; index < initial_file_name.size(); ++index) {
      if (content.at(index + 2) != static_cast<uint8_t>(initial_file_name[index])) {
        goto init_false;
      }
    }
    init = true;
  init_false:;
  }
  if (!init) {
    const auto write_something = std::make_unique<detail::write>(initial_file_path);
    std::vector<uint8_t> initial_file_info{0x01, 0x0e};
    for (const auto& b : initial_file_name) {
      initial_file_info.emplace_back(static_cast<uint8_t>(b));
    }
    write_something->content(initial_file_info, 0);
  }
}

}  // namespace she_db