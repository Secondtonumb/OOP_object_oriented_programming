#include <iostream>
using namespace std;

class cAdd{
  int va;
  int vb;
public:
  cAdd(){va = 0; vb = 0;}
  cAdd(int a, int b){va = a; vb = b;}
  void set_va(int dt) {va = dt;}
  void set_vb(int dt) {vb = dt;}
  int get_va() {return va;}
  int get_vb() {return vb;}
  void disp();
};

cAdd add(cAdd &data1, cAdd &data2){
  cAdd sum;
  sum.set_va(data1.get_va() + data2.get_va());
  sum.set_vb(data1.get_vb() + data2.get_vb());
  return sum;
}

void cAdd::disp(){
  cout << "va = " << va << endl;
  cout << "vb = " << vb << endl;
}

int main(){
  cAdd a(100, 200), b(10, 20), c;
  c =add(a, b);
  c.disp();
}
