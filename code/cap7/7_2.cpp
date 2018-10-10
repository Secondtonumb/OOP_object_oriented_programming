#include <iostream>
using namespace std;

class cBase{
  int va;
  int vb;
public:
  cBase(){
    va = 0;
    vb = 0;
  }
  cBase(int a, int b){
    va = a;
    vb = b;
  }
  void set_va(int dt){
    va = dt;
  }
  void set_vb(int dt){
    vb = dt;
  }
  int get_va(){
    return va;
  }
  int get_vb(){
    return vb;
  }
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
  void set_vc(int dt){
    vc = dt;
  }
  int get_vc(){
    return vc;
  }
  void disp();
};

cDerived::cDerived():cBase(){
  vc = 0;
}
cDerived::cDerived(int a, int b, int c): cBase(a, b){
  vc = c;
}

void cDerived::disp(){
  // cout << "va = " << vc >> endl;
  // cout << "vb = " << vc >> endl;
  cBase::disp();
  cout << "vc = " << vc << endl;
}

int main(){
  cBase dt1(10, 20);
  cDerived dt3(300, 400, 500);
  cBase *p;
  dt1.disp();
  dt3.disp();
  p = &dt1;
  p -> disp();
  p = &dt3;
  p -> disp();
}
