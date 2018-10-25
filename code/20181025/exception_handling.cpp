#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
  try{
    if(argc != 2){
      throw "Error: parameter error!\n";
    }
  }
  catch (const char *err){
    cout << err << endl;
    exit(1);
  }
  return 0;
}
