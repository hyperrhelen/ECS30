//Helen Chac

#include <stdio.h>
#define PI 3.14159265

int main()
{
  double diameter;
  double radius;

  printf("Please enter a diameter: ");
  scanf("%lf", &diameter);
  radius = diameter/2.0;
  printf("The circumference of a circle with diameter %.3lf is %.2lf.\n", diameter, 2 * PI * radius);
  printf("The area of a circle with diameter %.2lf is %.3lf.\n", diameter, radius * radius * PI);
  printf("The surface area of a sphere with diameter %.5lf is %.4lf.\n", diameter, 4 * PI * radius * radius);
  printf("The volume of a sphere with diameter %.4lf is %.5lf.\n", diameter, ( 4 / 3.0 ) * PI * radius * radius * radius);

  return 0;

} //main()
