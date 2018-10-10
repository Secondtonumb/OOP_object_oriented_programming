#include <iostream>
#include <algorithm>

using namespace std;

// struct to make elements which appears most frequently sorting easily.
typedef struct node{
    int value;
    int freq;
}Node;

class Array{
  int a[10];
public:
  Array();
  void input();
  void disp();
  int max(int &n);
  // count different elements' number for function find()
  int count(){
      int i;
      int cnt = 1;
      sort(a, a + 10);
      for(i = 1; i < 10; i ++){
	if(a[i - 1] != a[i]) cnt ++;
      }
      return cnt;
    }
  int find(int cnt);
};

// neccessary for algorithm::sort()
bool compare(Node a, Node b){
    return a.freq > b.freq;
}

Array::Array(){
    int i;
    for(i = 0; i < 10; i++){
        a[i] = 0;
    }
}

void Array::input(){
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

/*
Input: 
  int cnt: different elements number.
Output:
  int freq_num: How much time that the most-frequently-appear elements appeared.
*/
int Array::find(int cnt){
    int i, j;
    Node dict[cnt];
    // clear up     
    for(j = 0; j < cnt; j ++){
      dict[j].freq = 0;
    }
    // regist unique values to dict
    dict[0].value = a[0];
    j = 1;
    for(i = 1; i < 10; i++){
        if(a[i] != a[i - 1]) dict[j++].value = a[i];
    }

    i = 1;
    j = 0;
    dict[0].freq = 1;

    // count different elements' frequency
    while(j < cnt){
        while(a[i] == a[i - 1]){
            dict[j].freq ++;
            i ++;
        }
        dict[++j].freq++; i++;
    }
    // sorted by frequency, big endian
    sort(dict, dict + cnt, compare);

    // get how many elements which comes most frequently
    int freq_num = 1;
    for(j = 1; j < cnt; j++){
        if(dict[j - 1].freq == dict[j].freq)
            freq_num ++;
	else break;
    }
    
    for(j = 0; j < freq_num; j++){
      cout << "Elements appear most frequently No. " << j << ":" << dict[j].value << endl;
    }
    return dict[0].freq;
}

int main(){
    Array arr;
    int max_number;
    cout << "disp()" << endl;
    arr.disp();
    cout << "input()" << endl;
    arr.input();
    arr.disp();
    cout << "max()" << endl;
    cout << "Array's maximum value: " << arr.max(max_number) << endl;
    cout << "Maximum numbers: " << max_number << endl;

    cout << "find()" << endl;
    int ele_n;
    int freq_n;
    ele_n = arr.count();
    freq_n = arr.find(ele_n);
    cout << "Frequency: " << freq_n << endl;
}

