#include <iostream>

using namespace std;
class xyz{
  int x, y, z;
public:
  xyz(int a, int b, int c){
    x = a; y = b; z = c;
  }
  xyz(xyz &m){
    x = m.x; y = m.y; z = m.z;
    cout << "Entering copy constructor." <<endl;
  }
  int getx(){ return x;}
  int gety(){ return y;}
  int getz(){ return z;}  
};

void f1(xyz m){
  cout << "f: " << m.getx() << m.gety() << m.getz() << endl;
}

void f2(xyz &m){
  cout << "f: " << m.getx() << m.gety() << m.getz() << endl;
}
xyz g(){
  xyz m(7, 8, 9);
  cout << "g: " << m.getx() << m.gety() << m.getz() << endl;
  return m;
}
int main(){
  xyz a(10, 20, 30);
  cout << a.getx() << a.gety() << a.getz() << endl;
  xyz b(a);
  cout << b.getx() << b.gety() << b.getz() << endl;
  xyz c(1, 2, 3);
  f1(c);
  f2(c);
  xyz n(1, 2, 3);
  cout << n.getx() << n.gety() << n.getz() << endl;
  n = g(); //这里调用的结果好像不对。。
  cout << n.getx() << n.gety() << n.getz() << endl;
}
  
