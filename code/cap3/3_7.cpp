#include <iostream>
#include <fstream>

using namespace std;

int main(){
  ifstream fin;
  ofstream fout;
  char ch;
  fin.open("input.txt");
  if(fin.fail()){
    cout << "INPUT File open ERROR!" << endl;
    return 1;
  }
  fout.open("output.txt");
  if(fout.fail()){
    cout << "OUTPUT File open ERROR" << endl;
    return 1;
  }

  while(fin.get(ch)){
    fout.put(ch);
    cout.put(ch);
  }
  fin.close();
  fout.close();
}
