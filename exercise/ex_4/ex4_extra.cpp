#include <iostream>
#include <string.h>
#define MAXLENGTH 512
#define NUM 10
using namespace std;

class str{
  char m[MAXLENGTH];
public:
  str(){
      m[0] = '\0';
  }
  str(char *a){
    strcpy(m, a);
  }
  str(str &second){
    strcpy(m, second.m);
  }
  void input(){
    cout << "input a string" << endl;
    cin >> m;
  }
  // ?
  char min(int &n){    
    int i = 1;
    int temp = (int)m[0];
    while(m[i] != '\0'){
      if(temp >= (int)m[i]){
  	temp = (int)m[i];
      }
      i++;
    }
    i = 0;
    n = 0;
    while(m[i] != '\0'){
      if((int)m[i] == temp) n++;
      i++;
    }
    return char(temp);
  }
  void disp(){
    cout << m << endl;
  }
};

int main(){
  char temp[MAXLENGTH] = {"temp"};
  str a, b(temp);
  str c = b;
  a.disp();
  a.input();
  a.disp();
  b.disp();
  c.disp();
  int num = 0;
  char s;
  s = c.min(num);
  cout << s << num << endl;
}
