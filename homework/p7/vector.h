// Helen Chac
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ID_LENGTH 20
#define SPOUSES 40
#ifndef VECTOR_H
#define VECTOR_H
void initialize(int individual, int family, char ***indiIDs, char ***names, char ***spousesIDs, char ***childIDs);
void deallocate(int individual, int family, char **indiIDs, char **names, char **spousesID, char **childIDs);
#endif
