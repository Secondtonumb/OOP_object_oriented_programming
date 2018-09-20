#include <iostream>
using namespace std;

class cFriend{
  int va;
  int vb;
public:
  cFriend(){va = 0; vb = 0;}
  cFriend(int a, int b){va = a; vb = b;}
  void set_va(int dt) {va = dt;}
  void set_vb(int dt) {vb = dt;}
  int get_va() {return va;}
  int get_vb() {return vb;}
  void disp();
  friend void oneline_disp(cFriend dt);
};
void cFriend::disp(){
  cout << "va" << va << endl;
  cout << "vb" << vb << endl;
}
void oneline_disp(cFriend dt){
  cout << "va = " << dt.va << "vb = " << dt.vb << endl;
  cout << "vs = " << dt.get_va() << "vb = " << dt.get_vb() << endl;
}
int main(){
  cFriend dt1(10, 20);
  dt1.disp();
  oneline_disp(dt1);
}
