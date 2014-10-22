// Helen Chac
//
// readSalaries.c
//

#include <stdio.h>

typedef struct
{
  char occupation_title[31];
  int employment;
  double percent_of_total_employment;
  double median_hourly_wage;
  double mean_hourly_wage;
  double annual_mean_wage;
} SalaryInfo;
// can be treated as a global variable

int main()
{
  SalaryInfo salary;
  FILE *fp;
  int input_index, line_num = 0;
  fp = fopen("salaries.dat", "r");
  do
  {
    line_num = -1;
    // start indexing off at -1 because that is the line we dont want to read

    printf("Please enter an index (-1 = done): ");
    scanf("%d", &input_index);

    if (input_index == -1)
      break;//if the user inputs a -1, that means that they want to stop searching

    while(fread(&salary, sizeof(salary), 1, fp))
    {
      line_num++;

      if (input_index == line_num)
      {
        printf("%s: Employment: %d, Percent of employment %.2lf%%\n"
          "Median hourly wage: $%.2lf, Mean hourly wage: $%.2lf\n"
          "Mean annual wage: $%.0lf\n\n", salary.occupation_title,
           salary.employment, salary.percent_of_total_employment * 100,
           salary.median_hourly_wage, salary.mean_hourly_wage,
           salary.annual_mean_wage);
        fseek(fp, 0, 0);
        break;
      }//if we reach the wanted index

    }//while - searching through the file

  }while(line_num != -1);

  return 0;
} // main()
