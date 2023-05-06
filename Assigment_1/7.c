#include<stdio.h>
void printMatrix( int m , int n , int M1[][n] ){
    // The matrix is -
    int temp[m][n];
    for(int i=0; i<m ; i++){
        for(int j=0; j<n; j++){
            printf("%d ", M1[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void printarray(int n , int a[]){
    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}
void sort(int n , int a[]){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n; j++){
            if(a[j]>a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    printarray(n , a);
}

void solve(int m , int n , int mat[][n]){
    int newarr[m*n];
    int k=0;
    for(int i=0; i<m ; i++){
        for(int j=0; j<n; j++){
            newarr[k++] = mat[i][j];
        }
    }
    printf("The final sorted array is - \n");
    sort(m*n , newarr);
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
    solve( m , n , M1);

    return 0;
}