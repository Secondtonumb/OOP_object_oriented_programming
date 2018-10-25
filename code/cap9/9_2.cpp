// ERROR on Clang -> max is ambiguous
#include <iostream>

using namespace std;
template <class T>
T max(T x, T y){
  return x + y;
}
int max(int a, int b){
  return a - b;
}
int main(){
  int x;
  double y;
  x = max(12, 10);
  y = max(1.2, 1.0);
  cout << "x = " << x << " y = " << y << endl;
}
