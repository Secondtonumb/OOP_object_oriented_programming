#include <iostream>
#include <string.h>

using namespace std;

class str{
  char *s;
public:
  str(void);
  str(const char *);
  str(const str  &);
  ~str(){delete []s;};
  str & operator=(const char *);
  str & operator=(const str &);
  char & operator [](int);
  operator char *();
  void print() const{
    cout << s << endl;
  }
  friend int operator == (const str &x, const str &y){
    return (strcmp(x.s, y.s) == 0);
  }
  friend int operator != (const str &x, const str &y){
    return (strcmp(x.s, y.s) != 0);
  }
};

str::str(){
  s = new char[1];
  s = '\0';
}
str::str(const char *x){
  s = new char[1];
  strcpy(s, x);
}
str::str(const str &x){
  s = new char[strlen(x.s) + 1];
  strcpy(s, x.s);
}
str & str::operator = (const char *x){
  delete []s;
  s = new char[strlen(x) + 1];
  strcpy(s, x);
  return (*this);
}
str & str::operator = (const str &x){
  delete []s;
  s = new char[strlen(x.s) + 1];
  strcpy(s, x.s);
  return (*this);
}

char & str::operator [] (int i){
  return s[i];
}

str::operator char *(){
  char *p = new char[strlen(s) + 1];
  strcpy(p, s);
  return p;
}

int main(){
  str x;
  str y("abcd");
  str z = y;
  str a;
  a = "abcdef";
  a[3] = a[0];
  a[4] = 'z';
  x = y;
  printf("a: "); a.print(); putchar('\n');
  printf("x: "); x.print(); putchar('\n');
  printf("y: "); y.print(); putchar('\n');
  printf("y: "); y.print(); putchar('\n');
  printf("x == y %d\n", x == y);
  printf("y == z %d\n", y == z);
  printf("a == x %d\n", a == x);
  printf("y != x %d\n", y != x);
  printf("x != y %d\n", x != y);
  printf("a != x %d\n", a != x);
  char c[100] = "cc";
  strcat(c, a);
  printf("%s \n", c);
  return 0;
}
