#include <iostream>

using namespace std;
class cBase{
  int va;
  int vb;
public:
  cBase(){ va = 0; vb = 0;}
  cBase(int a, int b) { va = a; vb = b;}
  void set_va(int dt) {va = dt;}
  void set_vb(int dt) {vb = dt;}
  int get_va() {return va;}
  int get_vb() {return vb;}
  void disp();
};

void cBase::disp(){
  cout << "va = " << va << endl;
  cout << "vb = " << vb << endl;
}

class cDerived: public cBase{
  int vc;
public:
  cDerived();
  cDerived(int a, int b, int c);
  void set_vc(int dt) { vc = dt;}
  int get_vc(int dt) {return vc;}
  void disp();
};

cDerived::cDerived(): cBase(){
  vc = 0;
}

cDerived::cDerived(int a, int b, int c): cBase(a, b){
  vc = a;
}

void cDerived::disp(){
  // cout << "va = " << va << endl;
  // cout << "vb = " << vb << endl;
  cBase::disp();
  cout << "vc = " << vc << endl;
}

int main(){
  cout << "cBase class: \n";
  cBase a(10, 20);
  a.disp();
  cout << "cDerived class: \n";
  cDerived b(30, 40, 50);
  b.disp();
  b.set_va(60);
  b.set_vb(70);
  b.set_vc(80);
  b.disp();
}
