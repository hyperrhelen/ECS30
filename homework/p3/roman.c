// Helen Chac

#include <stdio.h>
void get_number(int *number);
void show_roman_thousands(int number);
void show_roman_hundreds(int number);
void show_roman_tens(int number);
void show_roman_ones(int number);

int main()
{
  int number;
  
  get_number(&number);
  printf("In Roman numerals that is ");
  show_roman_thousands(number/1000);	//print the thousands place in roman numerals
  number %= 1000;
  show_roman_hundreds(number/100);	// print the hundreds place in roman numerals
  number %= 100;
  show_roman_tens(number/10); 		// print the tens place in roman numeral
  number %= 10;
  show_roman_ones(number);		// print the ones place in roman numeral
  printf(".\n");
  
  return 0;
} //main ()

void get_number(int *number)
{
  printf("Please enter a number between 1 and 3999: ");
  scanf("%d", number);
} //get_number()

void show_roman_thousands(int number)
{
  switch (number)
  {
    case 3: printf("MMM"); break;
    case 2: printf("MM"); break;
    case 1: printf("M"); break;
    default: break;
  } //switch()
} //get_roman_thousands()

void show_roman_hundreds(int number)
{
  switch(number)
  {
    case 9: printf("CM"); break;
    case 8: printf("DCCC"); break;
    case 7: printf("DCC"); break;
    case 6: printf("DC"); break;
    case 5: printf("D"); break;
    case 4: printf("CD"); break;
    case 3: printf("CCC"); break;
    case 2: printf("CC"); break;
    case 1: printf("C"); break;
    default: break;
  } //switch()
} //get_roman_hundreds()

void show_roman_tens(int number)
{
  switch(number)
  {
    case 9: printf("XC"); break;
    case 8: printf("LXXX"); break;
    case 7: printf("LXX"); break;
    case 6: printf("LX"); break;
    case 5: printf("L"); break;
    case 4: printf("XL"); break;
    case 3: printf("XXX"); break;
    case 2: printf("XX"); break;
    case 1: printf("X"); break;
    default: break;
  } //switch()
} //get_roman_tens()

void show_roman_ones(int number)
{
  switch (number)
  {
    case 9: printf("IX"); break;
    case 8: printf("VIII"); break;
    case 7: printf("VII"); break;
    case 6: printf("VI"); break;
    case 5: printf("V"); break;
    case 4: printf("IV"); break;
    case 3: printf("III"); break;
    case 2: printf("II"); break;
    case 1: printf("I"); break;
    default: break;
  } //switch()
}//get_roman_ones()
