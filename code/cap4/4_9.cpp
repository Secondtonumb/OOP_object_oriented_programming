#include <iostream>

using namespace std;

void swap(int **p, int **q){
  int *t;
  t = *p;
  *p = *q;
  *q = t;
}

int main(){
  int a, b;
  a = 10;
  b = 20;
  int *p = &a, *q = &b;
  swap(&p, &q);
  cout << "*p = " << *p << ' ' << "*q = " << *q << '\n';
}
