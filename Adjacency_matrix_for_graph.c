#include <stdio.h>
#define V 4

void addedge(int mat[V][V], int i, int j){
    mat[i][j] = 1;
    mat[j][i] = 1;
}

void display(int mat[V][V]){
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++)
            printf("%d ",mat[i][j]);
            printf("\n");
    }
}

int main() {
    
    int mat[V][V] = {0};
    
    addedge(mat, 0, 1);
    addedge(mat, 0, 2);
    addedge(mat, 1, 2);
    addedge(mat, 3, 2);
    
    printf("Adjacency Matrix is:\n");
    display(mat);

    return 0;
}
