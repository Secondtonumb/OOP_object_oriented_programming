#include <iostream>

class exception{
public:
  exception() {}
  char *getMessage(){
    return "Error Occurred!";
  }
};
void exthrow(){
  throw exception();
}
int main(){
  try{
    exthrow();
  }
  catch(exception e){
    std::cout << e.getMessage() << std::endl;
  }
}

  
