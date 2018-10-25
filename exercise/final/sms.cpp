#include <iostream>
#include <stdio.h>
#include <string.h>

#define NAME_LENGTH 20
#define GRADE_LENGTH 3

using namespace std;

// Define student struct to manage data easily
typedef struct student{
  char name[NAME_LENGTH];
  int id;
  bool gender;
  int birth;
  int grade[GRADE_LENGTH];
  int grade_sum;
}stu_struct;

//Input data into structure
void data_input(stu_struct &x){
  int i;
  cout << "INPUT NAME" << endl;
  cin >> x.name;
  cout << "INPUT ID" << endl;
  cin >> x.id;
  cout << "INPUT GENDER(1: Male, 0: Female)" << endl;
  cin >> x.gender;
  cout << "INPUT BIRTH" << endl;
  cin >> x.birth;
  x.grade_sum = 0;
  for(i = 0; i < GRADE_LENGTH; i++){
    cout << "Input Grade "
	 << "(" << i + 1 << "/" << GRADE_LENGTH << ")";
    cin >> x.grade[i];
    x.grade_sum += x.grade[i];
  }
} 

// Student Node
class STU_NODE{
  friend class LIST;
  STU_NODE *next;
  stu_struct stu;
public:
  STU_NODE();
  STU_NODE(stu_struct x);
  STU_NODE(const STU_NODE &another);
  void input(void);
  void print(void);
};

// Default Constructor
STU_NODE::STU_NODE(){
  strcpy(stu.name, "Underfined");
  stu.id = 0;
  stu.gender = -1;
  stu.birth= 19000101;
  int i;
  for(i = 0; i < GRADE_LENGTH; i++){
    stu.grade[i] = -1;
  }
  stu.grade_sum = -1;
}

// Transform Constructor
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

// Copy Constructor
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

void STU_NODE::input(void){
  stu_struct basic_info;
  data_input(basic_info);
  *this = basic_info; 
}

void STU_NODE::print(void){
  if(strcmp(stu.name, "Underfined") != 0){
    printf("STUDENT'S NAME: %s\n", stu.name);
    printf("STUDENT'S ID: %d\nGENDER: %d\n", stu.id, stu.gender);
    printf("STUDENT'S BIRTH %d\n", stu.birth);
    int i;
    for(i = 0; i < GRADE_LENGTH; i++){
      printf("GRADE %d: %d\n", i, stu.grade[i]);
    }
    printf("GRADE_SUM: %d\n", stu.grade_sum);
  }
  else
    printf("Error(No object Found)\n");
}

// Class List 
class LIST{
  STU_NODE *first;
  STU_NODE *last;
public:
  LIST(){
    first = last = new STU_NODE;
  }// Default Constructor
  ~LIST(){
    Clear();
    delete first;
  }// Default Destructor
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
  int Print_highest_grade();
  int Print_lowest_grade();
  void Print();
  LIST &Clear();
};

// Insert a node from head
LIST &LIST::Insert(const STU_NODE &x){
  STU_NODE *ptr = first;
  first = new STU_NODE;
  *first = x;
  first->next = ptr;
  return(*this);
}

// Find A Node By attribute "name"
STU_NODE &LIST::Find(char *s){
  STU_NODE *ptr = first;
  while(ptr != last){
    if(strcmp(ptr->stu.name, s) == 0){
      return(*ptr);
    }
    else
      ptr = ptr->next;
  }
  cout << "\n==== COULD'T FIND ====\n" << endl;
  return *last;
}

// Find A Node by Attribute "id"
STU_NODE &LIST::Find(int id_num){
  STU_NODE *ptr = first;
  while(ptr != last){
    if(id_num == ptr->stu.id){
      return(*ptr);
    }
    else
      ptr = ptr->next;
  }
  cout << "\n==== COULD.T FIND ====\n" << endl;
  return *last;
}

// Delete A Node By attribute "name"
LIST &LIST::Delete(char s[]){
  STU_NODE *ptr;
  while(strcmp(first->stu.name, s) == 0){
    ptr = first;
    ptr = ptr->next;
    delete first;
    first = ptr;
  }
  if(first == last){
    return (*this);
  }
  STU_NODE *pre = first;
  while(pre->next != last){
    ptr = pre->next;
    if(strcmp(ptr->stu.name, s) == 0){
      pre->next = ptr->next;
      delete ptr;
    }
    pre = pre->next; 
  }
  return(*this);
}

// Delete A Node By attribute "int"
LIST &LIST::Delete(int id_num){
  STU_NODE *ptr;
  while(id_num == first->stu.id){
    ptr = first;
    ptr = ptr->next;
    delete first;
    first = ptr;
  }
  if(first == last){
    return (*this);
  }
  STU_NODE *pre = first;
  while(pre->next != last){
    ptr = pre->next;
    if(id_num == ptr->stu.id){
      pre->next = ptr->next;
      delete ptr;
    }

    pre = pre->next;
  }
  return(*this);
}

int LIST::Print_highest_grade(){
  STU_NODE *ptr = first;
  int temp = ptr->stu.grade_sum;
  if(first == last) {
    cout << "\n==== List is Empty ====\n" << endl;
    return 1;
  }
  while(ptr->next != last){
    if(temp < ptr->next->stu.grade_sum) temp = ptr->next->stu.grade_sum;
    ptr = ptr->next;
  }
  ptr = first;
  while(ptr != last){
    if(ptr->stu.grade_sum == temp) ptr->print();
    ptr = ptr->next;
  }
  return 1;
}

int LIST::Print_lowest_grade(){
  STU_NODE *ptr = first;
  int temp = ptr->stu.grade_sum;
  if(first == last) {
    cout << "\n==== List is Empty ====\n" << endl;
    return 1;
  }
  while(ptr->next != last){
    if(temp > ptr->next->stu.grade_sum) temp = ptr->next->stu.grade_sum;
    ptr = ptr->next;
  }
  ptr = first;
  while(ptr != last){
    if(ptr->stu.grade_sum == temp) ptr->print();
    ptr = ptr->next;
  }
  return 1;
}

void LIST::Print(){
  STU_NODE *ptr = first;
  if(ptr == last) cout << "\n===== List is Empty ! ====\n" << endl;
  else{
    puts("==== List Begin ====");
    while(ptr != last){
      ptr->print();
      putchar('\n');
      ptr = ptr->next;
    }
    puts("==== List End ====");
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
  cout << "++++ Welcome to Student Management System ++++ \n" << endl;
  LIST ls;
  char struction = '\0';
  while(1){
    cout << "\n++++ Select an Function ++++" << endl;
    cout << "Insert:I\t Print:P\t Find:F\n" 
	 << "Delete:D\t Highest:H\t Lowest:L " << endl;
    cout << "++++ Quit:Q ++++\n" << endl;
    cin >> struction;

    if(struction == 'I'){
      STU_NODE i;
      i.input();
      ls.Insert(i);
    }
    
    else if(struction == 'P'){
      ls.Print();
    }

    else if(struction == 'F'){
      char temp[2];
      temp[0] = '\0';
      while(1){
	if(strcmp(temp, "N") == 0){
	  char name[NAME_LENGTH];
	  cout << "Input a name" << endl;
	  cin >> name;
	  ls.Find(name).print();
	  break;
	}
	else if(strcmp(temp, "ID") == 0){
	  int id;
	  cout << "Input an ID" << endl;
	  cin >> id;
	  ls.Find(id).print();
	  break;
	}
	else{
	  cout << "Find by Name:N  Find by ID:ID" << endl;
	  cin >> temp;
	}
      }
    }
    
    else if(struction == 'D'){
      char temp[2];
      temp[0] = '\0';
      while(1){
	if(strcmp(temp, "N") == 0){
	  char name[NAME_LENGTH];
	  cout << "Input a name" << endl;
	  cin >> name;
	  ls.Delete(name).Print();
	  break;
	}
	else if(strcmp(temp, "ID") == 0){
	  int id;
	  cout << "Input an ID" << endl;
	  cin >> id;
	  ls.Delete(id).Print();
	  break;
	}
	else{
	  cout << "Delect by Name:N  Delect by ID:ID" << endl;
	  cin >> temp;
	}
      }
    }

    else if(struction == 'H'){
      ls.Print_highest_grade();
    }
    
    else if(struction == 'L'){
      ls.Print_lowest_grade();
    }

    else if(struction == 'Q'){
      cout << "Are you sure to exit? [Y/n]" << endl;
      char e;
      cin >> e;
      if(e == 'Y') exit(0);
      else struction = '\0';
    }
  }
}
