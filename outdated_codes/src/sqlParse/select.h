//
// Created by  shecannotsee on 2022/8/1.
//

#ifndef SHEDB_SELECT_H
#define SHEDB_SELECT_H

#include <string>
//simple select parse
//example: select name from user where age > 10;

std::string select_parse(const std::string& sql) {
  for (char e : sql) {
    if (e=='s' | e=='S') {}
  };

  std::string res = "select parse";
  return res;
};


#endif //SHEDB_SELECT_H
