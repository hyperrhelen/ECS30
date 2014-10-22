// Helen Chac

#include <stdio.h>
void get_velocity(int *velocity);
void show_description(int velocity);

int main()
{
  int velocity;
  
  get_velocity(&velocity);
  show_description(velocity);
  
  return 0;
}//main()

void get_velocity(int *velocity)
{
  printf("Please enter the wind velocity in knots: ");
  scanf("%d", velocity);
} // get_velocity()

void show_description(int velocity)
{
    // if velocity is less than 1, print
  if (velocity < 1)
    printf("That is calm.\n");
    // if velocity is between 1 and 3, print
  if(velocity >= 1 && velocity < 4)
    printf("That is light air.\n");
	// if velocity is between 4 and 27, print
  if (velocity >=4 && velocity < 28)
    printf("That is a breeze.\n");
	// if velocity is between 28 and 47, print
  if (velocity >= 28 && velocity < 48)
    printf("That is a gale.\n");
	// if velocity is between 48 and 62, print
  if (velocity >= 48 && velocity < 63)
    printf("That is a storm.\n");
	// if velocity is greater than 63, print
  if (velocity >= 63)
    printf("That is a hurricane.\n");
    
} // show_description()