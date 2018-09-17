/*
编写一个程序，用于说明当函数的返回值为某个类类型时的用法。
*/
#include <stdio.h>
#include <string.h>

class cString{
  char *s;
public:
  cString(const char*);
  void print(){ printf("%s\n", s);};
  void strcon(char *p);
};

void cString::strcon(char * p){
  strcat(s, p);
}
cString::cString(const char *x){
  s = new char[strlen(x) + 10];
  strcpy(s, x);
}
int main(){
  cString x("Good");
  cString y = x;
  x.print();
  y.print();
  y.strcon("morning!");
  x.print();
  y.print();
}
