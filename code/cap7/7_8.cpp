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

// class cBase_B: public cBase_A{
  
// };

// class cBase_C: public cBase_A{

// };

class cDerived_D: public cBase_B, public cBase_C{

};

int main(){
  cDerived_D x;
  int y, z, s;
  y = x.cBase_B::getx();
  x.setx(11);
  // x.cBase_C::setx(11);
  y = x.cBase_B::getx();
  z = x.cBase_C::getx();
  s = x.cBase_B::getx();
  cout << "y = " << y << endl;
  cout << "z = " << z << endl;
  cout << "s = " << s << endl;
}
