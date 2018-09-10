#include <iostream>

using namespace std;

int main(){
  int n;
  long int result;
  long int fact(int);
  while(1){
    cout << "Input a number:";
    cin >> n;
    if(n >= 0) break;
  }
  result = fact(n);
  cout << "Result = " << result;
}

long int fact(int n){
  long int f;
  if(n == 0) f = 1;
  else f = n *fact(n - 1);
  return(f);
}
