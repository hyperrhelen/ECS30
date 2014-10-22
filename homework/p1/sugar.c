//Helen Chac

#include <stdio.h>
#define pound .453592
#define percent .001

int main()
{
  double sweetener, weightofmouse;
  int goalweight;

  printf("Amount of sweetener needed to kill the mouse (kg): ");
  scanf("%lf", &sweetener);
  printf("Weight of the mouse (kg): ");
  scanf("%lf", &weightofmouse);
  printf("Goal weight of the dieter (pounds): ");
  scanf("%d", &goalweight);
  printf("For a goal weight of %d pounds, you may drink %.1lf kg of soda.\n", goalweight, ((goalweight*pound*sweetener)/weightofmouse)/percent);

  return 0;

}//main()
