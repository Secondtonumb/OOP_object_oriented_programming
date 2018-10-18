#include <iostream>
using namespace std;
class Stack{
  int size;
  int *ptr;
  int *top;
public:
  Stack(int n){
    ptr = top = new int[n];
    size = n;
  }
  int *get_top(){
    return top;
  }
  int *get_ptr(){
    return ptr;
  }
  void push(int x){
    if(top - ptr < size){
      *top++ = x;
    }
  }
  int pop(){
    if(top > ptr) return * --top;
    else return 0;
  }
  int operator !(){
    return top-ptr != 0;
  }
  operator int(){
    return size;
  }
  // int count(int *p){
  //   static int m = 0; // 静态变量 只编译一次
  //   if(p < top){
  //     if(*p++ == 0) m++;
  // 	count(p);
  //   }
  //   return m;
  // }
  int count(int m){
    if(m == 0) return 0;
    else return count(m - 1) + (ptr[m - 1] == 0);
  }
};

int main(){
  Stack s(10);
  int len;
  int *p = s.get_ptr();
  s.push(1);
  s.push(0);
  s.push(0);
  s.push(2);
  s.push(0);
  s.push(1);
  //   if(!s) cout << "Zero: " << s.count(p) << endl;
  cout << s.get_top() - s.get_ptr() << endl;
  if(!s) cout << "Zero: " << s.count(s.get_top() - s.get_ptr()) << endl;
  if(!s) cout << "Pop = " << s.pop() << endl;
  len = s;
  cout << "Len = " << len << endl;
}
