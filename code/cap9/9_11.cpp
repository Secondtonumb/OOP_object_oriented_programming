#include <iostream>
using namespace std;

int main(){
  int month;
  cout << "Input month: ";
  cin >> month;
  try{
    if(month < 1) throw "Error: Month is less than 1";
    if(month > 12) throw "Error: Month is bigger than 12";
  }
  catch(const char *errstr){
    cout <<errstr << endl;
    return 1;
  }
  cout << "End";
  return 0;
}
