//
// Created by shecannotsee on 24-2-5.
//

#include "data_type_operator.h"

namespace she_db {
data_type_operator::data_type_operator(std::string&& file_path) : file_path_(std::move(file_path)) {
}
}  // namespace she_db