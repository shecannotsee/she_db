#ifndef _STORAGE_ENGINE_TEST_H_
#define _STORAGE_ENGINE_TEST_H_

class storage_engine_test {
 public:
  storage_engine_test();
  ~storage_engine_test();
 public://base test
  void t_write();
  void t_read();
  void t_find();
  void create_file();
 public:
  void _f();

};


#endif//!_STORAGE_ENGINE_TEST_H_