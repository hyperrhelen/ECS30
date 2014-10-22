// Helen Chac
//

#ifndef MAIN_H
#define	MAIN_H

typedef struct {
  char *INDI;
  char *NAME;
  char *FAMC;
  char *FAMS;
} Individual;

typedef struct {
  char *FAM;
  char *HUSB;
  char *WIFE;
  char **CHILs;
  int chil_count;
} Family;

enum {DONE = 0, FINDCHILDREN, PRINTTREE};

void run( int individual_count, int family_count, Individual *individuals, Family *families);

#endif	

