//
// Created by shecannotsee on 24-2-5.
//

#include "data_type_operator.h"

namespace she_db {

data_type_operator::data_type_operator(std::string&& file_path) noexcept
    : file_path_(std::move(file_path)), p_file_(fopen(file_path_.c_str(), "rb+"), &fclose) {
  if (!p_file_) {
    throw std::runtime_error("File pointer is null," + file_path_);
  }
}

bool data_type_operator::read_boolean(const int offset) const noexcept {
  union {
    bool _1;
    char _2[1];
  } tmp;
  // move ptr
  if (fseek(p_file_.get(), offset, SEEK_SET) != 0) {
    throw std::runtime_error("Error seeking to offset");
  }
  // read data
  if (fread(&tmp._2, sizeof(char), boolean::size, p_file_.get()) != boolean::size) {
    throw std::runtime_error("Error writing to file");
  }
  // init ptr
  if (fseek(p_file_.get(), NULL, SEEK_SET) != 0) {
    throw std::runtime_error("Error seeking to offset");
  }
  return tmp._1;
}

int8_t data_type_operator::read_int8(int offset) const noexcept {
  union {
    int8_t _1;
    char _2[1];
  } tmp;
  // move ptr
  if (fseek(p_file_.get(), offset, SEEK_SET) != 0) {
    throw std::runtime_error("Error seeking to offset");
  }
  // read data
  if (fread(&tmp._2, sizeof(char), int8::size, p_file_.get()) != int8::size) {
    throw std::runtime_error("Error writing to file");
  }
  // init ptr
  if (fseek(p_file_.get(), NULL, SEEK_SET) != 0) {
    throw std::runtime_error("Error seeking to offset");
  }
  return tmp._1;
}

int16_t data_type_operator::read_int16(int offset) const noexcept {
  union {
    int16_t _1;
    char _2[2];
  } tmp;
  // move ptr
  if (fseek(p_file_.get(), offset, SEEK_SET) != 0) {
    throw std::runtime_error("Error seeking to offset");
  }
  // read data
  if (fread(&tmp._2, sizeof(char), int16::size, p_file_.get()) != int16::size) {
    throw std::runtime_error("Error writing to file");
  }
  // init ptr
  if (fseek(p_file_.get(), NULL, SEEK_SET) != 0) {
    throw std::runtime_error("Error seeking to offset");
  }
  return tmp._1;
}

int32_t data_type_operator::read_int32(int offset) const noexcept {
}

int64_t data_type_operator::read_int64(int offset) const noexcept {
}

float data_type_operator::read_float32(int offset) const noexcept {
}

double data_type_operator::read_float64(int offset) const noexcept {
}

void data_type_operator::write_boolean(int offset, bool input_t) const noexcept {
  union {
    bool _1;
    char _2[1];
  } tmp;
  tmp._1           = input_t;
  const auto input = tmp._2;
  // move ptr
  if (fseek(p_file_.get(), offset, SEEK_SET) != 0) {
    throw std::runtime_error("Error seeking to offset");
  }
  // write data
  if (fwrite(input, sizeof(char), boolean::size, p_file_.get()) != boolean::size) {
    throw std::runtime_error("Error writing to file");
  }
  // init ptr
  if (fseek(p_file_.get(), NULL, SEEK_SET) != 0) {
    throw std::runtime_error("Error seeking to offset");
  }
}
void data_type_operator::write_int8(int offset, int8_t input) const noexcept {
  // move ptr
  if (fseek(p_file_.get(), offset, SEEK_SET) != 0) {
    throw std::runtime_error("Error seeking to offset");
  }
  // write data
  if (fwrite(&input, sizeof(char), int8::size, p_file_.get()) != int8::size) {
    throw std::runtime_error("Error writing to file");
  }
  // init ptr
  if (fseek(p_file_.get(), NULL, SEEK_SET) != 0) {
    throw std::runtime_error("Error seeking to offset");
  }
}
void data_type_operator::write_int16(int offset, int16_t input_t) const noexcept {
  union {
    int16_t _1;
    char _2[2];
  } tmp;
  tmp._1           = input_t;
  const auto input = tmp._2;
  // move ptr
  if (fseek(p_file_.get(), offset, SEEK_SET) != 0) {
    throw std::runtime_error("Error seeking to offset");
  }
  // write data
  if (fwrite(&input, sizeof(char), int16::size, p_file_.get()) != int16::size) {
    throw std::runtime_error("Error writing to file");
  }
  // init ptr
  if (fseek(p_file_.get(), NULL, SEEK_SET) != 0) {
    throw std::runtime_error("Error seeking to offset");
  }
}
void data_type_operator::write_int32(int offset, int32_t input_t) const noexcept {
  union {
    int32_t _1;
    char _2[4];
  } tmp;
  tmp._1           = input_t;
  const auto input = tmp._2;
  // move ptr
  if (fseek(p_file_.get(), offset, SEEK_SET) != 0) {
    throw std::runtime_error("Error seeking to offset");
  }
  // write data
  if (fwrite(&input, sizeof(char), int32::size, p_file_.get()) != int32::size) {
    throw std::runtime_error("Error writing to file");
  }
  // init ptr
  if (fseek(p_file_.get(), NULL, SEEK_SET) != 0) {
    throw std::runtime_error("Error seeking to offset");
  }
}
void data_type_operator::write_int64(int offset, int64_t input_t) const noexcept {
  union {
    int32_t _1;
    char _2[8];
  } tmp;
  tmp._1           = input_t;
  const auto input = tmp._2;
  // move ptr
  if (fseek(p_file_.get(), offset, SEEK_SET) != 0) {
    throw std::runtime_error("Error seeking to offset");
  }
  // write data
  if (fwrite(&input, sizeof(char), int64::size, p_file_.get()) != int64::size) {
    throw std::runtime_error("Error writing to file");
  }
  // init ptr
  if (fseek(p_file_.get(), NULL, SEEK_SET) != 0) {
    throw std::runtime_error("Error seeking to offset");
  }
}
void data_type_operator::write_float32(int offset, float input) const noexcept {
  // move ptr
  if (fseek(p_file_.get(), offset, SEEK_SET) != 0) {
    throw std::runtime_error("Error seeking to offset");
  }
  // write data
  if (fwrite(&input, sizeof(float), 1, p_file_.get()) != float32::size) {
    throw std::runtime_error("Error writing to file");
  }
  // init ptr
  if (fseek(p_file_.get(), NULL, SEEK_SET) != 0) {
    throw std::runtime_error("Error seeking to offset");
  }
}
void data_type_operator::write_float64(int offset, double input) const noexcept {
  // move ptr
  if (fseek(p_file_.get(), offset, SEEK_SET) != 0) {
    throw std::runtime_error("Error seeking to offset");
  }
  // write data
  if (fwrite(&input, sizeof(double), 1, p_file_.get()) != float64::size) {
    throw std::runtime_error("Error writing to file");
  }
  // init ptr
  if (fseek(p_file_.get(), NULL, SEEK_SET) != 0) {
    throw std::runtime_error("Error seeking to offset");
  }
}
}  // namespace she_db