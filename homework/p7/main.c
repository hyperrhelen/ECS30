// Helen Chac
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"
#include "vector.h"
#include "search.h"

int main(int argc, char **argv)
{
  FILE *fp;
  int individual_count = 0 , family_count = 0;
  char **indiIDs, **names, **spousesIDs, **childIDs;
  if (argc != 2)
  {
    printf("Usage: %s <ged_file_name>", argv[0]);
    return 1;
  }
  fp = count_records(argv[1], &individual_count, &family_count);
  initialize(individual_count, family_count, &indiIDs, &names, &spousesIDs, &childIDs);
  //allocate

  read_file(fp, indiIDs, names, spousesIDs, childIDs);
//
  find_children(individual_count, family_count, indiIDs, names, spousesIDs, childIDs );
 
  deallocate(individual_count, family_count, indiIDs, names, spousesIDs, childIDs); // last function caled in main. 

  return 0;

}//main()


