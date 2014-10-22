// Helen Chac
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_path( char maze[][8], int rows, int columns);

int main(int argc, char **argv)
{
  FILE *fp = fopen(argv[1], "r");
  char array_maze[8][8];
  int i, j;

  for (i = 0; i < 8; i ++)
    for (j = 0; j < 8; j++)
      fscanf(fp, "%c\n", &array_maze[i][j]);

  if (find_path(array_maze, 7, 7) == 0)
    printf("No path was found.\n");
  return 0;
}//main()

int find_path( char maze[][8], int rows, int columns)
{
  if (rows < 0 || rows > 7 || columns < 0 || columns > 7)
    return 0;
  // out of bounds 
  if (rows == 0 && columns == 1)
  {
    printf("(%d, %d)\n", rows, columns);
    return 1;
  } // if found path, return 1
  if (maze[rows][columns] == 'X')
    return 0; 
  maze[rows][columns] = 'X';

  if (find_path(maze, rows+1, columns))
  {
    printf("(%d, %d)\n", rows, columns);
    return 1;
  } // go right
  if (find_path(maze, rows-1, columns))
  {
    printf("(%d, %d)\n", rows, columns);
    return 1;
  } // go left
  if (find_path(maze, rows, columns + 1))
  {
    printf("(%d, %d)\n", rows, columns);
    return 1;
  } // go right
  if (find_path(maze, rows, columns -1))
  {
    printf("(%d, %d)\n", rows, columns);
    return 1;
  } // go left

  return 0;
}//find_path()
