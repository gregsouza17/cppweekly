#include <iostream>


void my_swap(int &ref_a, int &ref_b);


int main(){

  int a(1), b(2);

  my_swap(a,b);

  std::cout << a << b << std::endl;
  
}

void my_swap(int &ref_a, int &ref_b){
  int temp;
  temp = ref_a;
  ref_a = ref_b;
  ref_b = temp;
}
