#include <iostream>
#include <string.h>

#define MAX 512
using namespace std;

class str{
  char *s;
public:
  str(){
    s = new char[MAX];
    s[0] = '\0';
  }
  void input();
  void disp(){
    cout << s << endl;
  }
  int operator==(str &second){
    return strcmp(s, second.s);
  }
  void exchange(){
    int i = 1;
    int temp1, temp2;
    temp1 = (int)s[0];
    temp2 = (int)s[0];
    while(s[i] != '\0'){
      if((int)s[i] >= temp1){
	temp1 = (int)s[i];
      }
      else if((int)s[i] <= temp2){
	temp2 = (int)s[i];
      }
      i++;
    }
    i = 0;
    while(s[i] != '\0'){
      if((int)s[i] == temp1){
	s[i] = char(temp2); 
      }
      else if((int)s[i] == temp2){
	s[i] = char(temp1);
      }
      i++;
    }
  }
};
void str::input(){
  cin >> s;
}

int main(){
  str a, b;
  a.disp();
  cout << "input str a" << endl;
  a.input();
  a.disp();
  cout << "input str b" << endl;
  b.input();
  b.disp();
  cout << "If a == b, result == 0, if not result != 0" << endl;
  cout << (a == b) << endl;
  cout << "Exchange" << endl;
  a.exchange();
  a.disp();
}
