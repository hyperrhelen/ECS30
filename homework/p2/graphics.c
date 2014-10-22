// Helen Chac

#include <stdio.h>
void rectangle();
void head();
void triangle();
void blank_lines();
void lines();

int main()
{
  head();
  triangle();
  blank_lines();
  lines();
  head();
  rectangle();
  blank_lines();
  lines();
  triangle();
  rectangle();
  rectangle();
  blank_lines();
  return 0;
}//main()

void rectangle()
{
  char vert_side = '|', hor_side = '-';
  printf("%c%c%c%c%c%c\n", vert_side, hor_side, hor_side, hor_side, hor_side, vert_side );
  printf("%c    %c\n", vert_side, vert_side);
  printf("%c%c%c%c%c%c\n", vert_side, hor_side, hor_side, hor_side, hor_side, vert_side );
}// rectangle()

void head()
{
  char eye = '0', chin = '_', mouth = '-', side = '|', head1 = '/', head2 = '\\';
  printf(" %c%c%c%c%c\n", head1, mouth, mouth, mouth, head2);
  printf("%c %c %c %c\n", side, eye, eye, side);
  printf(" %c%c%c%c%c\n", head2, chin, mouth, chin, head1);
}//head()

void triangle()
{
  char left = '/', right = '\\', bottom = '_';
  printf("  %c%c\n", left, right);
  printf(" %c  %c\n", left, right);
  printf("%c%c%c%c%c%c\n", left, bottom, bottom, bottom, bottom, right);
}//triangle()

void blank_lines()
{
  char left = '/', right = '\\';
  printf("  %c%c\n", left, right);
  printf(" %c  %c\n", left, right);
  printf("%c    %c\n", left, right);
}//blank_lines()

void lines()
{
  printf("\n\n");
}//lines()
