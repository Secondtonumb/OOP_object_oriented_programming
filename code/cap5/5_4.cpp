#include <iostream>

using namespace std;

int * retip(int a[]){
  return a;
}

int main(){
  int b[5] = {1, 2, 3, 4, 5};
  int *p = retip(b);
  for(int i = 0; i < 5; i++){
    cout << "a[" << i + 1 << "]" << *(p + i) << endl;
  }
}

