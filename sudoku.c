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
   int i, j, k;
   for (i = 0 ; i < 9 ; i++) //Recorre fila
   {
      for (j = 0 ; j < 9 ; j++) //Recorre columna
      {
         if (n->sudo[i][j] != 0) //Si no está vacío
         {
            //Verificar fila
            for (k = 0 ; k < 9 ; k++) //Revisa si el num está en fila o columna
            {
               if (n->sudo[i][j] == n->sudo[i][k] && k != j)
               {
                  return 0;
               }
            }
            for (k = 0 ; k < 9 ; k++)
            {
               if (n->sudo[i][j] == n->sudo[k][j] && k != i)
               {
                  //Revisa si el num está en la fila
                  return 0;
               }
            }
            //Revisa la submatriz
            int a, b;
            int fila = (i/3) * 3;
            int columna = (j/3) * 3;
            for (a = fila ; a < fila + 3 ; a++)
            {
               for (b = columna ; b < columna + 3 ; b++)
               {               
                  if (n->sudo[i][j] == n->sudo[a][b] && (a == i && b == j))
                  {
                     return 0;
                  }
               }
            }
        }
      } 
   }
    return 1;
}
//-------------------------------------------------------------------
List* get_adj_nodes(Node* n)
{
   List* list=createList();
   int i, j, k;
   for (i = 0; i < 9; i++)
   {
      for (j = 0 ; j < 9; j++)
      {
         if (n->sudo[i][j] == 0)
         {
            for (k = 1 ; k <= 9 ; k++)
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
int is_final(Node* n){
    return 0;
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