#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
  int a[][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
  int (*p)[3]; // 括号不能省
  int i, j;
  p = a;
  for(i = 0; i < 3; i++){
    for(j = 0; j < 3; j++){
      // cout << p[i][j] << endl;
      cout << *(*(a + i) + j) <<endl;
    }
  }
  
}
