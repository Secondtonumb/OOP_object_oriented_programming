#include <iostream>
#define MAX 1024
#define REG_NUM 9
#define CLASS_NUM 3
using namespace std;

typedef struct Student{
  char *name;
  int reg_num[REG_NUM];
  bool gender;
  char *birth;
  int grades[CLASS_NUM];
};

typedef struct node{
  Student s;
  Stddent *next;
}Node, List*;
