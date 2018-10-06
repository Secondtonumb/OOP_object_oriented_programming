#include <iostream>
using namespace std;
#define R 3
#define C 3

/*Return max element of each line*/
int max(int *a){
  int i;
  int temp = a[0];
  for(i = 1; i < C; i ++){
    if(a[i] >= temp) temp = a[i];
  }
  return temp;
}

int main(int argc, char *argv[]){
  int (*mat)[C];
  static int i, j;
  mat = new int[R][C];

  /* Initialization */
  cout << "R = " << R << " C = " << C << endl;
  cout << "Input " << R * C << " Integers to initialize" << endl;
  for(i = 0; i < R; i++){
    for(j = 0; j < C; j++){
      cin >> *(*(mat + i) + j);
    }
  }
  
  /* Show element of matrix mat*/
  // cout << "Elements Display" << endl;
  // cout << endl;
  // for(i = 0; i < R; i++){
  //   for(j = 0; j < C; j++){
  //     cout << mat[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  
  cout << endl;
  /* Return Maximum */
  for(i = 0; i < R; i++){
    cout << "Max element of line " << i << ":" << max(mat[i]) << endl;
  }
  delete []mat;
}
