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

 private:
 public:  // basic data types
  bool read_boolean(int offset) const noexcept;
  int8_t read_int8(int offset) const noexcept;
  int16_t read_int16(int offset) const noexcept;
  int32_t read_int32(int offset) const noexcept;
  int64_t read_int64(int offset) const noexcept;
  float read_float32(int offset) const noexcept;
  double read_float64(int offset) const noexcept;

  void write_boolean(int offset, bool) const noexcept;
  void write_int8(int offset, int8_t) const noexcept;
  void write_int16(int offset, int16_t) const noexcept;
  void write_int32(int offset, int32_t) const noexcept;
  void write_int64(int offset, int64_t) const noexcept;
  void write_float32(int offset, float) const noexcept;
  void write_float64(int offset, double) const noexcept;

 public:  // complex data types
};

}  // namespace she_db

#endif  // DATA_TYPES_RW_H
