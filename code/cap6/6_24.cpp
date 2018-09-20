#include <iostream>
using namespace std;

class cAddM{
  int va;
  int vb;
public:
  cAddM(){va = 0; vb = 0;}
  cAddM(int a, int b){va = a; vb = b;}
  void set_va(int dt) {va = dt;}
  void set_vb(int dt) {vb = dt;}
  int get_va() {return va;}
  int get_vb() {return vb;}
  void disp();
  cAddM operator + (cAddM &second);
  cAddM operator - (cAddM &second);
};

void cAddM::disp(){
  cout << "va = " << va << endl;
  cout << "vb = " << vb << endl;
}

cAddM cAddM::operator + (cAddM &second){
  return cAddM(va + second.va, vb + second.vb);
  // cAddM cw;
  // cw.set_va(va + second.va);
  // vw.set_vb(vb + second.vb);
  // return cw;
}

cAddM cAddM::operator - (cAddM &second){
  return cAddM(va - second.va, vb - second.vb);
  // cAddM cw;
  // cw.set_va(va - second.va);
  // vw.set_vb(vb - second.vb);
  // return cw;
}
int main(){
  cAddM a(100, 200), b(10, 20), c;
  c = a + b;
  c.disp();
  c = a - b;
  c.disp();
}
