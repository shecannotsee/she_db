#include <iostream>
#include <sheLog/sheLog.hpp>

int main() {
  sheLog::SheLog log("./","myLog");
  log.logMessage(sheLog::logLevel::INFO,"message");
  std::cout<<"hello sheDB\n";
  return 0;
}