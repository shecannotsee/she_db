//
// Created by shecannotsee on 24-2-5.
//

#ifndef DATA_TYPES_RW_H
#define DATA_TYPES_RW_H

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
  explicit data_type_operator(std::string&& file_path);

 private:
  std::string file_path_;

 public:  // basic data types
  struct read {
    bool boolean_ww();
    int8_t int8_ww();
    int16_t int16_ww();
    int32_t int32_ww();
    int64_t int64_ww();
    float float32_ww();
    double float64_ww();
  };
  struct write {
    bool boolean_ww();
    int8_t int8_ww();
    int16_t int16_ww();
    int32_t int32_ww();
    int64_t int64_ww();
    float float32_ww();
    double float64_ww();
  };

 public:  // complex data types
};

}  // namespace she_db

#endif  // DATA_TYPES_RW_H
