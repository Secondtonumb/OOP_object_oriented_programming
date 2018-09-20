#include <iostream>

using namespace std;

class A{
  friend class B;
public:
  A() { x = 10;}
  void Display(){
    cout << x <<endl;
  }
private:
  int x;
};

class B{
public:
  B() { a.x = 20;}
  void Set(int i);
  void Display();
private:
  A a;
};

void B::Set(int i){
  a.x = i;
}
void B::Display(){
  a.Display();
}
int main(){
  B var;
  var.Display();
  var.Set(11);
  var.Display();
}
