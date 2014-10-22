// Author: Helen Chac
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef FILE_H
#define FILE_H

FILE* count_records(const char *filename, int *ind_count, int *fam_count);
void read_file(FILE *fp, char **indiIDs, char **names, char **spousesIDs, char **childIDs);
char* read_indi(char *line, FILE *fp, char **indiIDs, char **names, int *indiv_count);
char* read_family(char *line, FILE *fp, char **spousesIDs, char **childIDs, int *fam_count);
char* read_other(char *line, FILE *fp);
char* get_ID(char *line);
#endif
