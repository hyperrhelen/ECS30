//Helen Chac
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "search.h"

int individual_cmp(const void *ptr, const void *ptr2)
{
  return strcmp(((Individual*)ptr)->INDI, ((Individual*)ptr2)->INDI);
}//individual_cmp

int family_cmp(const void *ptr, const void *ptr2 )
{
  return strcmp(((Family*)ptr)->FAM, ((Family*)ptr2)->FAM);
}//family_cmp()

void find_children(Individual *individuals, Family *families, int individual_count, int family_count)
{
  Family key_family, *family_ptr;
  char name[80];
  int name_index;
  
  while(1)
  {
    printf("Please enter a name (Done = exit): ");
    fgets(name, 80, stdin);
    
    if(strcmp(name, "Done\n") == 0) // if user enters Done
      return;
    name_index = find_name(individuals, name, individual_count);
    if(name_index >= 0) // if the index is greater than 0
    {
      key_family.FAM = individuals[name_index].FAMS;
      if(key_family.FAM==NULL)// if there is nothing in the FAM part of key_family
        printf("%s never married.\n", name);
      else
      {
        family_ptr = bsearch(&key_family, families, family_count, sizeof(Family), family_cmp);
        print_children(family_ptr, individuals, individual_count, name);
          
      } // else he married
    }  // if name found 
  } // while user doesn't enter Done
} // find_children()

void print_children(Family *families, Individual *individuals, int individual_count, char *name)
{
  int i;
  Individual key_individual, *individual_ptr; 

  if (families -> chil_count == 0)
  {
    printf("%s has no children.\n", name);;
    return;
  } // if does not have children.

  for (i = 0; i < families -> chil_count; i++)
  {
    key_individual.INDI = families -> CHILs[i];
    individual_ptr = bsearch(&key_individual, individuals, individual_count, 
      sizeof(Individual), individual_cmp);
    
    if (individual_ptr) // if individual_ptr contains something inside / true
      printf("%s\n", individual_ptr -> name); 
  }//for i less than chil_count inside of the specific family.

}//print_children()

int find_ID(const char* ID, char **IDs, int count)
{
  int i;
  
  for(i = 0; i < count; i++) // for i in count
    if(strstr(IDs[i], ID)) // if 2 id's are equal.
      return i;
  
  return -1;
} // find_ID
 

int find_name(Individual *individuals, char name[80], int individual_count)
{
  char  name2[80], *name_ptrs[5], *ptr;
  int count = 0, i, j;

  name[strlen(name) - 1] = '\0';
  strcpy(name2, name);
  
  for(ptr = strtok(name2, " ,\n"); ptr; ptr = strtok(NULL, " ,\n"))
    name_ptrs[count++] = ptr;
  // get rid of the spaces, commas and return spaces and keep looping until there are no spaces, returns or commas.
    
  for(i = 0; i < individual_count; i++) // for i less than the individual counts
  {
    for(j = 0; j < count; j++) // for j less than count
      if(strstr(individuals[i].name, name_ptrs[j]) == NULL)
        break;
      
    if(j == count)
      return i; // found the name
  } // for i
  
  printf("%s not found.\n", name);
  return -1;
} // find_name()
