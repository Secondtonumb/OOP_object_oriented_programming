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
}stu_struct;

void data_input(stu_struct &x){
  int i;
  cout << "INPUT NAME" << endl;
  cin >> x.name;
  cout << "INPUT ID" << endl;
  cin >> x.id;
  cout << "INPUT GENDER" << endl;
  cin >> x.gender;
  while(((x.gender == 0)||(x.gender == 1)) != 1) {
    cout << "INPUT GENDER" << endl;
    cin >> x.gender;
    cout << x.gender << endl;
  }
  cout << "INPUT BIRTH" << endl;
  cin >> x.birth;
  while(x.birth < 19000000 || x.birth > 20190000){
    cin >> x.birth;
  }
  for(i = 0; i < GRADE_LENGTH; i++){
    cin >> x.grade[i];
    if(x.grade[i] < 0 || x.grade[i] > 100) exit(1);
  }
} 

class STU_NODE{
  friend class LIST;
  STU_NODE *next;
  stu_struct stu; 
public:
  STU_NODE();
  STU_NODE(stu_struct x);
  STU_NODE(const STU_NODE &another);
  STU_NODE * get_next(void){
    return(next);
  }
  void input();
  void print(void){
    printf("STUDENT'S NAME: %s\n", stu.name);
    printf("STUDENT'S ID: %d\nGENDER: %d\n", stu.id, stu.gender);
    printf("STUDENT'S BIRTH %d\n", stu.birth);
    int i;
    for(i = 0; i < GRADE_LENGTH; i++){
      printf("GRADE %d: %d\n", i, stu.grade[i]);
    }
  }
};
STU_NODE::STU_NODE(){
  strcpy(stu.name, "");
  stu.id = 0;
  stu.gender = -1;
  stu.birth= 19000101;
  int i;
  for(i = 0; i < GRADE_LENGTH; i++){
    stu.grade[i] = 0;
  }
}
STU_NODE::STU_NODE(stu_struct x){
  strcpy(stu.name, x.name);
  stu.id = x.id;
  stu.gender = x.gender;
  int i;
  stu.birth = x.birth;
  for(i = 0; i < GRADE_LENGTH; i++){
    stu.grade[i] = x.grade[i];
  }
}
STU_NODE::STU_NODE(const STU_NODE &another){
  strcpy(stu.name, another.stu.name);
  stu.id = another.stu.id;
  stu.gender = another.stu.gender;
  int i;
  stu.birth = another.stu.birth;
  for(i = 0; i < GRADE_LENGTH; i++){
    stu.grade[i] = another.stu.grade[i];
  }
}
void STU_NODE::input(){
  stu_struct basic_info;
  data_input(basic_info);
  *this = basic_info; 
}

class LIST{
  STU_NODE *first;
  STU_NODE *last;
public:
  LIST(){
    first = last = new STU_NODE;
  }
  ~LIST(){
    Clear();
    delete first;
  }
  LIST &Insert(const STU_NODE &);
  STU_NODE &Find(char *); //find by name
  STU_NODE &Find(int); // find by id
  LIST &Delete(char *);
  LIST &Delete(int);
  int Count(){
    int n = 1;
    STU_NODE *ptr = first;
    while(ptr->next != last){
      n++;
      ptr = ptr->next;
    }
    return n;
  }
  LIST &Clear();
  void Print();
};

LIST &LIST::Insert(const STU_NODE &x){
  STU_NODE *ptr = first;
  first = new STU_NODE;
  *first = x;
  first->next = ptr;
  return(*this);
}

STU_NODE &LIST::Find(char *s){
  STU_NODE *ptr = first;
  while(ptr != last){
    if(strcmp(ptr->stu.name, s) == 0){
      return(*ptr);
      break;
    }
    else
      ptr = ptr->next;
  }
  return *last;
}
STU_NODE &LIST::Find(int id_num){
  STU_NODE *ptr = first;
  while(ptr != last){
    if(id_num == ptr->stu.id){
      return(*ptr);
      break;
    }
    else
      ptr = ptr->next;
  }
  return *last;
}

LIST &LIST::Delete(char *s){
  STU_NODE *ptr = first;
  STU_NODE *pre;
  if(ptr->next == last){
    if(strcmp(ptr->stu.name, s) == 0){
      ptr = first->next;
      delete first;
      first = ptr;
    }
  }
  while(ptr->next != last){
    if(strcmp(ptr->next->stu.name, s) == 0){
      pre = ptr;
      ptr = ptr->next;
      pre->next = ptr->next;
      delete ptr;
    }
    else ptr = ptr->next;
  }
  return(*this);
}

LIST &LIST::Delete(int id_num){
  STU_NODE *ptr = first;
  STU_NODE *pre;
  if(ptr->next== last && id_num == ptr->stu.id ){
    first = last;
    delete ptr;
    return (*this);
  }
  else 
  ptr = first;
  while(ptr->next != last){
    if(id_num == ptr->next->stu.id){
      pre = ptr;
      ptr = ptr->next;
      pre->next = ptr->next;
      delete ptr;
    }
    else ptr = ptr->next;
  }
  return(*this);
}

LIST &LIST::Clear(){
  STU_NODE *ptr = first;
  while(ptr != last){
    STU_NODE *next = ptr->next;
    delete ptr;
    ptr = next;
  }
  first = last;
  return(*this);
}

void LIST::Print(){
  puts("==== Print List ====");
  STU_NODE *ptr = first;
  while(ptr != last){
    ptr->print();
    putchar('\n');
    ptr = ptr->next;
  }
}
int main(){
  STU_NODE a; // Default Constructor
  a.input();
  // STU_NODE b = a;// Transfrom Constructor of CLink
  // b.print();
  STU_NODE b;
  b.input();
  STU_NODE c;
  c.input();
  // b = c;
  // b.print();
  LIST ls;
  ls.Insert(a);
  ls.Print();
  ls.Insert(b);
  ls.Print();
  ls.Insert(c);
  ls.Print();

  ls.Find("geng").print();
  ls.Find(201487028).print();
  ls.Delete("geng").Print();

  cout << ls.Count() << endl;
  ls.Delete(201487028);
  ls.Print();
  return 0;
}
