//Helen Chac
//

#include <stdio.h>
#include <stdlib.h>
#include "file.h"
FILE* count_records(const char *filename, int *ind_count, int *fam_count)
{
  FILE *file;
  char line[80];

  file = fopen(filename, "r");
  if (file == NULL)// if file cannot be read
  {
    printf("File cannot be read.\n");
    exit(1);
  }
  else // if file can be open
  {
    while(fgets(line, sizeof(line), file) != NULL)
    {
      if (line[0] == '0') // NULL means not found in the line.
      {
        if (strstr(line, "INDI") != NULL) // If it has INDI in the line
          (*ind_count)++; 
        if (strstr(line, "FAM") != NULL) // If it has FAM in the line
          (*fam_count)++;
      }
    }// while the line is not a null
    rewind(file); // rewind the file so that it can be read again.
    return file;
  } 
  return 0;

}//count-records()

void read_file(FILE *fp, char **indiIDs, char **names, char **spousesIDs, char **childIDs)
{
  int indiv_count = 0, fam_count = 0;
  char line[1000], *ptr_line;
  ptr_line = fgets(line, 1000, fp);
  while(ptr_line != NULL)
  {
    if(strstr(line, "INDI")) // if the line contains INDI
      ptr_line = read_indi(line, fp, indiIDs, names, &indiv_count);
    else // if the line contains FAM
      if(strstr(line, "FAM"))
        ptr_line = read_family(line, fp, spousesIDs, childIDs, &fam_count);
      else // if it doesn't contain INDI or FAM 
        ptr_line = read_other(line, fp);
  } // while the line is not the end of the file
}//read_file() 

char* read_indi(char *line, FILE *fp, char **indiIDs, char **names, int *indiv_count)
{
  char *ptr, *name, temp_name[150], *pointer, *point_end;

  strcpy(indiIDs[*indiv_count], get_ID(line));
  while(((ptr = fgets(line, 1000, fp)) != NULL) && (line[0] != '0'))
  {
    if ((name = strstr(line, "NAME")) != NULL)
    {
      strcpy(line, name+(5 * sizeof(char)));
      point_end = strrchr(line, '/');
      (*point_end) = '\0';
      
      pointer = strtok(line, "/");
      strcpy(temp_name, pointer); 
      while(pointer != NULL)
      {
        pointer = strtok(NULL, "/");
        if (pointer!= NULL) // point to the NULL character
          sprintf(temp_name, "%s%s", temp_name, pointer);
      } //while pointer is not null
      names[*indiv_count] = (char*)malloc(strlen(temp_name)*sizeof(char));
      strcpy(names[*indiv_count], temp_name);
    }// while the line contains the word NAME
  }//while()
  (*indiv_count)++;

  return ptr;
}//read_indi()

char* read_family(char *line, FILE *fp, char **spousesIDs, char **childIDs, int *fam_count )
{

  char *ptr, *husb_id, *wife_id, *chil_id;
 
  while((fgets(line, 1000, fp)) != NULL && (line[0] != '0'))
  {  
    if (strstr(line, "HUSB") != NULL)
    {
      husb_id = get_ID(line);
      strcpy(spousesIDs[*fam_count], husb_id);
    } // if the line contains HUSB
    if (strstr(line, "WIFE") != NULL)
    {
      wife_id = get_ID(line);
      sprintf(spousesIDs[*fam_count], "%s %s", spousesIDs[*fam_count], wife_id);
    } // if the line contains WIFE
    if (strstr(line, "CHIL") != NULL)    
    {
      chil_id = get_ID(line);
      if (childIDs[*fam_count] == NULL)
      {
        childIDs[*fam_count] = malloc(strlen(chil_id));
        strcpy(childIDs[*fam_count], chil_id);
      } // if the element is a NULL
      else
      {
        ptr = (char*)malloc(strlen(childIDs[*fam_count])+strlen(chil_id)+2);
        sprintf(ptr, "%s %s", childIDs[*fam_count], chil_id);
        free(childIDs[*fam_count]);
        childIDs[*fam_count] = malloc(strlen(childIDs[*fam_count])+strlen(ptr)+2);
        strcpy(childIDs[*fam_count], ptr);
      }// if the element is not a NULL
    }
  }
  (*fam_count)++;

  return line;
}//read_family()

char* read_other(char *line, FILE *fp)
{
  char *ptr;

  while(((ptr = fgets(line, 1000, fp)) != NULL) && (line[0] != '0'));
  //until end of file

  return ptr;
}//read_other()

char* get_ID(char *line)
{
  char *temp, ID[100];
  
  strcpy(ID, strchr(line, '@') + 1);
  temp = strrchr(ID, '@');
  (*temp) = '\0';
  
  return ID;
}//get_ID()
