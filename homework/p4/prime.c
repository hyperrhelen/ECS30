// Helen Chac and Terence Tang
//

#include <stdio.h>
#include <math.h>

void run_prime(int num1, int num2);
int is_prime(int number);
int main()
{
  int input1, input2, error;
  
  do
  {
    printf("Please enter two integers greater than one, and in ascending order: ");
    scanf("%d %d", &input1, &input2);
	
    if (input1 <= 1 || input2 <= 1)
    {
      error = 1;
      printf("The numbers must both be greater than one.\n");
    } // if any of the input is 1 or less - print error and continue while loop
    else if (input1 > input2)
    {
      error = 1;
      printf("The numbers must be in ascending order.\n");
    } // if the first input is more than the second input - then print error and continue while loop
    else if (input1 < input2 && input1 > 1 && input2 > 1)
      {
        run_prime(input1, input2);  
        break;
      } // if the input is correct then call is_prime()
    if (input1 <= 1 || input2 <= 1 || input1 > input2 ) 
      // after you print the error, print please try again. 
      printf("Please try again.\n\n");
  } while( error ); // while there is an error, continue looping
  
  return 0;
}//main()

void run_prime(int num1, int num2)
{
  int n, prime_number;
  
  for (n = num1; n <= num2; n++)
  {
    prime_number = is_prime(n);
    if (prime_number != 0) 
    // if the return of the value in is_prime is not 0, print the number.
      printf("%d ", prime_number);
  } // iterate for every number between num1 and num2
  printf("\n");
} // run_prime()

int is_prime(int number)
{
  int i, prime, count, not_prime;
  
  i = 2;
  count = 0;
  not_prime = 0;
  while(i <= sqrt(number))
  {
    prime = number % i;
    if (prime != 0) // if prime has a remainder, that means it's a prime.
      count += 1;
    if (prime == 0) // if prime does not have a remainder, that means it's not prime. 
      not_prime += 1;
    i++;
  } // while i is less than the square root of the number.
  if (not_prime == 0 && count != 0)
    // if not_prime is 0 & count is not 0, that means it's prime.
    return number;
  else if (number == 2 || number == 3)
    // if number is 2 or 3, it's prime.
    return number;
  else // if it doesn't mean any of the conditions, return 0
    return 0;
} // is_prime()
