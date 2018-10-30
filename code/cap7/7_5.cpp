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
  virtual void disp() = 0;
};

void cBase_v::disp(){
  cout << "va = " << va << endl;
  cout << "vb = " << vb << endl;
}

class cDerivedA: public cBase_v{
  int vc;
public:
  cDerivedA();
  cDerivedA(int a, int b, int c);
  void set_vc(int dt){vc = dt;}
  int get_vc() {return vc;}
  void disp();
};

cDerivedA::cDerivedA(): cBase_v(){
  vc = 0;
}

cDerivedA::cDerivedA(int a, int b, int c): cBase_v(a, b){
  vc = c;
}

void cDerivedA::disp(){
  cout << "va = " << get_va() << endl;
  cout << "vb = " << get_vb() << endl;
  cout << "vc = " << vc << endl;
}

class cDerivedB: public cBase_v{
  int vc;
public:
  cDerivedB();
  cDerivedB(int a, int b, int c);
  void set_vc(int dt){vc = dt;}
  int get_vc() {return vc;}
  void disp();
};

cDerivedB::cDerivedB(): cBase_v(){
  vc = 0;
}

cDerivedB::cDerivedB(int a, int b, int c): cBase_v(a, b){
  vc = c;
}

void cDerivedB::disp(){
  //  cBase_v::disp();
  cout << "va = " << get_va() << endl;
  cout << "vb = " << get_vb() << endl;
  cout << "vc = " << vc << endl;
}

int main(){
  // cBase_v dt1(10, 20);
  cDerivedA dta(300, 400, 500);
  cDerivedB dtb(600, 700, 800);
  /*
  If You define a pointer which belonging to Base class, then for those derived class
  You Don't have to cast it into and Derived pointer.
  Which inplemented as below
  */
  // cBase_v *p = &dta;
  // p->disp();
  // p = &ptb;
  // p->disp();
  cDerivedA *p = &dta;
  p->disp();
  p = (cDerivedA *)&dtb;
  p->disp();
}
