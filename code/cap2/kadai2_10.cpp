#include <iostream>
using namespace std;
int main(){
  char ch;
  cin >> ch;
  if(((ch >= 'a' && ch<= 'z') || (ch >= 'A' && ch <= 'Z')))
    cout << "Char is an Alphabet" << endl;
  else if(ch >= '0' && ch <= '9')
    cout << "Char is an Number" <<endl;
  else
    cout << "Char is somthing special" <<endl;
}
