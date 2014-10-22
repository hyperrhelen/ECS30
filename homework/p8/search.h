// Helen Chac
//

#ifndef SEARCH_H
#define	SEARCH_H

int individual_cmp(const void *ptr, const void *ptr2);
int family_cmp(const void *ptr, const void *ptr2);
void find_children(Individual *individuals, Family *families, int individual_count, int family_count); 
int find_name(Individual *individuals, char name[80], int individual_count);
int find_ID(const char* ID, char **IDs, int count);
void print_children(Family *families, Individual *individuals, int individual_count, char *name);

#endif	

