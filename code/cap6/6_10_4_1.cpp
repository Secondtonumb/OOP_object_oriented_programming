#include <iostream>

using namespace std;

class addeq{
  int x, y;
public:
  addeq(int ar = 0, int b = 0);
  addeq & operator += (const addeq &c);
  void disp(){
    cout << "x= " << x << "y= " << y << endl;
  }
};

addeq::addeq(int a, int b){
  x = a;
  y = b;
}
addeq &addeq::operator +=(const addeq &c){
  x += c.x;
  y += c.y;
  return *this;
}
int main(){
  addeq a(10, 10), b(30, 40), c;
  b += a;
  b.disp();
  c = b += a;
  c.disp();
}
