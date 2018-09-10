#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
  int (*p)[5];
  p = new int[4][5];
  int M, i, j;
  for(i = 0; i < 4; i++){
    for(j = 0; j < 5; j++){
      // cin >> p[i][j];
      cin >> *(*(p + i) + j);
    }
  }
  M = p[0][0];
  for(i = 0; i < 4; i++){
    for(j = 0; j < 5; j++){
      if(M < p[i][j]) M = p[i][j];
    }
  }
  cout << "Max = " << M << endl;
}
