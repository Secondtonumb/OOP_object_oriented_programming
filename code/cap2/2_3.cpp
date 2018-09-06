#include <stdio.h>
int main(){
  int i;
  double sum;
  sum = 1.0;
  i = 2;
  while(i <= 100){
    sum += 1.0 / (double)i;
    i += 2;
  }
  printf("sum = %f\n", sum);
}
