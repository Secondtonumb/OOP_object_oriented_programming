#include <string.h>
#include <iostream>

using namespace std;

class cVdata{
  int v;
  static int ct;
public:
  cVdata() {v = 0; ++ct;}
  void setdata(int dt) {v = dt;}
  int getdata() {return v;}
  static int count() {return ct;}
  ~cVdata() {--ct;}
};

int cVdata::ct = 0;

void subprg(){
  cVdata dt3;
  cout << "cVdata object 's count= "  << dt3.count() <<endl;
}

int main(){
  cVdata dt1;
  cout << "cVdata object 's count= "  <<dt1.count() <<endl;
  cVdata *dt2 = new cVdata;
  cout << "cVdata object 's count= "  <<dt1.count() <<endl;
  cout << "cVdata object 's count= "  <<dt2->count() <<endl;
  cout << "cVdata object 's count= "  <<cVdata::count() <<endl;
  subprg(); //?
  delete dt2;
  cout << "cVdata object 's count= "  <<dt1.count() <<endl;
}
