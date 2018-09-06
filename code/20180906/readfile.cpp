#include <iostream>
#include <fstream>
int main(int argc, char *argv[]){
  char ch;
  if(argc != 2){
    std::cout << "Usage:PR<filename>\n";
    return 1;
  }
  std::ifstream in(argv[1]);
  if(in.fail()){
    std::cout << "Cannot open file\n";
    return 1;
  }
  while(! in.fail()){
    in >> ch;
    std::cout << ch; //读入一个字符
  }
  in.close();
  return 0;
}
   
