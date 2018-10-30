#include <iostream>

using namespace std;

class cBase_v{
  int va;
  int vb;
public:
  cBase_v(){va = 0; vb = 0;}
  cBase_v(int a, int b){va = a; vb = b;}
  void set_va(int dt){va = dt;}
  void set_vb(int dt){vb = dt;}
  int get_va(){return va;}
  int get_vb(){return vb;}
  virtual void disp();
};

void cBase_v::disp(){
  cout << "va = " << va << endl;
  cout << "vb = " << vb << endl;
}

class cDerived_v: public cBase_v{
  int vc;
public:
  cDerived_v();
  cDerived_v(int a, int b, int c);
  void set_vc(int dt){vc = dt;}
  int get_vc() {return vc;}
  void disp();
};

cDerived_v::cDerived_v(): cBase_v(){
  vc = 0;
}

cDerived_v::cDerived_v(int a, int b, int c): cBase_v(a, b){
  vc = c;
}

void cDerived_v::disp(){
  cBase_v::disp();
  cout << "vc = " << vc  << endl;
}

int main(){
  cBase_v dt1(10, 20);
  cDerived_v dt3(300, 400, 500);
  cBase_v *p;
  p = & dt1;
  p->disp();
  p = & dt3;
  p->disp();
}
