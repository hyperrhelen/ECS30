// Helen Chac
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef SEARCH_H
#define SEARCH_H
void find_children(int individual, int family, char **indiIDs, char **names, char **spousesIDs, char **childIDs );

int find_name(char *line, char **names, int indi_counts);
int find_IDs(char **spousesIDs, int family_count, char *index);

#endif
