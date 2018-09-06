#include <iostream>
using namespace std;
int main(){
  char ch;
  cin >> ch;
  if(ch <= 'z' && ch >= 'a')
    ch = ch - 32;
  cout << ch <<endl;
}
