//
// Created by shecannotsee on 24-2-5.
//

#ifndef DATA_TYPES_RW_H
#define DATA_TYPES_RW_H

#include <memory>

#include "common_define.h"

namespace she_db {

class data_type_operator {
 public:
  // default ctor: off
  data_type_operator()  = delete;
  ~data_type_operator() = default;
  // copy:off
  data_type_operator(const data_type_operator&)            = delete;
  data_type_operator& operator=(const data_type_operator&) = delete;
  // move:off
  data_type_operator(data_type_operator&&)            = delete;
  data_type_operator& operator=(data_type_operator&&) = delete;
  // ctor
  explicit data_type_operator(std::string&& file_path) noexcept;

 private:
  std::string file_path_;
  std::unique_ptr<FILE, decltype(&fclose)> p_file_;

 public:  // basic data types
  template <typename type>
  typename type::type read(const int offset) const noexcept {
    union {
      typename type::type real;
      char c[type::size];
    } tmp;
    // move ptr
    if (fseek(p_file_.get(), offset, SEEK_SET) != 0) {
      throw std::runtime_error("Error seeking to offset");
    }
    // read data
    if (fread(&tmp.c, sizeof(char), type::size, p_file_.get()) != type::size) {
      throw std::runtime_error("Error writing to file");
    }
    // init ptr
    if (fseek(p_file_.get(), 0, SEEK_SET) != 0) {
      throw std::runtime_error("Error seeking to offset");
    }
    return tmp.real;
  }

  template <typename type>
  void write(const int offset, typename type::type input_t) const noexcept {
    union {
      typename type::type real;
      char c[type::size];
    } tmp;
    tmp.real         = input_t;
    const auto input = tmp.c;
    // move ptr
    if (fseek(p_file_.get(), offset, SEEK_SET) != 0) {
      throw std::runtime_error("Error seeking to offset");
    }
    // write data
    if (fwrite(input, sizeof(char), type::size, p_file_.get()) != type::size) {
      throw std::runtime_error("Error writing to file");
    }
    // init ptr
    if (fseek(p_file_.get(), 0, SEEK_SET) != 0) {
      throw std::runtime_error("Error seeking to offset");
    }
  }

 public:  // complex data types
};

}  // namespace she_db

#endif  // DATA_TYPES_RW_H
