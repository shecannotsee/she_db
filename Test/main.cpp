#include <stdio.h>
const int SIZE = 16;
const char g_data[SIZE] = {0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,
                           0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f};

void t_wirite() {
  FILE* write = nullptr;
  write = fopen("./file/data","w+b");
  if (write!=nullptr) {
    for (auto i : g_data) {
      printf("%ld",fwrite(&g_data,sizeof(char),SIZE*2,write));
    }
    printf("\n");
  } else {
    printf("open file.\n");
  }
  fclose(write);
}
void t_read() {
  FILE* read = nullptr;
  read = fopen("./file/data","r+b");
  char buff[SIZE] = {0};
  if (read!=nullptr) {
    fread(&buff,sizeof(char),SIZE,read);
    for (auto i : buff) {
      printf("%d",buff[i]);
    }
    printf("\n");
  } else {
    printf("open faild.");
  }
  fclose(read);
}
void t_find() {
  FILE* find = nullptr ;
  find = fopen("./file/data","rb");
  char buff = 0x00;
  if (find!=nullptr) {
    //fseek(find,0,SEEK_SET);//指针移动到文件开头
    //fseek(find,0,SEEK_END);//指针移动到文件结尾
    //fseeek(find,100L,SEEK_SET);//指针移动到文件开头往后100个字节处
    //fseek(find,100L,SEEK_CUR);//指针移动到当前指针往后100个字节处
    //fseek(find,-100L,SEEK_END);//指针移动到文件结尾往前100个字节处
    fseek(find,sizeof(char)*3,SEEK_SET);
    fread(&buff,sizeof(char),1,find);
    printf("%d\n",buff);
  } 
}
void create_file() {
  FILE* file_ptr = nullptr ;
  file_ptr = fopen("./file/4k_file","wb+");
  fseek(file_ptr,1024*4-1,SEEK_SET);
  char buff = 0x00;
  fwrite(&buff,sizeof(char),1,file_ptr);
  fclose(file_ptr);
}
int main() {
  //t_wirite();
  //t_read();
  //t_find();
  create_file();
  return 0;
}