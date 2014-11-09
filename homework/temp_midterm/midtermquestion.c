// Helen Chac
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void count_letters(FILE *fp, int **count_letters);
void show_results(int *count_letters);
int main()
{
  int *count_letter;
  FILE *fp;
  
  fp = fopen("test.txt", "r");
  count_letters(fp, &count_letter);
  show_results(count_letter);

  return 0;
}//main()

void count_letters(FILE *fp, int **count_letters)
{
  char letter;
  int i, index;

  (*count_letters) = (int*)malloc(26 * sizeof(int));
  for (i = 0; i < 26; i++)
  {
    (*count_letters)[i] = 0;
  }
  while (fscanf(fp, "%c", &letter) != EOF)
  {
    if (isalpha(letter))
    {
      letter = tolower(letter);
      index = letter - 'a';
      (*count_letters)[index]++;
    }
  }

}

void show_results(int *count_letters)
{
  int i;

  for (i = 0; i < 26; i++)
    printf("%2c ", 'a' + i);
  printf("\n");
  for (i = 0; i < 26; i++)
    printf("%2d ", count_letters[i]); 
}
