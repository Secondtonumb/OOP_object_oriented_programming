#include <iostream>

using namespace std;

class funover{
  int x;
public:
  funover(int a=10){
    x = a;
  }
  int operator()(){
    return x;
  }
  int operator()(int y){
    return x + y;
  }
};

int main(){
  funover f(20);
  cout << "func1 = " << f() << endl;
  cout << "func2 = " << f(100) << endl;
}
