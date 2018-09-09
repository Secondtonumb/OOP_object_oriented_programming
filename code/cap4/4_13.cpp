#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
  int i;
  i = 0;
  while(argc > 1){
    ++i;
    cout << argv[i] << endl;
    --argc;
  }
}
