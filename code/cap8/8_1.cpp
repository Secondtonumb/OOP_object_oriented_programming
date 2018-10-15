#include <iostream>
#define uMax 30000

using namespace std;

class counter{
  unsigned int cnt;
public:
  counter(){cnt = 0;}
  void increase(){
    if(cnt < uMax) cnt ++;
  }
  void decreade(){
    if(cnt > 0) cnt --;
  }
  int value(){
    return cnt;
  }
};

int main(){
  counter cnt1, cnt2;
  int i;
  for(i = 0; i < 10 ; i ++){
    cnt1.increase();
    cnt2.increase();
  }
  cout << cnt1.value() << endl;
  cout << cnt2.value() << endl;
  for(i = 0; i < 5; i++){
    cnt2.decreade();
  }
  cout << cnt1.value() << endl;
  cout << cnt2.value() << endl;
}

