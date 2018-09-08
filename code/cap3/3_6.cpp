#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]){
  char ch;
  if(argc != 2){
    cout << "Usage: PR<Filename>" << endl;
    return 1;
  }

  ifstream in(argv[1]);
  
  if(in.fail()){
    cout << "Cannot open file" <<endl;
    return 1;
  }
  while(! in.fail()){
    in >> ch; //Read a Char
    cout << ch;
  }
  in.close();
  return 0;
}
