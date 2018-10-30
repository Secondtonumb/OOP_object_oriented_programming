#include <iostream>
#include <string.h>

using namespace std;

class cMint{
  int idt;
public:
  cMint(){idt = 0;}
  cMint(int dt){idt = dt;}
  void set_dt(int dt){idt = dt;}
  int get_dt(){return idt;}
  void disp(){cout << "idt = " << idt << endl;}
};

class cMdb1{
  double ddt;
public:
  cMdb1(){ddt = 0;}
  cMdb1(double dt){ddt = dt;}
  void set_dt(double dt){ddt = dt;}
  int get_dt(){return ddt;}
  void disp(){cout << "ddt = " << ddt << endl;};
};

class cMids: public cMint, public cMdb1{
  char ss[256];
public:
  cMids(): cMint(), cMdb1(){
    strcpy(ss," ");
  }
  cMids(int d1, double d2, char *str);
  void set_dt(int dt, double d2, char *str);
  char *get_dt(){return ss;}
  void disp();
};

cMids::cMids(int d1, double d2, char *str): cMint(d1), cMdb1(d2){
  strcpy(ss, str);
}

void cMids::set_dt(int d1, double d2, char *str){
  cMint::set_dt(d1);
  cMdb1::set_dt(d2);
  strcpy(ss, str);
}

void cMids::disp(){
  cMint::disp();
  cMdb1::disp();
  cout << "ss = " << ss << endl;
}

int main(){
  char a[256] = "AAAAA";
  char b[256] = "BBBBB";
  char c[256] = "CCCCC";
  cMids dt(100, 2.22, a);
  dt.disp();
  dt.set_dt(300, 4.44, b);
  dt.disp();
  dt.cMint::set_dt(500);
  dt.cMdb1::set_dt(6.66);
  cout << "int: " << dt.cMint::get_dt() << endl;
  cout << "double: " << dt.cMdb1::get_dt() << endl;
  cout << "string: " << dt.cMids::get_dt() << endl;
}
  
