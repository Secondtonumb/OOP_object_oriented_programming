#include <iostream>
using namespace std;
int main(){
  double x;
  int y;
  cin >> x;
  if(x < 0) y = -1;
  else if(x > 0) y = 1;
  else y = 0;
  cout << "Y = "<< y << endl;
}
