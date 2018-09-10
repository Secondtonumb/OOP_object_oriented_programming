#include <iostream>

using namespace std;

int &pfunc(int &r){
  return r;
}

int main(){
  int x =5;
  int &p = pfunc(x);
  p = 26;
  cout << "p = " << p << '\n';
  cout << "x = " << x << '\n';
}
