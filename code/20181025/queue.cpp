#include <iostream>

using namespace std;
template <class T>
class TQueue{
  int n;
  int ele;
  T *data;
public:
  TQueue(int n){
    ele = 0;
    data = new T[n];
    this->n = n;
  }
  TQueue &Enqueue(T a){
    int i;
    if(ele < n){
      for(i = ele; i > 0; i--){
	data[i] = data[i - 1];
      }
    }
    data[0] = a;
    ele = ele + 1;
    return *this;
  }
  TQueue &Dequeue(){
    data[ele - 1] = 0;
    ele = ele - 1;
    return *this;
  }
  int operator !(){
    if(ele == 0) return 1;
    else return 0;
  }
  
  T Queuemax(int &x){
    T temp = data[0];
    int i;
    x = 0;
    for(i = 1; i < n; i++){
      if(temp < data[i]) temp = data[i];
    }
    for(i = 0; i < n; i++){
      if(temp == data[i]) x++;
    }
    return temp;
  }
  int return_ele(TQueue a){
    return a.ele;
  }
  int return_ele(){
    return ele;
  }
  int Qlen(){
    return n;
  }
  void disp(){
    int i;
    for(i = 0; i < ele; i++){
      cout << data[i] << endl;
    }
    cout << endl;
  }
};

int main(){
  TQueue <double> dq(10);
  dq.disp();
  cout << !dq << endl;

  dq.Enqueue(1.0);
  dq.Enqueue(2.0);
  dq.Enqueue(3.0);
  dq.Enqueue(3.0);

  int num;
  dq.disp();
  cout << !dq << endl;
  cout << dq.Queuemax(num) << " " << num << endl;

  dq.Dequeue();
  dq.disp();
  cout << !dq << endl;
}
