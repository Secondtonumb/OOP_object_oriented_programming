// Fibonacci sequence
#include <iostream>
using namespace std;
int main(){
  int i;
  long int F1, F2;
  F1 = 1; F2 = 1;
  for(i = 1; i <=20; i++){
    cout.width(10);
    cout << F1;
    cout.width(10);
    cout << F2;
    if(1 % 2 == 0) cout << '\n';
    F1 = F1 + F2;
    F2 = F1 + F2;
  }
}
