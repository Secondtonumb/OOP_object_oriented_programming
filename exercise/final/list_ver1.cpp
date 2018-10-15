#include <iostream>
#include <stdio.h>
#include <string.h>

#define NAME_LENGTH 20
#define GRADE_LENGTH 3

using namespace std;

typedef struct student{
  char name[NAME_LENGTH];
  int id;
  bool gender;
  int birth;
  int grade[GRADE_LENGTH];
}STU;

STU stu_default = {.name = "NULL", .id = 0, .gender = 1, .birth = 19711001, .grade ={}};

class cLink{
  friend class cList;
  cLink *next;
  STU stu; 
public:
  cLink(){
    strcpy(stu.name, "");
    stu.id = 0;
    stu.gender = 1;
    stu.birth = 19711001;
    int i;
    for(i = 0; i < GRADE_LENGTH; i++){
      stu.grade[i] = 0;
    }
  }
  cLink(STU x){
    strcpy(stu.name, x.name);
    stu.id = x.id;
    stu.gender = x.gender;
    stu.birth = x.birth;
    int i;
    for(i = 0; i < GRADE_LENGTH; i++){
      stu.grade[i] = x.grade[i];
    }
  }
  cLink * get_next(void){
    return(next);
  }
  void print(void){
    printf("STUDENT'S NAME: %s\n", stu.name);
    printf("STUDENT'S ID: %d\nGENDER: %d\nBIRTH: %d\n", stu.id, stu.gender, stu.birth);
    int i;
    for(i = 0; i < GRADE_LENGTH; i++){
      printf("GRADE %d: %d\n", i, stu.grade[i]);
    }
  }
};

void data_input(STU &x){
  int i;
  cin >> x.name;
  cin >> x.id;
  cin >> x.gender;
  if(((x.gender == 0)||(x.gender == 1)) == 0) exit(1);
  cin >> x.birth;
  if(x.birth <= 19000101 || x.birth >= 20500101) exit(1);
  for(i = 0; i < GRADE_LENGTH; i++){
    cin >> x.grade[i];
    if(x.grade[i] < 0 || x.grade[i] > 100) exit(1);
  }
}

int main(){
  STU temp;
  STU &y = temp;
  data_input(y);
  cLink a;
  a.print();
  a = temp;
  a.print();
  // ls.Append(cLink("Wang"));
  // ls.Insert(cLink("Zhang"));
  // ls.Append(cLink("Gong"));
  // ls.Append(cLink("Yang"));
  // ls.Print();
  return 0;
}
