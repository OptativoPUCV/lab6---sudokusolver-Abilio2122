#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

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

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n){
  int i,j, numColumna, num;
  for(i=0;i<9;i++){
    int filas[10]={0,0,0,0,0,0,0,0,0,};
    int columnas[10]={0,0,0,0,0,0,0,0,0,};
    for(j=0;j<9;j++){
      num=n->sudo[i][j];
      if(num !=0){
        if(filas[num]==0){
          filas[num]=1;
        }
        else{
          return 0;
        }
      }
      numColumna=n->sudo[j][i];
      if(numColumna !=0){
        if(columnas[numColumna]==0){
          columnas[numColumna]=1;
        }
        else{
          return 0;
        }
      }
    }
  }
  // recorrer sub matriz
  for(i = 0; i < 9; i += 3){
    for(j = 0; j < 9; j += 3){
      int submatriz[10] = {0,0,0,0,0,0,0,0,0,};
      int k, l;
      for(k = i; k < i + 3; k++){
        for(l = j; l < j + 3; l++){
          num = n->sudo[k][l];
          if(num != 0){
            if(submatriz[num] == 0){
              submatriz[num] = 1;
            } else {
              return 0;
            }
          }
        }
      }
    }
  }
  return 1;
}

List* get_adj_nodes(Node* n){
    List* list = createList();
    int i,j,num;
  
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            if(n->sudo[i][j] == 0){
                for(num=1;num<=9;num++){
                    Node *adyacente = copy(n);  
                    adyacente->sudo[i][j] = num;
                    if(is_valid(adyacente)){
                        pushBack(list, adyacente);
                    } else {
                        free(adyacente);
                    }
                }
                return list;
            }
        }
    }
    
    return list;
}

int is_final(Node* n){
    int i, j;
    for(i = 0; i < 9; i++){
        for(j = 0; j < 9; j++){
            if(n->sudo[i][j] == 0){
                return 0; 
            }
        }
    }
    return 1; 
}
Node* DFS(Node* initial, int* cont){
    
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/