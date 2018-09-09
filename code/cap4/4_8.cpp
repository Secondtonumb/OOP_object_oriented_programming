#include "iostream"

using namespace std;

int main(){
  int i;
  int *ip;
  ip = &i;
  i = 10;
  cout << i << ' ' << * ip << endl;
  * ip = 100;
  cout << i << ' ' << * ip << endl;
}
