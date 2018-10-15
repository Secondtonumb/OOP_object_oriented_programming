#include <iostream>
#define uMax 30000

using namespace std;

class counter{
  unsigned int cnt;
public:
  counter(){cnt = 0;}
  counter operator++(){
    if(cnt < uMax) cnt ++;
    return *this;
  }
  counter operator++(int){
    counter x = *this;
    if(cnt < uMax) cnt ++;
    return x;
  }
  counter operator--(){
    if(cnt > 0) cnt --;
    return *this;
  }
  counter operator--(int){
    counter x = *this;
    if(cnt > 0) cnt --;
    return x;
  }
  int operator !(){
    return(cnt == 0);
  }
  int value(){
    return cnt;
  }
  // !!!!!
  operator unsigned int(){
    return cnt;
  }
};

int main(){
  counter cnt1, cnt2;
  int i;
  for(i = 0; i < 10 ; i ++){
    ++cnt1;
    ++cnt2;
  }
  cout << cnt1 << endl;
  cout << cnt2 << endl;
  for(i = 0; i < 5; i++){
    --cnt2;
  }
  cout << cnt1 << endl;
  cout << cnt2 << endl;
}

