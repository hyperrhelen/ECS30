// Helen Chac
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"
#include "file.h"
#include "vector.h"

FILE* count_records(const char *filename, int *individual_count, int *family_count)
{
  char line[1000];
  FILE *fp = fopen(filename, "r");
  
  if(fp == NULL)
  {
    printf("Unable to read %s.\n", filename);
    exit(1);
  }  // if unable to open file
  
  *individual_count = *family_count = 0;
  
  while(fgets(line, 1000, fp) != NULL)
  {
    if(strstr(line, "INDI") && line[0] == '0')
      (*individual_count)++;
    
    if(strstr(line, "FAM") && line[0] == '0')
      (*family_count)++;
  } // while more in file
  
  rewind(fp);
  return fp;
} // count_records()


void add_child(Family *families, char *line)
{
  int i;
  char **temp;

  if (families -> CHILs == NULL)
  {
    temp = (char**)malloc((families->chil_count)*sizeof(char*));
    temp[0] = (char*)malloc((strlen(line) + 1)*sizeof(char*));
    strcpy(temp[0], get_ID(line));
  }// if there isn't CHILs array of families
  else
  {
    temp = (char**)malloc((families ->chil_count+1)*sizeof(char*));
    for (i = 0; i < families->chil_count; i++)
    {
      temp[i] = (char*)malloc((strlen(line)+1)*sizeof(char));
      strcpy(temp[i], families->CHILs[i]);
    }// for i less than the children count

  temp[i] = (char*)malloc((strlen(line)+1)*sizeof(char));
  strcpy(temp[i], get_ID(line));
  } //otherwise
  families->CHILs = temp;
  (families->chil_count)++;
}//add_child()

char* read_other(char *line, FILE *fp)
{
  char *ptr;

  while((ptr = fgets(line, 1000, fp)) != NULL && line[0] != '0');
  // get rid of all the unnecessary lines
  return ptr;
} //read_other()

char* get_ID(char *line)
{
  char *ptr = strrchr(line, '@');
  char *temp;

  *ptr = '\0';
  ptr = strchr(line, '@');
  temp = (char*)malloc((strlen(ptr) +1)*sizeof(char));
  strcpy(temp, ptr + 1);

  return temp;
}//get_ID()

char* read_indi(Individual *individuals, int *individual_count, char *line, FILE *fp)
{
  char *ptr, name[80];

  individuals[*individual_count].INDI = get_ID(line);
  
  while((ptr = fgets(line, 1000, fp)) != NULL && line[0] != '0')
  {
    if((ptr = strstr(line, "NAME")) != NULL)
    {
      strtok(ptr, " /");
      name[0] = '\0';
      ptr = strtok(NULL, " /\n");

      if(ptr)
        strcpy(name, ptr);
   
      while((ptr = strtok(NULL, " /\n")) != NULL)
        sprintf(name, "%s %s", name, ptr);

      char *ind_name = (char*)malloc(strlen(name)+1);
      strcpy(ind_name, name);
      (individuals)[*individual_count].name = ind_name;
    } // if a NAME tagged line
    if((ptr = strstr(line, "FAMS"))!= NULL)
      individuals[*individual_count].FAMS = get_ID(line);
    if((ptr = strstr(line, "FAMC")) != NULL)
      individuals[*individual_count].FAMC = get_ID(line);
  } // while more in the record

  (*individual_count)++;
  return ptr;
}  // read_indi()


char* read_family(Family *families, int *family_count, char *line, FILE *fp)
{
  char *ptr, line2[1000];
  
  families[*family_count].FAM = get_ID(line);
  while((ptr = fgets(line, 1000, fp)) != NULL && line[0] != '0')
  {
    strcpy(line2, line);
    if (strstr(line2, "HUSB"))// line with HUSB 
      families[*family_count].HUSB = get_ID(line2);
    if (strstr(line, "WIFE")) // line with WIFE
      families[*family_count].WIFE = get_ID(line2);
    if(strstr(line, "CHIL")) // line with CHIL
      add_child(&families[*family_count], line2);
  }// while more in the file
  (*family_count)++;
  return ptr;
}  // read_family()


void read_file(Individual *individuals, Family *families, FILE *fp)
{
  char line[256], *ptr;
  int individual_count = 0, family_count = 0;
  
  ptr = fgets(line, 256, fp);
  
  while(ptr != NULL)
  {
    if(strstr(line, "INDI")) // reads if line has INDI
      ptr = read_indi(individuals, &individual_count, line, fp);
    else // reads if line has FAM
    {
      if(strstr(line, "FAM"))
        ptr = read_family(families, &family_count, line, fp);
      else
        ptr = read_other(line, fp); // reads in everything else
    }
  } // while more in the file
} // read_file()
