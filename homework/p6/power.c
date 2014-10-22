// Helen Chac
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void get_grid(int (**power));
void display_grid(int (**power));
void where_off(int (**power));
int power_ok(int (**power));

int main()
{
  int **power = NULL, i;
  
  power = (int**)malloc( 3 * sizeof( int* ) ); // for the rows 
  for ( i = 0; i < 3; i++ ) // for every row, you want get 4 addresses
    power[i] = (int*)malloc(4 * sizeof (int) ); 
  get_grid(power);

  return 0;
}//main()

void get_grid(int (**power))
{
  FILE *fp;
  int i, j;
  char str[80];
//  int power[3][4];
  printf("Filename: ");
  scanf("%s", str);

  fp = fopen(str, "r");
  for (i = 0; i < 3; i++) 
    //for every row you want to go to every column
    for (j = 0; j < 4; j++) 
       //scan in the integer and store it in the array
       fscanf(fp, "%d", &power[i][j]);
  display_grid(power);
  return;
} // read_file()

void display_grid(int (**power))
{
  int i, j; // counters
  
  for (i = 0; i < 3; i++)// for every row
  { 
    if (i != 0) // print a new line except for the first one
      printf("\n");
    for (j = 0; j < 4; j++) // print out what is stored in every column
     printf("%d ", power[i][j]);
  }
  printf("\n\n");
  where_off(power);

}//display_grid()

void where_off(int (**power))
{
  int i, j;
  if (power_ok(power) == 1) // if there is power throughout the whole grid
    printf("Power is on throughout grid.\n");
  else if (power_ok(power) == 0) // if there is not power throughout the whole grid
  {
    printf("Power is off in sectors:\n");
    for ( i = 0; i < 3; i++) // for every row
      for( j = 0; j < 4; j++) // for every column
      {
        if(power[i][j] == 0) // print where there is no power in the grid
          printf("      (%d,%d)\n", i, j);
      }
  }
}//where_off()

int power_ok(int (**power))
{
  int i, j, is_power;
  
  for ( i = 0; i < 3; i++) // for every row
    for ( j = 0; j < 4; j++) // for every column
    {
      if ( power[i][j] == 1) // check if the power is on
        is_power ++; // if it is add it the list
      else // if not return 0
        return 0;
    }
  if (is_power == 12) 
  // if the total power is 12, that means there is power everywhere
    return 1;
  return 1;

}//power_ok()
