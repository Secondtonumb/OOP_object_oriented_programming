#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
  int x;
  int &y = x;
  y = 12;
  cout << x << endl;
  cout << y << endl;
  
}
