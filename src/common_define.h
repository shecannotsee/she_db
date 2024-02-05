//
// Created by shecannotsee on 24-2-5.
//

#ifndef COMMON_DEFINE_H
#define COMMON_DEFINE_H

#include <string>

namespace she_db {
const std::string prefix_path = "../store/";

enum class data_type : int {
  boolean = 1,
  int8    = 2,
  int16   = 3,
  int32   = 4,
  int64   = 5,
  float32 = 6,
  float64 = 7,
  string  = 8,
};

template <data_type she_type, typename real_type, int byte_size>
struct integral_constant {
  constexpr static data_type value  = she_type;
  constexpr static int size = byte_size;
  using type                = real_type;
};

using boolean = integral_constant<data_type::boolean, bool,    1>;
using int8    = integral_constant<data_type::int8,    int8_t,  1>;
using int16   = integral_constant<data_type::int16,   int16_t, 2>;
using int32   = integral_constant<data_type::int32,   int32_t, 4>;
using int64   = integral_constant<data_type::int64,   int64_t, 8>;
using float32 = integral_constant<data_type::float32, float,   4>;
using float64 = integral_constant<data_type::float64, double,  8>;

}  // namespace she_db

#endif  // COMMON_DEFINE_H
