#include <string.h>
#include <iostream>

using namespace std;
class cExam{
  int aInt;
public:
  cExam(); //void 也不要写
  void disp(){
    cout << "aInt = " << aInt << endl;
  }
};
cExam:: cExam(){
  aInt = 999;
}
int main(){
  cExam dt;
  dt.disp();
}
