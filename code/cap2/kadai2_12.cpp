#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int main(){
  int n, temp;
  cin >> n;
  temp = n;
  // Digits counting
  int cnt = 1;
  while(temp/10 != 0){
    cnt ++;
    // cout << temp/10 << endl;
    temp = temp/10;
  }
  cout << "Digit Number =" << cnt << endl;
  temp = n;

  // Print digits
  int *digit;
  digit = (int*)malloc(cnt * sizeof(int));
  int i;

  for(i = cnt; i > 0; i--){
    cout << "TEMP = " << temp << endl;
    digit[cnt - i] = int (temp / pow(10, i - 1));
    temp -= digit[cnt - i] *  pow(10, i - 1);
    
  }
  for(i = 0; i < cnt; i++){
    cout << digit[i] << endl;
  }
  // Make minimum and maximum
  sort(digit, digit + cnt);
  int max = 0, min = 0;
  for(i = 0; i < cnt; i ++){
    min += digit[i] * pow(10, cnt - i - 1);
    max += digit[cnt - i - 1] * pow(10, cnt -i - 1);
  }
  cout << "Min ==" << min << endl;
  cout << "Max ==" << max << endl;
}
