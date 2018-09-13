#include <string.h>
#include <iostream>

using namespace std;
class cPerson{
  char name[40];
  int age;
public:
  void setname(char* ss){
    strcpy(name, ss);
  }
  void setage(int tage){
    age = (tage < 0) ? 0: tage;
  }
  char *getname(){
    return name;
  }
  int getage(){
    return age;
  }
  void disp();
};

void cPerson::disp(){
  cout << "Name: " << name << endl;
  cout << "Age: " << age << endl;
}
int main(){

  cPerson man;
  int n;
  man.setname("Wang");
  man.setage(20);
  n = man.getage();
  man.disp();
  cout << man.getname() << man.getage() << n <<endl;
}
  
