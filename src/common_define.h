//
// Created by shecannotsee on 24-2-5.
//

#ifndef COMMON_DEFINE_H
#define COMMON_DEFINE_H

#include <string>
#include <type_traits>

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

template <typename T, T V, int s>
struct integral_constant {
  constexpr static T value  = V;
  constexpr static int size = s;
  using type                = T;
};

using boolean = integral_constant<data_type, data_type::boolean, 1>;
using int8    = integral_constant<data_type, data_type::int8   , 1>;
using int16   = integral_constant<data_type, data_type::int16  , 2>;
using int32   = integral_constant<data_type, data_type::int32  , 4>;
using int64   = integral_constant<data_type, data_type::int64  , 8>;
using float32 = integral_constant<data_type, data_type::float32, 4>;
using float64 = integral_constant<data_type, data_type::float64, 8>;

}  // namespace she_db

#endif  // COMMON_DEFINE_H
