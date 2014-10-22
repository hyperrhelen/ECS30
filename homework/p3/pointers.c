// Helen Chac

#include <stdio.h>

void operate(int *address1, int *address2, int *address3);
int* read_address(int one_two);
int check_address(int *ptr, int *num_ptr1, int *num_ptr2, int *num_ptr3);
int read_operand();
char read_operator();
void run_operation(int *ptr1, int *ptr2, int operand, char operator);

int main()
{
  int num1, num2, num3;
  
  setvbuf(stdout, NULL, _IONBF, 0);
  printf("The addresses are num: %u, num2: %u, num3: %u\n", (unsigned) &num1, (unsigned) &num2, (unsigned) &num3);
  operate(&num1, &num2, &num3);
  operate(&num1, &num2, &num3);
  operate(&num1, &num2, &num3);
  printf("Done\n");
  
  return 0;
} //main()

void operate(int *address1, int *address2, int *address3)
{
  int *ptr1, *ptr2, operand;
  char operator;
  ptr1 = read_address(1);
    // if the user inputs 2 addresses and they are both true call for operand and operator
  if (check_address(ptr1, address1, address2, address3) && (ptr2 = read_address(2)) && check_address(ptr2, address1, address2, address3))
  {
    operand = read_operand();
    operator = read_operator();
    run_operation(ptr1, ptr2, operand, operator);
  }
  return;
}//operate()

int* read_address(int one_two)
{
  int *ptr;
  
  printf("Please enter int address #%d: ", one_two);
  scanf("%u", (unsigned*) &ptr);
  return ptr;
}// read_address()

int check_address(int *ptr, int *num_ptr1, int *num_ptr2, int *num_ptr3)
{
    //if the address that the input matches one of the three addresses in main
  if ((int)ptr == (int)num_ptr1 || (int)ptr == (int)num_ptr2 || (int)ptr == (int)num_ptr3)
  {
    printf("That is a valid address.\n");
    return 1;
  }
  else // if the user inputs a number that is not printed in main
  {
    printf("That is an invalid address.\n");
    return 0;
  }
}// check_address()
int read_operand()
{
  int operand;
  
  printf("Please enter an integer: ");
  scanf("\n%d", &operand);
  
  return operand;
}// read_operand()

char read_operator()
{
  char operator;
  
  printf("Please enter an operator: ");
  scanf("\n%c", &operator);

  return operator;
}// read_operand()

void run_operation(int *ptr1, int *ptr2, int operand, char operator)
{
  switch (operator)
  { 
    case '+':
    {
      *ptr2= *ptr1 + operand;
      printf("First int: %d, second int: %d.\n", *ptr1, *ptr2);
      break;
    }// if the user inputs a '+' operator
    case '*':
    {
      *ptr2= *ptr1 * operand;
      printf("First int: %d, second int: %d.\n", *ptr1, *ptr2);
      break;
    }// if the user inputs a '*' operator
    case '=':
    {
      *ptr2= *ptr1 = operand;
      printf("First int: %d, second int: %d.\n", *ptr1, *ptr2);
      break;
    }// if the user inputs a '=' operator

    case '%':
    {
      *ptr2= operand & *ptr1;
      printf("First int: %d, second int: %d.\n", *ptr1, *ptr2);
      break;
    }// if the user inputs a '&' operator
    default: printf("%c is an invalid operator. \n", operator); break;
  } //switch()
} //run_operation()
