#include <iostream>

using namespace std;

#define Max(a, b) ((a) > (b) ? (a) : (b))
inline int max(int a, int b){
  if (a > b)
    return a;
  else return b;
}

int main(){
  int x,  y, maxdt;
  x = 10; y = 20;
  maxdt = Max(++x, ++y);
  // maxdt = ((++x) > (++y) ? (++x): (++y));
  cout << "Macro x=" << x << "y = " << y << "maxdt = "<< maxdt << endl;
  x = 10; y = 20;
  maxdt = max(++x, ++y);
  cout << "inline x=" << x << "y = " << y << "maxdt = "<< maxdt << endl;
}

