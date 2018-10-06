#include <iostream>
#include <algorithm>

using namespace std;

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
    int count(){
      int i;
      int cnt = 1;
      sort(a, a + 10);
      for(i = 1; i < 10; i ++){
	if(a[i - 1] != a[i]) cnt ++;
      }
      return cnt;
    }
  int find(Node* &dict, int cnt);
};

bool compare(Node a, Node b){
    return a.freq > b.freq;
}

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

int Array::find(Node &dict, int cnt){
    int i, j;
    for(j = 0; j < cnt; j ++){
      dict[j].freq = 0;
    }
    dict[0].value = a[0];
    j = 0;
    for(i = 1; i < 10; i++){
        if(a[i] != a[i - 1]) dict[j++].value = a[i];
    }
    
    i = 1;
    dict[0].freq = 1;
    for(j = 1; j < cnt; j++){
        while(a[i] == a[i - 1]){
            dict[j - 1].freq ++;
            i ++;
        }
        dict[j].freq++;
    }

    for(j = 0 ;j < cnt; j ++){
      cout << "what" <<  dict[j].value << dict[j].freq << endl;
    }
    
    sort(dict, dict + cnt, compare);
    
    int freq_num = 1;
    for(j = 1; j < cnt; j++){
        if(dict[j - 1].freq == dict[j].freq)
            freq_num ++;
    }
    cout << "freq_num " << freq_num << endl;
    return freq_num;
}

int main(){
    Array arr;
    int max_number;
    arr.disp();
    arr.input();
    arr.disp();
    cout << "Array's maximum value: " << arr.max(max_number) << endl;
    cout << "Maximum numbers: " << max_number << endl;
    int ele_n;
    ele_n = arr.count();
    Node Dict[ele_n];
    Node *p = &Dict[ele_n];
    
    cout << ele_n << endl;

    int freq_n, i;
    freq_n = arr.find(p, ele_n);
    cout << "Most frequent elements: " << endl;
    for(i = 0; i < freq_n; i++){
      cout << Dict[i].value << endl;
    }
}

