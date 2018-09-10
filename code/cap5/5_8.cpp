#include <iostream>

using namespace std;

void myinc(int *a){
  *a = 1;
}

int main(){
  int dt = 10;
  myinc(&dt);
  cout << dt << '\n';
}

// int a = 10, b = 20;

// void func(int *p){
//   p = &b;
// }

// int main(){
//   int *q;
//   q = &a;
//   func(q);
//   cout << *q << endl;
// }
