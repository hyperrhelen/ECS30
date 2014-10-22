// Helen Chac 
//

#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "file.h"
#include "vector.h"
#include "search.h"

int main(int argc, char **argv)
{
  Individual *individuals;
  Family *families;
  int individual_count, family_count;
  FILE *fp;
  
  if(argc != 2)
  {
    printf("Usage: family.out <ged_filename>\n");
    return 1;
  } // if the number of arguments is wrong
  
  fp = count_records(argv[1], &individual_count, &family_count);
  initialize(&individuals, &families, individual_count, family_count);
  read_file(individuals, families, fp);
  qsort(individuals, 4, sizeof(Individual), individual_cmp);
  qsort(families, 4, sizeof(Family), family_cmp);
  find_children(individuals, families, individual_count, family_count);
  deallocate(individuals, families, individual_count, family_count);
  return 0;
} // main()

