#include <iostream>
#include <string.h>

#define MAXLENGTH 512
#define NUM 10
using namespace std;

class str{
  char m[NUM][MAXLENGTH];
public:
  str(){
    int i;
    for(i = 0; i < NUM; i ++){
      *(m[i]) = '\0';
    }
  }
  // Default: copy 'a' for all string elements in m[][MAXLENGTH]
  // Transform Constructor
  str(char *a){
    int i;
    for(i = 0; i < NUM; i++){
      strcpy(m[i], a);
    }
  }
  // Copy Constructor
  str(str &second){
    int i;
    for(i = 0; i < NUM; i++){
      strcpy(m[i], second.m[i]);
    }
  }
  // Input string and assign it to m[n]
  void input(int n){
    cout << "input a string for element " << n << endl;
    cin >> m[n];
  }
  
  /*Input: 
      index: m's first dimension, which means [index]th string
      n: variable return how many time the smallest elements appeared
    --------
    Output:
      char(temp): the smallest element in this string
  */
  char min(int index, int &n){    
    int i = 1;
    int temp = (int)m[index][0];
    while(m[index][i] != '\0'){
      if(temp >= (int)m[index][i]){
  	temp = (int)m[index][i];
      }
      i++;
    }
    i = 0;
    n = 0;
    while(m[index][i] != '\0'){
      if((int)m[index][i] == temp) n++;
      i++;
    }
    return char(temp);
  }
  // Display
  void disp(int n){
    cout << m[n] << endl;
  }
  // Declaration of increase_sort
  void inc_sort();
};

// Using Bubble sort
void str::inc_sort(){
  int i, j;
  char temp[MAXLENGTH];
  strcpy(temp, m[0]);
  for(i = 0; i < NUM; i++){
    for(j = 0; j < NUM - 1 - i; j++){
      // if m[j] > m[j + 1]
      if(strcmp(m[j], m[j + 1]) > 0){ 
	// swao(m[j], m[j + 1])
	strcpy(temp, m[j]);
	strcpy(m[j], m[j + 1]);
	strcpy(m[j + 1], temp);
      }
    }
  }
}

int main(){
  int i;
  char temp[MAXLENGTH] = {"Default"};
  str a, b(temp);
  str c = b;
  int n;

  cout << "Test for Transfrom Constructor" << endl;
  cout << "Display Object b, whose elements should all be the same string (Default)" << endl;
  cout << "----------------------------------------------------------------------------" << endl;
  for(i = 0;  i < 10; i++){
    b.disp(i);
  }
  cout << "\nTest for Copy Constructor" << endl;
  cout << "Display Object c, whose elements should the same as Object b" << endl;
  cout << "----------------------------------------------------------------------------" << endl;
  for(i = 0; i < 10; i++){
    c.disp(i);
  }
  cout << "\nTest for Default Constructor" <<endl;
  cout << "Display Object a, where 10 blank lines will be display"<< endl;
  cout << "----------------------------------------------------------------------------" << endl;
  for(i = 0; i < NUM; i++){
    a.disp(i);
  }

  cout << "\nNow call function (input) to assign each string in Object a" << endl;
  cout << "----------------------------------------------------------------------------" << endl;
  for(i = 0; i < NUM; i++){
    a.input(i);
  }

  cout << "\nNow Display 10 strings in Object a" << endl;
  cout << "----------------------------------------------------------------------------" << endl;
  for(i = 0; i < NUM; i++){ 
    a.disp(i);
  }

  cout << "\nNow Return each String's smallest element (Sorted by ASCII) in Object a" << endl;
  cout << "And how many time it appeared in this string" << endl; 
  cout << "----------------------------------------------------------------------------" << endl;
  for(i = 0; i < NUM; i++){
    cout << "min: " << a.min(i, n) << " numbers " << n << endl;
  }
  cout << "\nNow Sorted all the strings in Object a, and sorted in increasing sequence" << endl;
  cout << "----------------------------------------------------------------------------" << endl;
  a.inc_sort();

  for(i = 0; i < NUM; i++){
    a.disp(i);
  }
}
