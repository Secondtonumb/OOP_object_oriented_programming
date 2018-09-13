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

int main(){
  cXydate dt1;
  cXydate dt2(100);
  cXydate dt3 = 200;
  cXydate dt4(300, 400);
  cXydate dt5 = cXydate(500, 600);
  dt1.disp();
  dt2.disp();
  dt3.disp();
  dt4.disp();
  dt5.disp();
}
