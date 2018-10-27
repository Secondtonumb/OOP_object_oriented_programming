#include <iostream>

using namespace std;

class cConst{
  int va;
  int vb;
public:
  cConst(){va = 0; vb = 0;}
  cConst(int a, int b){va = a; vb = b;}
  void set_va(int dt){va = dt;}
  void set_vb(int dt){vb = dt;};
  int get_va() const {return va;}
  int get_vb() const {return vb;}
  void disp() const;
};

void cConst::disp() const{
  cout << "va = " << va << endl;
  cout << "vb = " << vb << endl;
}

int main(){
  const cConst dt1(10, 20);
  dt1.disp();
  cout << dt1.get_va();
}
