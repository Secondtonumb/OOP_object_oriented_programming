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
  cXydate(const cXydate &another);
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

cXydate::cXydate(const cXydate &another){
  x = another.x; y = another.y;
}

int main(){
  cXydate dt1(100, 200); // 函数说明
  cXydate dt2(dt1);
  cXydate dt3 = dt1;

  dt1.disp();
  dt2.disp();
  dt3.disp();
}
