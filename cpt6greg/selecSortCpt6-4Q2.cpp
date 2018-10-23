#include <iostream>
#include <utility>
// For std::swap



int main(void){

  const int N = 5;
  int array[N] = {3,5,2,1,4};

  
  for(int i = 0; i < N-1 ; i++){ //outside loop
    int maxIndex=i;
    
    for(int j = i+1; j < N; j++){ //internal loop
      
      if(array[j] > array[maxIndex])
	maxIndex = j;
      
    } //end internal loop

    std::swap(array[i], array[maxIndex]);
    
  } //end external loop

  for(int i = 0; i<N; i++){
    std::cout << array[i];
  }
  printf("\n");
  
  return 0;
}




