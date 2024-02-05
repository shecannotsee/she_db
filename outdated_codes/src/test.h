//
// Created by  shecannotsee on 2022/8/1.
//

#ifndef SHEDB_TEST_H
#define SHEDB_TEST_H

#include <sheLog/sheLog.hpp>
//  //log example
//  sheLog::SheLog log("./","myLog");
//  log.logMessage(sheLog::logLevel::INFO,"message");
#include "StorageEngine/CreateFile.h"
#include "sqlParse/select.h"


void test_create_file() {
  //尝试添加以一个16k的表
  CreateFile t(16);
  t.sheData();
  sheLog::SheLog log("./","sheDBLog");
  log.logMessage(sheLog::logLevel::INFO," create table(16k)");
};

void test_select_parse() {
  std::string sql = "select name from user where age > 10;";
  std::string s = select_parse(sql);
  sheLog::SheLog log("./","sheDBLog");
  log.logMessage(sheLog::logLevel::INFO," sql parse is:"+s);
};

#endif //SHEDB_TEST_H
