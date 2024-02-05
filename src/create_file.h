//
// Created by shecannotsee on 24-2-5.
//

#ifndef CREATE_FILE_H
#define CREATE_FILE_H

#include <cstdio>
#include <stdexcept>
#include <string>

namespace she_db {

template <int file_size_k>
static void createFile() noexcept {
  const std::string filePath = "../store/tableName.sheData";

  FILE* pFile = fopen(filePath.c_str(), "wb+");

  if (!pFile) {
    throw std::runtime_error("Error opening file");
  }

  const size_t size = 1024 * file_size_k;

  fseek(pFile, size - 1, SEEK_SET);
  constexpr char buff = 0x00;
  fwrite(&buff, sizeof(char), 1, pFile);

  fclose(pFile);
}

}  // namespace she_db

#endif  // CREATE_FILE_H
