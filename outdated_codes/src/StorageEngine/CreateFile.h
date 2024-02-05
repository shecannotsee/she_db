//
// Created by  shecannotsee on 2022/8/1.
//

#ifndef SHEDB_CREATEFILE_H
#define SHEDB_CREATEFILE_H
#include <cstdio>

class CreateFile {
 private:
  FILE* pFile_;
  int size_;
 public:
  //默认表大小为4k
  CreateFile();
  //指定创建一定大小的表
  explicit CreateFile(const int& size_with_K);
  ~CreateFile();
 public:
  //创建表结构
  void form();
  //创建表
  void sheData();
  //创建索引
  void sheIndex();
 public:
  void test_create_table();
};


#endif //SHEDB_CREATEFILE_H
