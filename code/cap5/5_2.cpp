#include <iostream>

using namespace std;
int *pfunc(int *p){
  *p = 10;
  return p;
}

int main(){
  int x = 5;
  int *p;
  p = pfunc(&x);

  cout << "*p = " << *p << endl;
  cout << "x = " << x << endl;
}
