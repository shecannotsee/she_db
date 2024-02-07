//
// Created by shecannotsee on 24-2-5.
//

#ifndef COMMON_DEFINE_H
#define COMMON_DEFINE_H

#include <memory>
#include <string>

#if __cplusplus >= 201103L && __cplusplus < 201402L
namespace std {
template <typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args) {
  return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}
}  // namespace std
#endif

namespace she_db {
const std::string prefix_path       = "../store/";
const std::string initial_file_name = "initial.she_db";

enum class db_data_type : int {
  boolean = 1,
  int8    = 2,
  int16   = 3,
  int32   = 4,
  int64   = 5,
  float32 = 6,
  float64 = 7,
  string  = 8,
};

template <db_data_type she_type, typename real_type, int byte_size>
struct integral_constant {
  constexpr static db_data_type value = she_type;
  constexpr static int size           = byte_size;
  using type                          = real_type;
};

using she_boolean = integral_constant<db_data_type::boolean, bool, 1>;
using she_int8    = integral_constant<db_data_type::int8, int8_t, 1>;
using she_int16   = integral_constant<db_data_type::int16, int16_t, 2>;
using she_int32   = integral_constant<db_data_type::int32, int32_t, 4>;
using she_int64   = integral_constant<db_data_type::int64, int64_t, 8>;
using she_float32 = integral_constant<db_data_type::float32, float, 4>;
using she_float64 = integral_constant<db_data_type::float64, double, 8>;

}  // namespace she_db

#endif  // COMMON_DEFINE_H
