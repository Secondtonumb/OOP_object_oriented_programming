#include <iostream>

class cAnimal{
protected:
  int height;
public:
  cAnimal(int h){height = h;}
  virtual void Disp(void){}
};

class cDog: public cAnimal{
public:
  cDog(int h): cAnimal(h){}
  void Disp(){
    printf("This is a Dog.\n");
    printf("Height = %d\n", height);
  }
};

class cCat: public cAnimal{
public:
  cCat(int h): cAnimal(h){}
  void Disp(){
    printf("This is a Cat.\n");
    printf("Height = %d\n", height);
  }
};

class cMonkey: public cAnimal{
public:
  cMonkey(int h): cAnimal(h){}
  void Disp(){
    printf("This is a Monkey.\n");
    printf("Height = %d\n", height);
  }
};

class cSeal: public cAnimal{
public:
  cSeal(int h): cAnimal(h){}
  void Disp(){
    printf("This is a Seal.\n");
    printf("Height = %d\n", height);
  }
};

void Name(cAnimal *para){
  para->Disp();
}

int main(){
  cDog Dog(80);
  cCat Cat(30);
  cMonkey Monkey(70);
  cSeal Seal(60);
  Name(&Dog);
  Name(&Cat);
  Name(&Monkey);
  Name(&Seal);
  return 0;
}

