#include <iostream>

using namespace std;

int main(){
  int buffer[10], Max, i;
  for(i = 0; i < 10; i++){
    cin >> buffer[i];
  }
  Max = buffer[0];
  for(i = 1;  i < 10; i++){
    if(Max < buffer[i]) Max = buffer[i];
  }
  cout << "Max=" << Max << endl;
}
