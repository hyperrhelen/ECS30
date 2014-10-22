// Helen Chac
//
#include <stdio.h>

void get_grades(const char *course, int *agrade, int *bgrade, int *cgrade, int *dgrade, int *fgrade);
void show_totals(int agrade, int bgrade, int cgrade, int dgrade, int fgrade);
int main()
{
  int grade_a = 0, grade_b = 0, grade_c = 0, grade_d = 0, grade_f = 0;

  get_grades("ECS 10", &grade_a, &grade_b, &grade_c, &grade_d, &grade_f);
  get_grades("ECS 20", &grade_a, &grade_b, &grade_c, &grade_d, &grade_f);
  get_grades("ECS 30", &grade_a, &grade_b, &grade_c, &grade_d, &grade_f);
  get_grades("ECS 40", &grade_a, &grade_b, &grade_c, &grade_d, &grade_f);
  show_totals(grade_a, grade_b, grade_c, grade_d, grade_f);

  return 0;  
}//main()

void get_grades(const char *course, int *agrade, int *bgrade, int *cgrade, int *dgrade, int *fgrade)
{
  int temp_a, temp_b, temp_c, temp_d, temp_f;

  printf("Please enter the grades for %s in order As Bs Cs Ds Fs: ", course);
  scanf("%d %d %d %d %d", &temp_a, &temp_b, &temp_c, &temp_d, &temp_f);
  *agrade = *agrade + temp_a;
  *bgrade = *bgrade + temp_b;
  *cgrade = *cgrade + temp_c;
  *dgrade = *dgrade + temp_d;
  *fgrade = *fgrade + temp_f;
}//get_grades()

void show_totals (int agrade, int bgrade, int cgrade, int  dgrade, int fgrade)
{
  int total =(agrade + bgrade + cgrade + dgrade + fgrade);

  printf("The percentages were A: %d%%, B: %d%%, C: %d%%, D: %d%%, F: %d%%.\n", (agrade*100)/total, (bgrade*100)/total, (cgrade*100)/total, (dgrade*100)/total, (fgrade*100)/total);
}//show_totals()
