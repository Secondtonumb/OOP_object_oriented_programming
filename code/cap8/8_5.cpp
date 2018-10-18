#include <iostream>
#define MLEN 8
using namespace std;

class mat{
  int M[MLEN][MLEN];
public:
  mat();
  mat operator -(mat &);
  mat operator *(mat &);
  int operator !();
  void cinput();
  int Minv();
  void disp();
};

mat::mat(){
  int i, j;
  for(i = 0; i < MLEN; i++){
    for(j = 0; j < MLEN; j++){
      M[i][j] = 0;
    }
  }
}

mat mat::operator -(mat &x){
  int i, j;
  mat a;
  for(i = 0; i < MLEN; i++){
    for(j = 0; i < MLEN; j++){
      a.M[i][j] = M[i][j] - x.M[i][j];
    }
  }
  return a;
}
mat mat::operator *(mat &x){
  int i, j, k;
  mat a;
  for(i = 0; i < MLEN; i++){
    for(j = 0; i < MLEN; j++){
      for(k = 0; j < MLEN; k++){
	a.M[i][j] += M[i][k] * a.M[k][j];
      }
    }
  }
  return a;
}
void mat::cinput(){
  int i, j;
  cout << "Input " << MLEN << "x" << MLEN << "data:" << endl;
  for(i = 0; i < MLEN; i++){
    for(j = 0; j < MLEN; j++){
      cin >> M[j][i];
    }
  }
}
int mat::operator !(){
  int i;
  for(i = 0; i < MLEN; i++){
    if(M[i][i] != 0) return 0;
  }
  return 1;
}
int mat::Minv(){
  int i, Mi;
  Mi = M[0][0];
  for(i = 1; i < MLEN; i++){
    if(M[i][i] < Mi) Mi = M[i][i];
  }
  return Mi;
}
void mat::disp(){
  int i, j;
  for(i = 0; i < MLEN; i++){
    for(j = 0; j < MLEN; j++){
      cout <<  M[i][j] << " ";
    }
    cout << endl;
  }
}

int main(){
  mat M, N, P;
  M.cinput();
  N.cinput();
  P = M - N;
  P.disp();
  cout << "Min: " << P.Minv() << endl;
  P = M * N;
  P.disp();
  cout << "Min:" << P.Minv() << endl;
  if(!P) cout << "All elements are zeros" << endl;
  else cout << "Non-zero elements exist" << endl;
    
}
