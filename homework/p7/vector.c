// Helen Chac
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"

void initialize(int individual, int family, char ***indiIDs, char ***names, char ***spousesIDs, char ***childIDs )
{
  int i;

  (*indiIDs) = (char**)malloc(individual * sizeof(char*));
  (*names) = (char**)malloc(individual*sizeof(char*));

  for (i = 0; i < individual; i++)
  {
    (*indiIDs)[i] = (char*)malloc(ID_LENGTH * sizeof(char));
    (*names)[i] = NULL;
  }// dynamically allocate indiIDs and names

  (*spousesIDs) = (char**)malloc(family * sizeof(char*));
  (*childIDs) = (char**)malloc(family*sizeof(char*));

  for (i = 0; i < family; i++)
  {
    (*spousesIDs)[i] = (char*)malloc(SPOUSES*sizeof(char));
    (*spousesIDs)[i][0] = '\0';
    (*childIDs)[i] = NULL;
  } // dynamically allocate spousesIDs and childIDs


}//initialize() will dynamically allocate the 4 arrays

void deallocate(int individual, int family, char **indiIDs, char **names, char **spousesIDs, char **childIDs)
{  
  int i;

  for (i = 0; i < individual; i++)
  {
    free(indiIDs[i]);
    if (names[i]) // if there's something contained, you want to free it.
      free(names[i]);
  } // free indiIDs and names
  for (i = 0; i < family; i++)
  {
    free(spousesIDs[i]);
    if (childIDs[i]) // if there's something contained, you want to free it.
      free(childIDs[i]);
  } // free spousesIDs and childIDs 
}//deallocate()

