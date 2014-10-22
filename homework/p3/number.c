// Helen Chac

#include <stdio.h>
void show_tens_place(int num);
void show_ones(int num);

int main()
{
  int num;

  printf("Please enter a number between 0 and 99: ");
  scanf("%d", &num);
  printf("In English, that is ");

    // if number is between 0-19, prints 1-19 in english
  if (num >= 0 && num <= 19)
	show_ones(num);
    // if number is a multiple of 10, print the english of it
  else if (num % 10 == 0)
  {
    show_tens_place(num);
    printf(".");
  }
	// if number is not a multiple of ten and not less than 19, print the english multiple of ten's place and then the single digit place
  else if (num % 10 != 0)
  {
    show_tens_place(num);
    printf("-");
    show_ones(num%10);
  }

  return 0;
}//main()

void show_tens_place(int num)
{
  switch(num/10)
  {
    case 9: printf("ninety"); break;
    case 8: printf("eighty"); break;
    case 7: printf("seventy"); break;
    case 6: printf("sixty"); break;
    case 5: printf("fifty"); break;
    case 4: printf("fourty"); break;
    case 3: printf("thirty"); break;
    case 2: printf("twenty"); break;
  } //switch()
} //show_tens_place()


void show_ones(int num)
{
  switch(num)
  {
    case 0: printf("zero.\n"); break;
    case 1: printf("one.\n"); break;
    case 2: printf("two.\n"); break;
    case 3: printf("three.\n"); break;
    case 4: printf("four.\n"); break;
    case 5: printf("five.\n"); break;
    case 6: printf("six.\n"); break;
    case 7: printf("seven.\n"); break;
    case 8: printf("eight.\n"); break;
    case 9: printf("nine.\n"); break;
    case 10: printf("ten.\n"); break;
    case 11: printf("eleven.\n"); break;
    case 12: printf("twelve.\n"); break;
    case 13: printf("thirteen.\n"); break;
    case 14: printf("fourteen.\n"); break;
    case 15: printf("fifteen.\n"); break;
    case 16: printf("sixteen.\n"); break;
    case 17: printf("seventeen.\n"); break;
    case 18: printf("eighteen.\n"); break;
    case 19: printf("nineteen.\n"); break;
  } // switch()
  
}//show_ones()
