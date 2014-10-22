//Helen Chac

#include <stdio.h>

int main()
{
  double monetary_value;

  printf("Please enter a monetary value: ");
  scanf("%lf", &monetary_value);
  printf("%16.2lf\n", monetary_value);
  printf("%24.10lf\n", monetary_value);
  printf("%34.20lf\n", monetary_value);

  return 0;

} //main()
