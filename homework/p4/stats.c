//Helen Chac 

#include <stdio.h>
#include <math.h>

void open_file();
void get_stats(FILE* fp);
void std_dev(FILE* fp, double mean, int num_of_int);

int main()
{
  open_file();

  return 0;
} //main()

void open_file()
{
  FILE* fp;

  fp = fopen("stats_data.txt", "r");
  if (fp == NULL)
    printf("stats_dat.txt is not readable.\n");
  else
    get_stats(fp);
} // open_file

void get_stats(FILE *fp)
{
  int column = 0, num, i, max, min, sum, total_sum = 0, count_lines = 0;
  double ovr_avg, average = 0;
  
  fscanf(fp, "%d", &column);
  while (fscanf(fp, "%d", &num) != EOF)
  {
    sum = min = max = num;
    for (i = 0; i < column - 1; i++)
    {
      fscanf(fp, "%d", &num); 
      sum += num; // running total of the sum in the line
      if (num > max) // if the number is greater than the current max then change the max to the num
        max = num;
      if (num < min) // if the number is less than the current min then change the min to the num
        min = num;	  
    } // for the numbers between 0 and the column -1 .
    average = (sum / (double) column);
    total_sum += sum;
    count_lines += 1;
    if (count_lines % 2 == 0) // every two lines print a new line
      printf("min: %d max: %d avg: %.2lf \n", min, max, average);
    else //don't print an enter 
      printf("min: %d max: %d avg: %.2lf ", min, max, average);
  }  // while the pointer is not at the end of the file
  ovr_avg = ( total_sum + column ) / (( (count_lines ) * (double) column) + 1);
  printf("Average: %.2lf ", ovr_avg);
  std_dev(fp, ovr_avg, ( count_lines * column +1 ));

} // get_stats()

void std_dev(FILE* fp, double mean, int num_of_int)
{
  int file;
  double stdev, num, sum = 0;

  rewind(fp);
  file = fscanf(fp, "%lf", &num);
  while (file != EOF)
  {
    sum += pow((num - mean), 2);
    file = fscanf(fp, "%lf", &num);
  } // while the file is not at the end of the file
  stdev = sqrt( sum / (num_of_int - 1));
  printf("Standard deviation: %.2lf\n", stdev);
} // std_dev()
