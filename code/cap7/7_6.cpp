#include <iostream>
using namespace std;

class cBase{
  int x;
public:
  cBase(int a = 0){
    x = a;
  }
  ~cBase(){
    cout << "Enter cBase destructor" << endl;
  }
  // virtual ~cBase(){
  //   cout << "Enter cBase destructor" << endl;
  // }
  virtual void disp(){
    cout << "x = " << x << endl;
  }
};

class cDerived: public cBase{
  int y;
public:
  cDerived(int a = 0):cBase(){
    y = a;
  }
  ~cDerived(){
    cout << "Enter cDerived destructor" << endl;
  }
  void disp(){
    cBase::disp();
    cout << "y = " << y << endl;
  }
};

int main(){
  cBase *p = new cDerived(10);
  p->disp();
  delete p;
}
