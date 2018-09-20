#include <iostream>
using namespace std;
class xx{
private:
  int x;
public:
  xx () { x = 0; }
  void disp();
  void display();
};

class yy{
private:
  int y;
  void disp() { cout << "y= " << y << endl;}
public:
  yy(int a) {y = a;}
  friend void xx::disp();
};

void xx::disp(){
  yy y(1);
  y.disp();
}
void xx::display(){
  yy y(2);
}

int main(){
  xx x;
  x.disp();
}
