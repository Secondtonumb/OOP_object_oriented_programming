#include <iostream>

using namespace std;

void myfunc(int &a){
  ++a;
}

int main(){
  int dt = 10;
  int &rf = dt;
  myfunc(rf);
  cout << rf << '\n';
  myfunc(dt);
  cout << dt << '\n';
}

// 当引用作为函数形参时，形参的改变将直接影响到与其对应的实参。
