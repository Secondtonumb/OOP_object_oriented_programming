/*
编写一个程序，用于说明当函数的返回值为某个类类型时的用法。
*/
#include <string.h>
#include <iostream>

using namespace std;
class cXydate{
  int x;
  int y;
public:
  cXydate();
  cXydate(int a);
  cXydate(int a, int b);
  void clear(){
    x = 0;
    y = 0;
  }
  void disp(){
    cout << "x = " << x << "y = " << y << endl;
  }
};

cXydate:: cXydate(){
  x = 0;
  y = 0;
}
cXydate:: cXydate(int a){
  x = a;
  y = 0;
}
cXydate:: cXydate(int a, int b){
  x = a;
  y = b;
}
// 定义全局函数dt1(), 返回值是类 cXydata 类型名 
class cInt{
  int x;
  int xRet() { return x;}
};

cXydate dt1(){
  cXydate a(800, 900);
  return a;
}

int main(){
  cXydate dt1(); // 函数说明
  cXydate dt2;
  dt2.disp();
  dt2 = dt1();   // 函数调用
  dt2.disp();
}
