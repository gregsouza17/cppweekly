#include <iostream>
#include "constants.h"

double calculateHeight(double time,double initialHeight);
void printHeight(double time, double height);
void calculatePrintHeight(double time, double initialHeight);


int main(void){
  //Asks for the initial height and compute the following height
  //at 5 differente times

  std::cout<<"Please insert the initial height in meters \n";
  double initialHeight;
  std::cin >> initialHeight;

  //Calculate at five times given by constats.h
  calculatePrintHeight(constants::t1, initialHeight);
  calculatePrintHeight(constants::t2, initialHeight);
  calculatePrintHeight(constants::t3, initialHeight);  
  calculatePrintHeight(constants::t4, initialHeight);  
  calculatePrintHeight(constants::t5, initialHeight);

  
}


double calculateHeight(double time,double initialHeight){
  //Givent time and initial height, calculates height after
  // falling for the amount of time
  
  double acceleration;
  acceleration = constants::my_gravity;


  return (initialHeight - 0.5*acceleration*time*time);
}

void printHeight(double time, double height){
  //Prints time and height iif height > 0, otherwise
  //tell that the ball has fallen

  
  if(height > 0)
	printf("at time %f the ball is at: %f\n", time, height);
  else
	printf("At time %f the ball has already fallen\n", time);
}

void calculatePrintHeight(double time, double initialHeight){

  printHeight(time, calculateHeight(time, initialHeight));
}
