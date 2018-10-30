#include <iostream>

using namespace std;

class base{
public:
  virtual int func(void){
    cout << "base:: func" <<endl;
    return 10;
  }
};

class derived: public base{
public:
  int func(void){
    cout << "derived: base" << endl;
    return 20;
  }
};

int main(){
  derived d;
  base * b1 = &d;
  base & b2 = d;
  base b3 = d;
  b1 ->func();
  b2.func();
  b3.func();
}
