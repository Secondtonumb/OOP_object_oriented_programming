#include <iostream>
using namespace std;
/*
As odd numbers can only be divided by 1 && itself
For int i under n
If i can not be devided by none of a number between (2, n - 1) 
then i is an odd number
*/
int main(){
  int n;
  int i, j;
  cin >> n;
  for(i = 2; i < n; i++){
    j = 2;
    while(i % j != 0) j++;
    if(j == i) cout << i << endl;
  }
}
