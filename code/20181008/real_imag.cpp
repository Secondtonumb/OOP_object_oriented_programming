#include <iostream>
using namespace std;

class Complex{
  double real;
  double imag;
public:
  // Complex(){
  //   real = 0;
  //   imag = 0;
  // }
  Complex(double a=0, double b=0){
    real = a;
    imag = b;
  }
  Complex operator+(const Complex &c);
  Complex operator-(const Complex &c);
  void disp();
};

Complex Complex::operator+(const Complex &c){
  return Complex(real + c.real,imag + c.imag);
}

Complex Complex::operator-(const Complex &c){
  return Complex(real - c.real, imag - c.imag);
}

void Complex::disp(){
  cout << real << "+" << imag << "i" << endl;
}

int main(){
  Complex a(3, 5), b(1, 1), c;
  c = a + b;
  c.disp();
  c = a - b;
  c.disp();
}
