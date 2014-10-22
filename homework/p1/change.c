// Helen Chac

#include <stdio.h>

int main()
{
  int change, numquarters, numdimes, numnickels, numpennies;

  printf("Please enter the amount of change (0-99): ");
  scanf("%d", &change);
  numquarters = change/25;
  change = change - (numquarters*25);
  numdimes = change/10;
  change = change - (numdimes*10);
  numnickels = change/5;
  change = change - (numnickels*5);
  numpennies = change;
  printf("That would be %d quarters, %d dimes, %d nickels, and %d pennies.\n", numquarters, numdimes, numnickels, numpennies);

  return 0;

} // main()
