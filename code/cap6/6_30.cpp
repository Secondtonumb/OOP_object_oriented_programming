#include <iostream>

using namespace std;

class cConstant{
public:
  const int iConst;
  const double fConst;
  int vInt;
public:
  cConstant(): iConst(100), fConst(3.14){
    vInt = 200;
  }
};

int main(){
  cConstant cVar;
  cout << "iConst = " << cVar.iConst << endl;
  cout << "fConst = " << cVar.fConst << endl;
  cout << "vInt = " << cVar.vInt << endl;
}
