#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

bool randomselected = false;
int num;
int Random(int lower, int upper){
    num = (rand() % (upper + 1 - lower) + lower * 2);
    return num;
}
void sig_handler(int signum){
  if (randomselected){
    printf("The Number Was %d",num);
      }
  exit(130);
}


int main() {

  signal(SIGINT,sig_handler);
  int low;
  int high;
  int i = 0;

  printf("Lowest Number: ");
  if(scanf("%d", &low) == 1){
    printf("Biggest Number: ");
    if(scanf("%d", &high) == 1){
        if (low > high){
            printf("w\n");
                exit(1);
                 }
    }
    else{
      printf("Type an integer");
      exit(1);
    }
  }
  else{
    printf("Type an integer");
    exit(1);
  }
  randomselected = true;
  srand(time(0));
  int random = Random(low,high);
  int Guess;
  while (1){
    printf("Guess:");
    if(scanf("%d", &Guess) == 1)
    {
      if(Guess == random){
        printf("Correct\nit was %d\n",random);
        break;
      }
      else if(Guess > random){
        printf("Your guess is too high\n");
      }
      else if(random > Guess){
        printf("Your guess is too low\n");
      }
      else{
        printf("please type an integer");
}
}
    else{
    printf("Type an integer");
    exit(1);
  }
}
}
