#include <iostream>
int main(){
  char c;
  std::cin >> c;
  if((c >= 'a' && c <='z') || (c >='A' && c <= 'Z'))
    std::cout << "It is a letter\n";
  else
    std::cout << "It is not a letter\n";
  return 0;
}
