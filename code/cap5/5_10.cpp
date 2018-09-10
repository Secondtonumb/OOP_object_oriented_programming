#include <iostream>

using namespace std;

int sum_and_clr (int a[], int size){
  int i, sum = 0;
  for(i = 0; i < size; i++){
    // sum += a[i];
    // a[i] = 0;
    sum += *(a + i);
    *(a + i) = 0;
  }
  return sum;
}


int main(){
  int dt[5] = {10, 20, 30, 40, 50};
  cout << "Sum = " << sum_and_clr(dt, 5) << endl;
  cout << "dt[0] = " << dt[0] << '\n';
}
