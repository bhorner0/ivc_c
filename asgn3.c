#include <stdio.h>
#include <stdlib.h>

/*
K so the user is gunna give 1 employee at a time and make calculations
on the fly, meaning employee info is not stored and cannot be recalled.
Number of overtime employees, total overtime hours, and total overtime
pay are global variables that get printed on exit.
*/

struct bruh {
  char namef[50];
  char namel[50];
  float hours;
  float rate;
  float fedtax;
  float statetax;
  float othours;
  float otpay;
};

float totalot = 0;
float totalotp = 0;
int otno = 0;

int getman( struct bruh *man );
void calcman( struct bruh man );

void main () {
  struct bruh mydood;
  while ( getman(&mydood) == 0 ) {
    calcman(mydood);
  }
}

int getman( struct bruh *man ) {
  //get first name and test for exit
  printf( "Give First Name ('exit' to quit): " );
  
  char buff[50];
  scanf( "%s",buff );
  
  if ( strcmp(buff,"exit") == 0 ) {
    printf( "\npeace mah dood...\n\n" );
    printf( "# of OTers:\t%d\n",otno ); //print globals
    printf( "Total OT Hours:\t%f\n",totalot );
    printf( "Total OT Pay:\t$%.2f\n\n",totalotp );
    return 1;
  }
  
  strcpy( man->namef, buff );
  //get everything else
  printf( "Give Last Name: " );
  scanf( "%s",man->namel );

  printf( "Give Hours: " );
  scanf( "%f",&man->hours );

  printf( "Give Rate: " );
  scanf( "%f",&man->rate );

  printf( "Give Federal Tax: " );
  scanf( "%f",&man->fedtax );

  printf( "Give State Tax: " );
  scanf( "%f",&man->statetax );
  
  return 0;
}

void calcman(struct bruh man) {

  float gpay = (man.hours * man.rate);
  //overtime stuff
  if ( (man.hours - 40) > 0 ) {
    man.othours = (man.hours - 40);
    man.otpay = (man.hours - 40) * (man.rate * 1.5);
    gpay = ((man.hours-man.othours)*man.rate) + man.otpay;
    //update globals
    otno++;
    totalot = totalot + man.othours;
    totalotp = totalotp + man.otpay;
  }
  
  float frate = (man.fedtax / 100);
  float srate = (man.statetax / 100);
  printf("\nName:\t\t%s, %s\n",man.namel,man.namef);
  printf("Gross Pay:\t$%.2f\n",gpay);
  printf("Fed Tax Owed:\t$%.2f\n",(gpay * frate));
  printf("State Tax Owed:\t$%.2f\n",(gpay * srate));
  printf("Net Pay:\t$%.2f\n\n",(gpay - (gpay*frate) - (gpay*srate)) );
}

