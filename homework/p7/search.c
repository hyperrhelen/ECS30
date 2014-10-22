//Helen Chac
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "search.h"
void find_children(int individual, int family, char **indiIDs, char **names, char **spousesIDs, char **childIDs)
{

  char line[200], *temp, *index;
  int id_index = 0, name_index = 0, ID = 0;
  do
  {
    printf("Please enter a name (Done = exit): ");
    fgets(line, 200, stdin);
    name_index = find_name(line, names, individual);
    if (strstr(line, "Done"))// if the user inputs Done, stop.
      return;
    else
    {
      if (name_index == -1) // if name index is not valid
        printf("%s not found.\n", line);
      else //if the name index is valid
      { 
        id_index = find_IDs(spousesIDs, family, index);
        if (id_index == -1) // if index of the id is not valid
          printf("%s never married.\n", line);
        else
        {
	  temp = strtok(childIDs[id_index], " I\n");
	  if (temp == NULL)
	    printf("%s has no children.\n", line);

          while(temp != NULL)
          {
            ID = atoi(temp);
	    printf("%s\n", names[ID - 1]);
	    temp = strtok(NULL, " I\n");
          } // while temp is not NULL print the name
        }// if the index of the id is not -1
      }
    }
  }while(strcmp(line, "Done")); // range checking
 
}//find_children()


int find_name(char line[100], char **names, int indi_counts)
{
  int i = 0, j = 0, k = 0, matches;
  char name2[80], *ptr, *name_ptrs[5];
  
  line[strlen(line) - 1] = '\0';
  ptr = strtok(name2, line);

  while (ptr != NULL)
  {
    name_ptrs[i] = (char*)malloc(sizeof(char)*strlen(ptr));
    // malloc because it doesn't know how many spaces to leave for the name.
    // only declared 5 strings.
    strcpy(name_ptrs[i], ptr);
    ptr = strtok(NULL, " ,");
    i++;
  }//while ptr is not null or is less than 5

/*  for (k = 0; k < i; k++)
  {
    printf("%s", (name_ptrs)[k]);
    if (name_ptrs[k] == NULL)
      printf("HAHA\n");
    printf("%s ", name_ptrs[k]);
  }
*/

  for (j = 0; j < indi_counts; j++ )
  {
    matches = 0;
    for (k = 0; k < i ; k++)
    {
//      printf("k: %d\n", k);
      if (strstr(names[j], (name_ptrs)[k]) == NULL)
        break;
/*
      if (strstr(names[j], (name_ptrs)[k]) != NULL ) //if they match, 
      {
        printf("k again: %d\n", k);
        printf("Hello\n");
        matches++;  
      }
*/
//      if (name_ptrs[k] != '\0') // if the string is not a NULL or 0 character
//        count++;
    }//for(inner)
      if (matches == i) // if it matches return the counter index
        return j;
  }//for(outer)

  return -1; // if it is not found
}//find_name()


int find_IDs(char **spousesIDs, int family_count, char *index)
{
  int i;
  
  for (i = 0; i < family_count; i++) 
  // checks to see if the index is in the spousesIDs.
    if (strstr(spousesIDs[i], index))
      return i;      

  return -1;// change it to return the index of the ID.
}//find_IDs()

