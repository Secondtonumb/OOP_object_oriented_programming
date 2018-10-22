#include <iostream>
namespace mm{
  int x = 9;
  int y = 8;
  class xy{
    int a;
  public:
    xy(){a = 0;}
    void seta(int x){
      a = x;
    }
    void disp(){
      std::cout << "a = " << a << std::endl;
    }
  };
}

int x = 100;
using namespace mm;
int main(){
  int x = 10;
  xy y;
  y.seta(20);
  y.disp();
  std::cout << x << std::endl;
  std::cout << ::x << std::endl;
  std::cout << mm::x << std::endl;
}
