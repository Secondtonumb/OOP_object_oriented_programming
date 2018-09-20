#include <iostream>

using namespace std;

class cAdata{
  int a;
public:
  cAdata(int x){a = x;}
  operator int() { return a;}
  void disp() {cout << "a = " << a << endl;}
};
int main(){
  cAdata dt = 1234;
  int idt = dt;
  dt.disp();
  cout << "idt = " << idt <<endl;
}
