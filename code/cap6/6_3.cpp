#include <string.h>
#include <iostream>

using namespace std;
class cXydate{
  int x;
  int y;
public:
  cXydate(int a, int b);
  void clear(){
    x = 0;
    y = 0;
  }
  void disp(){
    cout << "x = " << x << "y = " << y << endl;
  }
};
cXydate:: cXydate(int a, int b){
  x = a;
  y = b;
}
int main(){
  cXydate dt1(100, 100);
  dt1.disp();
}
