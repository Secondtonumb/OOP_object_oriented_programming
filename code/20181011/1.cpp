#include <iostream>

using namespace std;
class Arr{
  int *a;
  int n;
public:
  Arr(int n){
    a = new int[n];
    this->n = n;
  }
  ~Arr(){
    delete []a;
  }
  void input(int n){
    int i;
    for(i = 0; i < n; i++){
      cin >> a[i];
    }
  }
  void disp(int n){
    int i = 0;
    for(i = 0; i < n; i++){
      cout << a[i] << endl;
    }
  }
};
int main(){
  int num = 10;
  Arr arr(num);
  arr.input(num);
  arr.disp(num);
}
