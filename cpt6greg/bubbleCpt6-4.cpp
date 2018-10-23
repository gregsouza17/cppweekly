#include <iostream>
#include <utility> //for std::swap

int main(){

  const int N = 5;
  int array[N] = {1,3,4,5,2};

  bool bSwaps = true;
  int indexNum = 0;

  while(bSwaps){

    int numSwaps(0);

    for(int i = 0; i<N-1; i++){
      if(array[i] < array[i+1]){
	std::swap(array[i] , array[i+1]);
	numSwaps++;
      }
    }

    indexNum+=1;


    //If we had no swaps we end, or if we did enough iterations
    if(numSwaps == 0 || indexNum == (N-1))
      bSwaps = false;
    
  
  }

  //Print array
  for(int i =0; i< N; i++)
    printf("%d ", array[i]);

  printf("\n");
}
