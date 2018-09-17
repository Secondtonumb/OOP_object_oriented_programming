#include <iostream>
#include <string.h>

using namespace std;

class cMystring{
  char * text;
public:
  cMystring(char *str);
  void disp(){
    cout << "text = " << text << endl;
  };
  ~cMystring();
};

cMystring::cMystring(char *str){
  cout << str << "constructor\n";
  text = new char[strlen(str) + 1];
  strcpy(text, str);
}

cMystring::~cMystring(){
  cout << text << "destructor\n";
  delete []text;
}
void subfunc(){
  cMystring ss1 = "ABCDE";
  ss1.disp();
}
int main(){
  subfunc();
  cMystring ss2("12345");
  ss2.disp();
}
/*
  如果没有析构函数，在对象中定义的char *text，这样的指针变量时可以自动被释放掉的，但动态申请到的内存空间不能被自动释放掉了，这样其他程序所能使用的内存空间就会禁烧。
  在对象中需要动态申请存储空间是，往往需要定义析构函数，一边在析构函数中释放掉申请到的内存空间
*/
