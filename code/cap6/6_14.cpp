/*
  深复制
*/
#include <stdio.h>
#include <string.h>

class cString{
  char *s;
public:
  cString(const char*);
  cString(const cString &);
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
cString::cString(const cString &x){
  s = new char[strlen(x.s) + 10];
  strcpy(s, x.s);
}

int main(){
  cString x("Good");
  cString y = x;
  // cString y(x);
  x.print();
  y.print();
  y.strcon("morning!");
  x.print();
  y.print();
}
