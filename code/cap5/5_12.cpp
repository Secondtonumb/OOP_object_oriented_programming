#include <iostream>
using namespace std;
int main(){
  double Xpower(double, int);
  double x;
  int n;
  double r;
  cin >> x >> n;
  r = Xpower(x, n);
  cout << "Result = " << r;
}

double Xpower(double x, int n){
  if(n <= 0) return 1;
  else return(x * Xpower(x, n - 1));
}
