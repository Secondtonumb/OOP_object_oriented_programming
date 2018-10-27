#include <iostream>

using namespace std;

class assignover{
  int x;
  const int y;
public:
  assignover(int a, int b): y(b){
    x = a;
  }
  assignover &operator= (assignover &a){
    x = a.x;
    return *this;
  }
  void disp(){
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
  }
};

int main(){
  assignover a(10, 20), b(50, 60);
  a.disp();
  b.disp();
  b = a;
  b.disp();
}
