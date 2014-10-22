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
  int individual_count, family_count;
  Individual *individuals;
  Family *families;

  FILE *fp;
  
  if(argc != 2)
  {
    printf("Usage: family.out <ged_filname>\n");
    return 1;
  } // if the number of arguments is wrong
  
  fp = count_records(argv[1], &individual_count, &family_count);
  initialize(individual_count, family_count, &individuals, &families);
  read_file(fp, individuals, families);
  qsort(individuals, individual_count, sizeof(Individual), individual_cmp);
  qsort(families, family_count, sizeof(Family), family_cmp);
  run(individual_count, family_count, individuals, families);
  // run will get the user input and call the search functions
  deallocate(individual_count,family_count, individuals, families);
  return 0;
} // main()

void run(int individual_count, int family_count, Individual *individuals, Family *families)
{
  int user_input, name_index;
  char name[80];
  do
  {
    printf("\nMenu\n0. Done.\n");
    printf("1. Find children.\n");
    printf("2. Print family tree.\n");
    printf("Your choice: ");
    scanf("%d", &user_input);
    if (user_input == DONE)	 // if the user enters 0 : STOP.
      break;
    else
    {  
      printf("Please enter a name: ");
      scanf("\n");
      fgets(name, 80, stdin);
      name_index = find_name(name, individual_count, individuals);
      if(name_index >= 0)
      {
        if (user_input == FINDCHILDREN)
        {
          find_children(individual_count, family_count, individuals, families, individuals[name_index].INDI);
          continue;	// keep looping
        } // if the user enters 1
        if (user_input == PRINTTREE);
        {
          printTree(individual_count, family_count, individuals, families, individuals[name_index].INDI);
          continue;	//keep looping
        } // if the user enters 2
      }//if
    }//else
  }while(1);	//while true
}//run()
