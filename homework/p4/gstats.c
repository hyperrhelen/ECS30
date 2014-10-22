// Helen Chac
//

#include <stdio.h>
#include <math.h>

void open_file();
void get_stats(FILE* fp);
void std_dev(double mean, int num_of_int);

int main()
{
  open_file();
  return 0;
} //main()

void open_file()
{
  FILE* fp;
  fp = fopen("stats_data.txt", "r");
  get_stats(fp);
} // open_file

void get_stats(FILE *fp)
{
  int column = 0, num, i, max, min, sum = 0, total_sum = 0, count_lines = 0;
  double ovr_avg, average = 0;
  while (fscanf(fp, "%d", &num) != EOF)
  {
    for (i = 0; i < column; i++)
	{
	  fscanf(fp, "%d", &num);
	  sum += num; // running total of the sum in the line
	  if (i == 0)
	    max = min = num;
	  else
	  {
	    if (num > max)
		  max = num;
		if (num < min)
		  min = num;
	  }
	}
	average = (sum / column);
	total_sum += sum;
	count_lines++;
	printf("min: %d max: %d avg: %lf.\n", min, max, average);
  } // while the pointer is not at the end of the file
  ovr_avg = ( total_sum ) / ( count_lines * column);
  printf("\nAverage: %lf . ", ovr_avg);
  fclose(fp);
  std_dev(ovr_avg, ( count_lines * column ));

} // get_stats()

void std_dev(double x, int num_of_int)
{
  FILE* fp;
  int column, i, sum, num;
  double power, stdev;
  fp = fopen("stats_data.txt", "r");
  fscanf(fp, "%d", &column);
  power = pow( (column - x) , 2);
  sum = power;
  while (fscanf(fp, "%d", &num) != EOF)
  {
    for (i = 0; i < column; i++)
	  fscanf(fp, "%d", &num);
	  sum += pow(num - x, 2);
  }
  stdev = sqrt( sum / (num_of_int));
  printf("Standard Deviation is %lf \n", stdev);
} // std_dev()
