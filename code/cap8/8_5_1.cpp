#include <iostream>
#define MLEN 8
using namespace std;

class mat{
  int (*M)[MLEN];
  int n;
public:
  mat(int n);
  ~mat(){
    delete []M;
  }
  // mat operator -(mat &);
  // mat operator *(mat &);
  // int operator !();
  // void cinput();
  // int Minv();
  void disp();
};

mat::mat(int n){
  int i, j;
  this->n = n;
  M = new int[n][MLEN];
  for(i = 0; i < n; i++){
    for(j = 0; j < MLEN; j++){
      M[i][j] = 0;
    }
  }
}
 
void mat::disp(){
  int i, j;
  for(i = 0; i < n; i++){
    for(j = 0; j < MLEN; j++){
      cout <<  M[i][j] << " ";
    }
    cout << endl;
  }
}

int main(){
  mat M(10);
  M.disp();   
}
