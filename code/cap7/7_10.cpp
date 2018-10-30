#include <iostream>

using namespace std;

class cBase_A{
  int x;
public:
  cBase_A(){x = 10;}
  int getx(){return x;}
  void setx(int a){x = a;}
};

class cBase_B: virtual public cBase_A{
  
};

class cBase_C: virtual public cBase_A{

};

class cDerived_D: public cBase_B, public cBase_C{

};

int main(){
  cDerived_D x;
  int y, z, s;
  y = x.getx();
  x.setx(11);
  y = x.cBase_B::getx();
  z = x.cBase_C::getx();
  s = x.getx();
  cout << "y = " << y << endl;
  cout << "z = " << z << endl;
  cout << "s = " << s << endl;
  cout << "---------" << endl;
  cBase_B b;
  cBase_C c;
  b.setx(22);
  cout << "b = " << b.getx() << " c = " << c.getx() << endl;
  c.setx(33);
  cout << "C = " << c.getx() << " b = " << b.getx() << endl;
  cout << "D = " << x.getx() << endl;
}
