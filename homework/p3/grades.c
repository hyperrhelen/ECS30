// Helen Chac

#include <stdio.h>
void get_test_grade(int *score);
void show_grade(int score);

int main()
{
  int test_score;
  
  get_test_grade(&test_score);
  show_grade(test_score);
  
  return 0;
} //main()

void get_test_grade(int *score)
{
  printf("Please enter a test score: ");
  scanf("%d", score);
} //get_test_grade()

void show_grade(int score)
{
  switch((score/10))
  {
    case 10:
    case 9:
    printf("Letter grade: A\n");
    break;
    case 8:
    printf("Letter grade: B\n");
    break;
    case 7:
    printf("Letter grade: C\n");
    break;
    case 6:
    printf("Letter grade: D\n");
    break;
    default:
    printf("Letter grade: F\n");
    break;
  } //switch()
} //show_grade()