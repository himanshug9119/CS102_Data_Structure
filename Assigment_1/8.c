#include<stdio.h>

void printMatrix( int m , int n , int M1[][n] ){
    int temp[m][n];
    for(int i=0; i<m ; i++){
        for(int j=0; j<n; j++){
            printf("%d ", M1[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void swap(int *a , int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void solve(int m , int n , int a[][n]){
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            swap(&a[i][j] , &a[j][i]);
        }
    }
    printf("The transpose of given matrix - \n");
    printMatrix(m , n , a);
}

int main(){
    int m, n;
    printf("Enter # of rows and columns of matrix M1- \n");
    scanf("%d%d" , &m , &n);
    int M1[m][n];
    printf("Enter the elements of matrix M1-\n");
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            scanf("%d" , &M1[i][j]);
        }
    }
    printf("The given matrix by user is - \n");
    printMatrix(m , n , M1);
    solve( m , n , M1);

    return 0;
}