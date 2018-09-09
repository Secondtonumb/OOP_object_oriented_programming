#include <iostream>

using namespace std;

int main(){
  static char text[] = {'h', 'e', 'l', 'l', 'o'};
  char buff[5];
  int i, flag;
  for(i = 0; i < 5; i++){
    cin >> buff[i];
  }
  flag = 0;
  for(i = 0; i < 5; i++){
    if(buff[i] != text[i]){
      flag = 1;
      break;
    }
  }
  if(flag)
    cout << "The string is not  Hello " << endl;
  else
    cout << "The string is  Hello " << endl;
}
