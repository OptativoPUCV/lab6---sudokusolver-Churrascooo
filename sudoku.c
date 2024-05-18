#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;
//-------------------------------------------------------------------
Node* createNode()
{
   Node* n=(Node*) malloc(sizeof(Node));
   return n;
}
//-------------------------------------------------------------------
Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}
//-------------------------------------------------------------------
Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}
//-------------------------------------------------------------------
void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}
//-------------------------------------------------------------------
int is_valid(Node* n)
{
   int i, j;
   for (i = 0 ; i < 9 ; i++) //Recorre fila
   {
      int arrayFilas[10] = {0};
      for (j = 0 ; j < 9 ; j++) //Recorre columna
      {
         if (n->sudo[i][j] == 0)
         {
            continue;
         }
         if (n->sudo[i][j] < 1 || n->sudo[i][j] > 9)
         {
            return 0;
         }
         if (arrayFilas[n->sudo[i][j]] != 0)
         {
            return 0;
         }
         arrayFilas[n->sudo[i][j]] = 1;
      }
   }
   for (i = 0 ; i < 9 ; i++) //Recorre fila
   {
      int arrayColumnas[10] = {0};
      for (j = 0 ; j < 9 ; j++) //Recorre columna
      {
         if (n->sudo[i][j] == 0)
         {
            continue;
         }
         if (n->sudo[i][j] < 1 || n->sudo[i][j] > 9)
         {
            return 0;
         }
         if (arrayColumnas[n->sudo[i][j]] != 0)
         {
            return 0;
         }
         arrayColumnas[n->sudo[i][j]] = 1;
      }
   }
   
   
   //Revisa la submatriz
   for (int k = 0 ; k < 9 ; k++)
   {
      int arraySubmatrices[10] = {0};
      for (int m = 0 ; m < 9 ; m++)
      {
         int i = 3 * (k/3) + (m/3);         
         int j = 3 * (k%3) + (m%3);
         if (n->sudo[i][j] == 0)
         {
            continue;
         }
         if (n->sudo[i][j] < 1 || n->sudo[i][j] > 9)
         {
            return 0;
         }
         if (arraySubmatrices[n->sudo[i][j]] != 0)
         {
            return 0;
         }
         arraySubmatrices[n->sudo[i][j]] = 1;
         } 
   }
   return 1;
}
//-------------------------------------------------------------------
List* get_adj_nodes(Node* n)
{
   List* list=createList();
   int i, j, k;
   int primeraCasilla = 0;
   for (i = 0; i < 9; i++)
   {
      for (j = 0 ; j < 9; j++)
      {
         if (n->sudo[i][j] == 0 && primeraCasilla == 0)
         {
            primeraCasilla = 1;
            for (k = 1 ; k < 10 ; k++)
            {
               Node *copia = copy(n);
               copia->sudo[i][j] = k;
               if (is_valid(copia))
               {
                  pushBack(list, copia);
               }
               else
               {
                  free(copia);
               }
            }
            break;
         }
      }
   }
   return list;
}
//-------------------------------------------------------------------
int is_final(Node* n)
{
   if (is_valid(n))
   {
      return 0;
   }
    return 1;
}
//-------------------------------------------------------------------
Node* DFS(Node* initial, int* cont){
  return NULL;
}
//-------------------------------------------------------------------
/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/