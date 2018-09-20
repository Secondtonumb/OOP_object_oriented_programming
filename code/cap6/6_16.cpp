#include <iostream>

using namespace std;

class cXydata{
  int x;
  int y;
public:
  cXydata() { x = 0; y = 0;}
  cXydata(int a) { x = a; y = 0;}
  cXydata(int a , int b) {x = a; y = b;}
  cXydata(const cXydata &another , int n = 1);
  operator long() {return(x * 10000 + y);}
  void clear() { x = 0; y = 0;}
  void disp() { cout << "x = " << x <<" y = " << y <<endl;}
};
cXydata::cXydata(const cXydata &another, int n){
  if(n < 1) n = 1;
  x = another.x * n; y = another.y * n;
}
int main(){
  cXydata dt1(1234, 5678);
  long ldt;
  dt1.disp();
  ldt = dt1;
  cout << "ldt = "<< ldt << endl;
  cout << "(long)dt1 = "<< (long)dt1 << endl;
}
