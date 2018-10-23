#include <iostream>
#include <string>

std::string getName();

void sortArray(std::string *array, int N);

int main(){

 
  int N;

  std::cout << "How many names 'll u scream? \n";
  std::cin >> N;

  std::string *theNames = new std::string[N];

  for(int i=0; i < N; i++){
    theNames[i] = getName();
  }

  sortArray(theNames, N);

  for(int i=0; i<N; i++)
    std::cout << theNames[i] << std::endl;
  
  
}

std::string getName(){

  std::string theName;
  
  std::cout << "Scream your naaaameeee \n";
  std::cin >> theName;

  return theName;
}

void sortArray(std::string *array, int N){

  bool bSwaps = true;
  int indexNum = 0;

  while(bSwaps){

    int numSwaps(0);

    for(int i = 0; i<N-1; i++){
      if(array[i] > array[i+1]){
	std::swap(array[i] , array[i+1]);
	numSwaps++;
      }
    }

    indexNum+=1;


    //If we had no swaps we end, or if we did enough iterations
    if(numSwaps == 0 || indexNum == (N-1))
      bSwaps = false;  
  
  }


}

