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

inline void test() {
  //尝试添加以一个16k的表
  CreateFile t(16);
  t.sheData();
  sheLog::SheLog log("./","sheDBLog");
  log.logMessage(sheLog::logLevel::INFO," create table(16k)");
}

#endif //SHEDB_TEST_H
