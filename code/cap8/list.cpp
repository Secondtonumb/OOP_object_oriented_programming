#include <stdio.h>
#include <string.h>
class cLink{
  friend class cList;
  cLink *next;
  char item[20];
public:
  cLink(char x[] = ""){
    strcpy(item, x);
  }
  cLink * get_next(void){
    return(next);
  }
  void print(void){
    printf("%s\n", item);
  }
};

class cList{
protected:
  cLink *first;
  cLink *last;
public:
  cList(void){
    first = last = new cLink;
  }
  ~cList(){
    Clear();
    delete first;
  }
  cList &Insert(const cLink &);
  cList &Append(const cLink &);
  cList &Delete(void);
  cList &Remove(void);
  cList &Clear(void);
  void Print(void);
};

cList &cList::Insert(const cLink &x){
  cLink *ptr = first;
  first = new cLink;
  *first = x;
  first->next = ptr;
  return(*this);
}

cList &cList::Append(const cLink &x){
  cLink *ptr = last;
  *ptr = x; 
  last = new cLink;
  ptr->next = last;
  return(*this);
}

cList &cList::Delete(){
  if(first != last){
    cLink *ptr = first->next;
    delete first;
    first = ptr;
  }
  return(*this);
}

cList &cList::Remove(){
  if(first == last);
  else if(first->next == last){
    Delete();
  }
  else{
    cLink *now = first;
    cLink *pre;
    while(now->next != last){
      pre = now;
      now = now->next;
    }
    pre->next = last;
    delete now;
  }
  return(*this);
}

cList &cList::Clear(){
  cLink *ptr = first;
  while(ptr != last){
    cLink *next = ptr->next;
    delete ptr;
    ptr = next;
  }
  first = last;
  return(*this);
}

void cList::Print(){
  puts("= = = = List = = = = ");
  int no = 1;
  cLink *ptr = first;
  while(ptr != last){
    printf("%d:", no++);
    ptr->print();
    putchar('\n');
    ptr = ptr->next;
  }
}

int main(){
  cList ls;
  ls.Append(cLink("Wang"));
  ls.Insert(cLink("Zhang"));
  ls.Append(cLink("Gong"));
  ls.Append(cLink("Yang"));
  ls.Print();
  return 0;
}
