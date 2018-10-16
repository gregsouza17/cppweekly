#include <iostream>
#include <random> //for std::mt19937
#include <ctime> // for std::time

int getRandomNumber();
int getGuess();
bool evaluateGuess(int value,int guess);
bool playAgain();
bool playOneGame();
void playTheGame();

int main(void){
  //Initialiize mersenne twister with time based seed

  playTheGame();
  
}

int getRandomNumber(){
  //Gets a random number between 1 and 100

  //Starts mersenne method with time related seed
  std::mt19937 mersenne(static_cast<unsigned int>
			(std::time(nullptr)));
  int min, max;
  min =1; max=100;

  std::uniform_int_distribution<> die(min,max);

  return die(mersenne);
}

 int getGuess(){
   //asks for a integer guess in the correct range until Given
   
  int guess;
  
  std::cout << "Insert a guess between 1 and 100 "<<std::endl;
  std::cin >> guess;
  while( std::cin.fail() || guess<1 || guess>100){
    std::cout<<"Try again " << std::endl;
    std::cin.clear();
    std::cin.ignore(256, '\n');
    std::cin >> guess;
  }
  
  return guess;
}

bool evaluateGuess(int value,int guess){
  //Given the correct value and a guess for hilo,
  //evaluates the guess as high or low, returns true if
  //the guess was corret, false otherwise.

  if(value == guess){
    std::cout << "You win, the correct guess was " << value <<
       " Indeed " << std::endl;
    return true;
  }
  else if(guess > value)
    std::cout << "Too High!" << std::endl;
  else
    std::cout << "Too Low!" << std::endl;

  return false;

}

bool playAgain(){

  std::cout << "Do you want to play another game? Type y/n \n";
  char s;
  std::cin >> s;
  
  while(std::cin.fail() || (s!='y' &&  s!='n')){
    std::cout << "Try Again, y/n" << std::endl;
    std::cin.clear();
    std::cin.ignore(256, '\n');
    std::cin >> s;
  }

  return (s=='y');
}

bool playOneGame(){
  //Plays one game of hilo, asks if the player
  //wants to play again, return true if so, return false
  //otherwise

  int value;
  value = getRandomNumber();

  int guess(0);

  bool guessValue;
  
  for(int i = 0; i< 7; i++){
    printf("--- Guess number %d --- \n", i);
    guess = getGuess();

    guessValue = evaluateGuess(value, guess);

    if(guessValue){
      return playAgain();
    }    
  }

  std::cout << "You've ran out of guesses ! You lose !"<< std::endl;

  return playAgain();
}

void playTheGame(){
  //Keeps the game going while the player wants it to.
  
  bool again(true);

  while(again){
    again = playOneGame();
  }

  std::cout << "Quitting \n";

}
