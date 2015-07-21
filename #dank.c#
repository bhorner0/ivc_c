#include <stdio.h>
#include <stdlib.h>

int main() {

  int big, small = 0;
  int temp;

  //initialize

  printf("Giff integer pls: ");
  if (scanf("%d", &temp) != 1) {
    printf("Peace...\n");
    return(0);
  }
  big = temp;
  small = temp;

  //T H E L O O P

  while(1) {
    printf("Giff integer pls: ");
    if (scanf("%d",&temp) != 1){
      printf("Peace...\n");
      break;
    }
    else {
      if (temp > big) {
	big = temp;
	continue;
      }
      if (temp < small) {
	small = temp;
	continue;
      }
    }
  }

  printf("Biggest: %d, Smallest: %d\n",big,small);
  
}
