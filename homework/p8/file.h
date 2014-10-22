// Helen Chac
//

#ifndef FILE_H
#define	FILE_H

FILE* count_records(const char *filename, int *individual_count, int *family_count);
char* get_ID(char *line);
void read_file(Individual *individuals, Family *families, FILE *fp);
char* read_other(char *line, FILE *fp);
char* read_indi(Individual *individuals, int *individual_count, char *line, FILE *fp);
char* read_family( Family *families, int *family_count, char *line, FILE *fp);
void add_child(Family *families, char *line);

#endif	

