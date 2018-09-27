#include <iostream>

using namespace std;

class fraction{
  long numera;
  long denomi;
  long gcd(long a, long b);
public:
  fraction() {numera = 0; denomi = 1;}
  fraction(long a, long b = 1);
  void disp();
  fraction operator+(fraction &dt2);
  fraction operator+(long dt2);  
};

fraction::fraction(long a, long b){
  long wk;
  if(b <= 0) b = 1;
  wk = gcd(a, b);
  numera = a / wk;
  denomi = b / wk;  
}
fraction fraction::operator+(fraction &dt2){
  long mul1, mul2;
  mul1 = numera * dt2.denomi + dt2.numera * denomi;
  mul2 = denomi * dt2.denomi;
  return fraction(mul1, mul2);
}

fraction fraction::operator+(long dt2){
  return fraction(numera + denomi * dt2, denomi);
}

long fraction::gcd(long a, long b){
  long wk;
  while(b != 0){
    a = a % b;
    wk = a; a = b; b = wk;
  }
  return a;
}

void fraction::disp(){
  cout << numera << '/' << denomi << endl;
}

int main(){
  fraction a(2, 16), b(1, 6), c(5), d;
  cout << "init: " << endl;
  a.disp();
  b.disp();
  c.disp();
  d.disp();
  cout << "a + b 's result: " << endl;
  c = a + b;
  c.disp();
  cout << "a + 2 's result: " << endl;
  c = a + 2;
  c.disp();
}  

  

  
