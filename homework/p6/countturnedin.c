//Helen Chac
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void copy_words(char *ar[], char *words_ar[], FILE *fp, int size, int *tot_words);
void trim_words( char **raw_words, int tot_words, char **trimed_words);
char** make_array(int row, int col);
void check_length(char **words_ar, int check_length[], int tot_words);
int check_unique(char** words_ar, int tot_words, char **unique, int *unique_size);
char** resize(char **unique, int *unique_size);
void free_unique( char **c_array, int size);

int main()
{
  FILE *fp;
  char file_words[31], userfile[30];
  char **raw_words_ar, **words_ar, **unique, **trimmed_words_ar;
  int unique_size = 10, unique_words;
  int size = 0, i, tot_words, length[30];

  printf("Filename: ");
  scanf("%s", userfile);
  fp = fopen(userfile, "r");

    while(fscanf(fp, "%s", file_words) != EOF)
      size++;
    raw_words_ar = make_array(size, 30);
    words_ar = make_array(size, 30);
    unique = make_array(unique_size, 30);
    copy_words(raw_words_ar, words_ar, fp, size, &tot_words);
    trimmed_words_ar = make_array(tot_words, 30);
    check_length(words_ar, length, tot_words);
    trim_words(words_ar, tot_words, trimmed_words_ar);
    unique_words = check_unique(trimmed_words_ar, tot_words, unique, &unique_size);
    printf("Total words: %d  Unique words: %d  Unique's size: %d\n", tot_words, unique_words, unique_size);
    printf("Length Count\n");
    if(unique_size == unique_words) // if unique_size is the same as unique_words
      unique_size = unique_words;
    for(i = 0; i < 30; i++)
    {
      if(length[i] != 0) // if the length of the array of the is not 0;
        printf("%4d   %4d\n", i, length[i]);
    } // for i is less than 30
    free_unique(trimmed_words_ar, tot_words);
    free_unique(words_ar, tot_words);
    free_unique(raw_words_ar, tot_words);
  // if the file can be open
  return 0;
}//main()

char** make_array(int row, int col)
{
  int i;
  char **temp;

  temp = (char**) malloc(row * sizeof(char*)); // make addresses for the rows
  for(i = 0; i < row; i++) // make an address for the number of columns. 
    temp[i] = (char*) malloc(col * sizeof(char));

  return temp;
}//make_array malloc

void copy_words( char *ar[], char *words_ar[], FILE *fp, int size, int *tot_words)
{
  char word[31];
  int i, j, k, count_word = 0;

  rewind(fp); // rewind to reread the file
  for(i = 0, k = 0; fscanf(fp, "%s", word) != EOF && i < size; i++)
  {
    int check_word = 0;// check if it's a real word
    for( j = 0; word[j] != '\0'; j++)
    {
      ar[i][j] = word[j];
      if(isalpha(ar[i][j])) // if the character is an alphabet
        check_word = 1;
    } // until j reaches the end of the string
    ar[i][j] = '\0';
    if(check_word)
    {
      count_word++;
      strcpy(words_ar[k], ar[i]);
      k++;
    } //
  }// put every string into the array raw_words_ar[][]
  *tot_words = count_word;
}//copy_words

void check_length(char **words_ar, int length[], int tot_words)
{
  int i, j, len = 0, start;

  for(i = 0; i < 30; i++)
    length[i] = 0;
  for(i = 0; i < tot_words; i++)
  {
    len = 0;
    start = 0;
    for(j = 0; words_ar[i][j] != '\0'; j++)
    {
      if(isalpha(words_ar[i][j]))
      {
        len++;
        start = 1;
      }
      if(start && !isalpha(words_ar[i][j+1]))
        break;
    }
    length[len] += 1;
  }//for
}//check_length

void trim_words( char **words_ar, int tot_words, char **trimed_words)
{
  int i, j, k, found, start, end;
  for(i = 0; i< tot_words; i++)
  {
    found = 0;
    for(j = 0; words_ar[i][j] != '\0' && j < 30; j++)
    {
      if(isalpha(words_ar[i][j]) && found == 0)
      {
        found = 1;
        start = j;
      }
      if(!isalpha(words_ar[i][j+1]) && found == 1)
      {
        end = j;
        break;
      }
    }//for
    for(k = 0; start <= end; start++, k++) // 
      trimed_words[i][k] = tolower(words_ar[i][start]);
  }
}//trim_words

int check_unique(char** words_ar, int tot_words, char **unique, int *unique_size)
{
  int i, j, count = 0, found;
  
  unique[0] = words_ar[0];
  count++;
  for(i = 0; i < tot_words; i++)
  {
    found = 0;
    for(j = 0; j < count; j++)
      if(strcmp(words_ar[i], unique[j])== 0)
	  
    found = 1;
    if(!found) //
    {
      unique[count] = words_ar[i];
      count++;
    }
    if(count == *unique_size) // if 
      unique = resize(unique, unique_size);
  }// go through each part of the array
  
  return count;
}//check_unique*/

char** resize(char **unique, int *unique_size)
{
  int i;
  char **temp;

  *unique_size = *unique_size * 2;
  temp = make_array(*unique_size, 30);
  for(i = 0; i < *unique_size; i++) // store words from unique into temp
    temp[i] = unique[i];
  free(unique);
  return temp;
}//resize();

void free_unique(char **c_array, int size)
{
  int i;

  for(i = 0; i < size; i++) // free the stuff in the array
    free(c_array[i]);
  free(c_array); // free the array
}//free_unique();