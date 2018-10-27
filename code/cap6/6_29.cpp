#include <iostream>

using namespace std;

class inner_class{
private:
  int x;
public:
  inner_class(int z){x = z;}
  void write() {cout << x << endl;}
};

class outer_class{
private:
  int y;
  inner_class x;
  inner_class r;
public:
  outer_class(int a, int b, int c);
  void write(){cout << y << endl;}
  void write_inner_x(){x.write();}
  void write_inner_r(){r.write();}
};

outer_class::outer_class(int a, int b, int c): x(a), r(b), y(c){
  //  y = z;
}

int main(){
  outer_class object(10, 20, -12);
  object.write_inner_x();
  object.write_inner_r();
  object.write();
}

