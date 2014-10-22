// Helen Chac
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void get_colors(char band1[10], char band2[10], char band3[10]);
  // gets the colors of the three bands
int search(const char (*colors)[7], char band[10], int size);
  // searches through the constant character list to check if the user input is in the array
void print_resistance(int value1, int value2, int value3);
  // prints the resistance
int main()
{
  const char colors[10][7] = {"black", "brown", "red", "orange", "yellow",
  "green", "blue", "violet", "gray", "white"};
  char band1[10], band2[10], band3[10], yes_no;
  int color1, color2, color3;

  do
  { 
    get_colors(band1, band2, band3); // passed the address (pointer) 
    color1 = search(colors, band1, 10);
    color2 = search(colors, band2, 10);
    color3 = search(colors, band3, 10);
    if (color1 == -1 || color2 == -1 || color3 == -1) 
      // if the user input isINVALID
    {
      if (color1 == -1)
        // if the first band is invalid then print that it is invalid
        printf("Invalid color: %s\n", band1);
      else if (color2 == -1)
        // if the second band is invalid then print that it is invalid
        printf("Invalid color: %s\n", band2);
      else if (color3 == -1)
        // if the third band is invalid then print that it is invalid
        printf("Invalid color: %s\n", band3); 
    }
    else  // if the user input is not valid
      print_resistance(color1, color2, color3);
    printf("Do you want to decode another resistor?\n=> ");
    scanf("\n%c", &yes_no);
  }while(yes_no != 'n'); // while the user does not enter a 'n'

  return 0;

} //main()

void get_colors(char band1[10], char band2[10], char band3[10]) // pointer value
{
  printf("Enter the colors of the resistor's three bands, beginning with\n");
  printf("the band nearest the end.  ");
  printf("Type the colors in lower case letters\n");
  printf("only, NO CAPS.\nBand 1 => ");
  scanf("%s", band1);
  printf("Band 2 => ");
  scanf("%s", band2);
  printf("Band 3 => ");
  scanf("%s", band3);

} //get_colors()

int search(const char (*colors)[7], char band[10], int size)
{
  int i;

  for(i = 0; i < size; i++)
    // for every color in the array check if the user input is in it
    if (strcmp(colors[i], band) == 0)
      // if the user input is found in the array then return the position
      return i;
 
  return -1;
}//search()

void print_resistance(int value1, int value2, int value3)
{
  long long int resis_value;

  resis_value = (value1 * 10 + value2) * pow(10, value3);
  printf("Resistance value:  %lld kilo-ohms\n", resis_value/1000);

}//get_resistance()



