/*
编写一个程序，用于说明当函数的返回值为某个类类型时的用法。
*/
#include <string.h>
#include <iostream>

using namespace std;
class xx{
  int x;
public:
  xx(){ x = 0;}
  xx(int a){ x = a;}
  void set(int a) {x = a;}
  void disp(){cout << "x = " << x << endl;}
};
void f(xx x){
// void f(xx &x){
  xx y(10);
  x = y;
  // x.set(10);
  x.disp();
}
int main(){
  xx x;
  f(x);
  x.disp();
}
