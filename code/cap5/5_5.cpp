#include <iostream>

using namespace std;

int(* rettwo(int a[][4]))[4]{
  return a;
}

int main(){
  int b[][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}};
  int (*p)[4], i, j;
  p = rettwo(b);
  for(i = 0; i < 2; i++){
    for(j = 0; j < 4; j++){
      cout << *(*(p + i) + j) << ' ';
    }
    cout << '\n';
  }
}
