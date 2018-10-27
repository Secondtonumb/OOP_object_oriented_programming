#include <iostream>

using namespace std;

class info{
public:
  int x;
  void func(){
    cout << "Entering info." << endl;
    cout << x << endl;
  }
};

class memacc{
  int y;
  info *p;
public:
  memacc(info *q){
    y = 10; p = q;
  }
  info *operator->(){
    return p;
  }
};

int main(){
  info a;
  memacc b(&a);
  b -> x = 100;
  b -> func();
}
