#include <iostream>

int digitSum(int N);

int main(void){

  std::cout << digitSum(19782);
    
  return 0;
}

int digitSum(int N){

  if(N/10 == 0)
    return N;
  else
    return (N/10) + digitSum(N%10);
  
}
