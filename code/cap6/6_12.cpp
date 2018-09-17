/*
编写一个程序，用于说明当函数的返回值为某个类类型时的用法。
*/
#include <stdio.h>
#include <string.h>

class cStrpro{
  char *s;
public:
  cStrpro();
  cStrpro(const char*);
  cStrpro(const cStrpro &);
  void print(){ printf("%s\n", s);};
};
cStrpro::cStrpro(){
  s = new char[1];
  *s = '\0';
}
cStrpro::cStrpro(const char *x){
  s = new char[strlen(x) + 1];
  strcpy(s, x);
}
cStrpro::cStrpro(const cStrpro &x){
  s = new char[strlen(x.s) + 1];
  strcpy(s, x.s);
}
int main(){
  cStrpro x("abcd");
  cStrpro y = x;
  x.print();
  y.print();
}
