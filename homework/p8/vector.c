// Helen Chac
//

#include <stdlib.h>
#include "main.h"
#include "vector.h"

void deallocate(Individual *individuals, Family *families, int individual_count, int family_count)
{
  int i, j;
  
  for(i = 0; i < individual_count; i++)
  {
    if (individuals[i].INDI != NULL)
      free(individuals[i].INDI);
    if (individuals[i].name != NULL)
      free(individuals[i].name);
    if (individuals[i].FAMS != NULL)
      free(individuals[i].FAMS);
    if (individuals[i].FAMC != NULL)
      free(individuals[i].FAMC);
  } // for i
  free(individuals);
  // free what's in the structs of individual

  for(i = 0; i < family_count; i++)
  {
    if (families[i].FAM != NULL)
      free(families[i].FAM);
    if (families[i].HUSB != NULL)
      free(families[i].HUSB);
    if (families[i].WIFE != NULL)
      free(families[i].WIFE);
    for (j = 0; j < families[i].chil_count; j++)
      free(families[i].CHILs[j]);
  } // for i
  free(families);
  // free what is in the structs of families

} // deallocate


void initialize(Individual **individuals, Family **families, int individual_count, int family_count)
{
  int i;

  (*individuals) = (Individual*)malloc(individual_count *sizeof(Individual));
  (*families) = (Family*)malloc(family_count*sizeof(Family));

  for (i = 0; i < individual_count; i++)
  {
    (*individuals)[i].INDI = NULL;
    (*individuals)[i].name = NULL;
    (*individuals)[i].FAMC = NULL;
    (*individuals)[i].FAMS = NULL;
  }//for i, set the elements in the arrays equal to null
  for (i = 0; i < family_count; i++)
  {
    (*families)[i].FAM = NULL;
    (*families)[i].HUSB = NULL;
    (*families)[i].WIFE = NULL;
    (*families)[i].chil_count = 0;
    (*families)[i].CHILs = NULL;
  } // for i , set fam, husb, wife, and chils to null
} // initialize()
