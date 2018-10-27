#include <iostream>

using namespace std;

class innerA{
public:
  innerA(){ cout << "Entering innerA constructor" << endl;}
  ~innerA(){ cout << "Entering innerA destructor" << endl;}
};

class innerB{
public:
  innerB(){ cout << "Entering innerB constructor" << endl;}
  ~innerB(){ cout << "Entering innerB destructor" << endl;}
};

class outerA{
  innerA A1;
  innerA A2;
  innerB B1;
  innerB B2;
  public:
  outerA(){ cout << "Entering outerA constructor" << endl;}
  ~outerA(){ cout << "Entering outerA destructor" << endl;}
};

int main(){
  outerA X;
}
