#include <iostream>
#include <map>

using namespace std;

class Array{
  int a[10];
public:
  Array();
  void input();
  void disp();
  int max(int &n);
  int find(int &m);
};

Array::Array(){
  int i;
  for(i = 0; i < 10; i++){
    a[i] = 0;
  }
}

void Array:: input(){
  int i;
  for(i = 0; i < 10; i++){
    cin >> *(a + i);
  }
}

void Array::disp(){
  int i;
  for(i = 0; i < 10; i++){
    cout << a[i] << ' ';
  }
  cout << endl;
}

int Array::max(int &n){
  int max_value = a[0];
  int i;
  n = 0;
  for(i = 1; i < 10; i++){
    if(max_value <= a[i]) max_value = a[i];
  }
  for(i = 0; i < 10; i++){
    if(a[i] == max_value) n ++;
  }
  return max_value;
}

int Array::find(int &m){
  int freq_value = a[0];
  int i;
  m = 0;
  map<int, int> mp;
  for(i = 0; i < 10; i++){
    if(++mp[a[i]] >= mp[freq_value])
      freq_value = a[i];
  }
  
  for(i = 0; i < 10; i++){
    if(a[i] == freq_value)
      m ++;
  }  
  return freq_value;
}

int main(){
  Array arr;
  int max_number;
  int freq_number;
  arr.disp();
  arr.input();
  arr.disp();
  cout << "Array's maximum value: " << arr.max(max_number) << endl;
  cout << "Maximum numbers: " << max_number << endl;
  cout << "Array's most freq value: " << arr.find(freq_number) << endl;
  cout << "most freq numbers: " << freq_number << endl;
}
