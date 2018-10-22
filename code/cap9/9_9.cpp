#include <iostream>
#include <list>

using namespace std;

#define N 3

int main(){
  list <double>Ls;
  double data;
  int i;
  cout << "Input " << N << "double data: ";
  for(i = 0; i < N; i++){
    cin >> data;
    Ls.push_front(data);
  }
  cout << "original data: \n";
  list <double>::iterator it = Ls.begin();
  int num = 1;
  while(it != Ls.end()){
    cout << num << ": ";
    cout << *it << '\n';
    num++;
    it++;
  }
  cout << "sorted data: \n";
  Ls.sort();
  it = Ls.begin();
  num = 1;
  while(it != Ls.end()){
    cout << num << ":";
    cout << *it << '\n';
    num ++;
    it ++;
  }
  cout << "Input data to delete: ";
  cin >> data;
  Ls.remove(data);
  it = Ls.begin();
  num = 1;
  cout << "remaining data: \n";
  while(it != Ls.end()){
    cout << num << ":";
    cout << *it << '\n';
    num ++;
    it ++;
  }
}
