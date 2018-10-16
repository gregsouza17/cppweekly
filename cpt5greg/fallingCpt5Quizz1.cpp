#include <iostream>
#include "constantsCpt5.h"

double getInitialHeight();
int getTime();
double calculateHeight(double h, int t);

int main(void){
  //Given the time interval and initial height, calculates
  // the path of the ball
  
  int initialTime;
  initialTime = getTime();
  double initialHeight;
  initialHeight = getInitialHeight();

  for(int i = 0; i < initialTime+1; i++){
    int height;
    height = calculateHeight(initialHeight, i);

    std::cout << "At time " << i ;
    if(height <= 0){
      std::cout << " The Ball is at the Groud!\n";
      break;
    }
    else{
      std::cout << " the ball is at " << height << " meters\n";
    }
     
    
    
  }
 
 
  
  return 0;
}

double getInitialHeight(){
  //Gets the user to inesert a positive real height
  
  std::cout<< "Please Insert the initial height in Meters: \n";
  double height;
  std::cin >> height;
  while(std::cin.fail() || height <0){
      std::cout << "Try again:" << std::endl;
      std::cin.clear();
      std::cin.ignore(256, '\n');
      std::cin >> height;
  }
  return height;

}

int getTime(){
  //Gets the user to inser a integer valued time
  
    std::cout << "Please, insert the integer time interval for falling \n";
    int time(0);
    std::cin >> time;
    while(std::cin.fail() || time<0){
      std::cout << "Try again:" << std::endl;
      std::cin.clear();
      std::cin.ignore(256, '\n');
      std::cin >> time;
    }   

    return time;
}


double calculateHeight(double h, int t){

  return h - 0.5*t*t*myConstants::gravity;
  

}
