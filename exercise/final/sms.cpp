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
  int grade_sum;
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
  x.grade_sum = 0;
  for(i = 0; i < GRADE_LENGTH; i++){
    cin >> x.grade[i];
    x.grade_sum += x.grade[i];
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
  void input();
  void print(void){
    printf("STUDENT'S NAME: %s\n", stu.name);
    printf("STUDENT'S ID: %d\nGENDER: %d\n", stu.id, stu.gender);
    printf("STUDENT'S BIRTH %d\n", stu.birth);
    int i;
    for(i = 0; i < GRADE_LENGTH; i++){
      printf("GRADE %d: %d\n", i, stu.grade[i]);
    }
    printf("GRADE_SUM: %d\n", stu.grade_sum);
  }
};

STU_NODE::STU_NODE(){
  strcpy(stu.name, "temp");
  stu.id = 0;
  stu.gender = 1;
  stu.birth= 19000101;
  int i;
  for(i = 0; i < GRADE_LENGTH; i++){
    stu.grade[i] = 0;
  }
  stu.grade_sum = 0;
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
  stu.grade_sum = x.grade_sum;
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
  stu.grade_sum = another.stu.grade_sum;
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
  void Print_highest_grade();
  void Print_lowest_grade();
  void Print();
  LIST &Clear();
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
    }
    else
      ptr = ptr->next;
  }
  cout << "COULD'T FIND" << endl;
  return *last;
}

STU_NODE &LIST::Find(int id_num){
  STU_NODE *ptr = first;
  while(ptr != last){
    if(id_num == ptr->stu.id){
      return(*ptr);
    }
    else
      ptr = ptr->next;
  }
  cout << "\nCOULD.T FIND\n" << endl;
  return *last;
}

LIST &LIST::Delete(char *s){
  STU_NODE *ptr = first;
  STU_NODE *pre = first;
  if(strcmp(ptr->stu.name, s) == 0){
    delete first;
    first = ptr->next;
    return (*this);
  }
  else 
  while(pre->next != last){
    ptr = pre->next;
    if(strcmp(ptr->stu.name, s) == 0){
      pre->next = ptr->next;
    }
    pre = pre->next;
  }
  return(*this);
}

LIST &LIST::Delete(int id_num){
  STU_NODE *ptr = first;
  STU_NODE *pre = first;
  if(id_num == ptr->stu.id){
    delete first;
    first = ptr->next;
    return (*this);
  }
  while(pre->next != last){
    ptr = pre->next;
    if(id_num == ptr->stu.id){
      pre->next = ptr->next;
    }
    pre = pre->next;
  }
  return(*this);
}

void LIST::Print_highest_grade(){
  STU_NODE *ptr = first;
  int temp = ptr->stu.grade_sum;
  while(ptr->next != last){
    if(temp < ptr->next->stu.grade_sum) temp = ptr->next->stu.grade_sum;
    ptr = ptr->next;
  }
  ptr = first;
  while(ptr->next != last){
    if(ptr->stu.grade_sum == temp) ptr->print();
    ptr = ptr->next;
  }
}

void LIST::Print_lowest_grade(){
  STU_NODE *ptr = first;
  int temp = ptr->stu.grade_sum;
  while(ptr->next != last){
    if(temp < ptr->next->stu.grade_sum) temp = ptr->next->stu.grade_sum;
    ptr = ptr->next;
  }
  ptr = first;
  while(ptr->next != last){
    if(ptr->stu.grade_sum == temp) ptr->print();
    ptr = ptr->next;
  }
}

void LIST::Print(){
  puts("==== Print List ====");
  STU_NODE *ptr = first;
  if(ptr == last) cout << "Empty" << endl;
  while(ptr != last){
    ptr->print();
    putchar('\n');
    ptr = ptr->next;
  }
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

int main(){
  STU_NODE a; // Default Constructor
  //a.input();
  STU_NODE b;
  //b.input();
  STU_NODE c, d;
  a.input();
  b.input();
  c.input();
  d.input();
  // b = c;
  // b.print();
  LIST ls;
  ls.Insert(a);
  ls.Insert(b);
  ls.Insert(c);
  ls.Insert(d);
  ls.Print();

  // ls.Find("geng").print();
  // ls.Find(12).print();
  // ls.Delete("liu").Print();
  // ls.Delete(1).Print();

  // cout << ls.Count() << endl;
  
  ls.Print_highest_grade();
  ls.Print_lowest_grade();
  return 0;
}
