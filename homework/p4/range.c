//Helen Chac and Terence Tang

#include <stdio.h>
#include <float.h>

void get_double();
double get_num(double n_min, double n_max);

int main() 
{  
  get_double();
  return 0;
}//main()

void get_double()
{
  double min, max, last_input;
  
  min = get_num( -DBL_MAX, DBL_MAX);
  max = get_num(min, DBL_MAX);
  last_input = get_num(min, max);
  printf("min: %.8g, max: %.4g, input: %.4g are all OK.\n", min, max, last_input); 

} // get_double()
  
  // Returns the first integer between n_min and n_max entered as data.
double get_num(double n_min, double n_max)
{
  double input;  // input: number entered by user
  int status;
  char skip_ch;  // character used for skipping balance of line
  int error;     // error flag for bad input
  
  do 
  { 
    error = 0; // No errors yet
    printf("Enter an integer in the range from %g to %g inclusive> ", n_min, n_max);
    status = scanf("%lf", &input);
    scanf("%c", &skip_ch);
    if(status != 1 || skip_ch != '\n') 
    {
      error = 1;
      if (skip_ch != '\n')
      {
        printf("Invalid character >>%c>>. ", skip_ch);
        printf("Skipping rest of line.\n");
      }// if input is not an enter
      else if (status != 1 )
      {
        printf("Invalid character >>%c>>. ", skip_ch);
        printf("Skipping rest of line.\n");
      } // if user input is not an integer
    do
    {
      scanf("%c", &skip_ch);
    }while(skip_ch != '\n'); // skips line.
    } // if input is not an integer
    
    else
    {
      if (input <= n_min)
      {
        error = 1;
        printf("Number %.8g is too small.\n", input);
      } // if the number isn't between the two ranges
      else if (input >= n_max)
      {
        error = 1;
        printf("Number %.8g is too high.\n", input);
      }//if the number isn't between the two ranges
    } // if the input is an enter.
  } while(error);
  return input;
} // get_num()
