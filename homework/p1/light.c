//Helen Chac

#include <stdio.h>
#define SPEED_OF_LIGHT 299792458

int main()
{
  unsigned int frequency;

  printf("Frequency of the CPU (Hz): ");
  scanf("%u", &frequency);
  printf("Electricity can travel %.0lf millimeters in one cycle of a CPU that has", (double) SPEED_OF_LIGHT / (double) frequency * 1000 );
  printf("\na frequency of %d Hz.\n", frequency);
  printf("Using only integers, that is %u millimeters.\n", (SPEED_OF_LIGHT)/(frequency/1000));

  return 0;

} //main()
