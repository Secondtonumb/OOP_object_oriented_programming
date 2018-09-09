#include <iostream>

using namespace std;

int main(){
  int a[10], i, temp;
  for(i = 0; i < 10; i++){
    cin >> a[i];
  }
  cout << '\n';
  for(i = 0; i < 10/2; i++){
    temp = a[i];
    a[i] = a[10 - i - 1];
    a[10 - i - 1] = temp;
  }
  for(i = 0; i < 10; i++)
    cout << a[i] <<endl;
}
