//Helen Chac

#include <stdio.h>

int main()
{
  char character1, character2;
  int num;

  printf("Please enter two characters and an integer: ");
  scanf("%c%c%d", &character1, &character2,& num);
  printf("c1 + c2 = %c (char), %d (int).", character1 + character2, character1 + character2);
  printf("\nc1 - c2 = %c (char), %d (int).", character1 - character2, character1 - character2);
  printf("\nc1 + num = %c (char), %d (int).\n", character1 + num, character1 + num);
  
  return 0;

} //main()
