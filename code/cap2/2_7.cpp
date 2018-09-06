#include <iostream>
int main(){
  int sum, i;
  char ch;
  sum = 0;
  for(i = 0; i < 10; i++){
    std::cin >> ch;
    if(ch <= 'a'||ch >= 'z')
      continue;
    sum++;
  }
  std::cout << sum;
}
