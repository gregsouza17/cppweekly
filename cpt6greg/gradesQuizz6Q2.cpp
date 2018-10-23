#include <iostream>
#include <string>

struct student{
  //Stores Name and Grade of a student
  std::string name;
  int grade;

  //Initialization
  //  student(std::string aName, int theGrade) : name(aName), grade(theGrade)
  // {}

  //Defines operator for comparing frades
  bool operator>(const student otherStudent){
    return (grade > otherStudent.grade);
  } 
  
};

void sortArray(student *array, int N);

int main(void){

  struct student *studentArray;
  int N;

  std::cout << "How many students ill u insert me in bla bla \n";
  std::cin >> N;

  studentArray = new student[N];

  for(int i = 0; i<N; i++){
    std::cout << "Name : "<<std::endl;
    std::cin >> studentArray[i].name;

    std::cout << "Grade : " << std::endl;
    std::cin >> studentArray[i].grade;
    
  }

  sortArray(studentArray, N);

  for(int i=0; i <N; i++){
    std::cout << "The Student named " << studentArray[i].name <<
      " had the grade " << studentArray[i].grade << std::endl;
  }
  
  return 0;
}

void sortArray(student *array, int N){
  //Does bubble sort
  
  bool bSwaps = true;
  int indexNum = 0;

  while(bSwaps){

    int numSwaps(0);

    for(int i = 0; i<N-1; i++){
      if(array[i+1] > array[i]){
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
