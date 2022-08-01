//
// Created by  shecannotsee on 2022/8/1.
//

#include "CreateFile.h"

CreateFile::CreateFile()
    : pFile_(nullptr),
      size_(4) {
};
CreateFile::CreateFile(const int& size_with_K) {
  CreateFile();
  size_ = size_with_K;
};

CreateFile::~CreateFile() {
  fclose(pFile_);
};

void CreateFile::form() {
  // TODO:需要表结构设计
};

void CreateFile::sheData() {
  // TODO:若文件名存在需要给出一定信息
  // TODO:需要指定表名
  pFile_ = fopen("./tableName.sheData","wb+");
  fseek(pFile_, 1024 * size_ - 1, SEEK_SET);
  char buff = 0x00;
  fwrite(&buff, sizeof(char), 1, pFile_);
};

void CreateFile::sheIndex() {
  // TODO:需要索引结构设计
};
