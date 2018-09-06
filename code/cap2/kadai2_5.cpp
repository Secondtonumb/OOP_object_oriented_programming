#include <iostream>
using namespace std;
int main(){
  int x = 20, result;
  result = ++x;
  result += x;
  cout << "Result = " << result << '\n';
  result = x--;
  result -= x;
  cout << "Result = " << result << '\n';
}
