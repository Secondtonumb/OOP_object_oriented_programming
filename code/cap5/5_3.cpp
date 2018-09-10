#include <iostream>

using namespace std;

int a;
int * readonly(){
  return &a;
}
int main(){
  int b = 5;
  * readonly() = b;
  cout << "a = " << a;
}
