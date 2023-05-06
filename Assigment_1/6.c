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

void addition( int m , int n , int M1[][n] ,int M2[][n] ){
    int temp[m][n];
    for(int i=0; i<m ; i++){
        for(int j=0; j<n; j++){
            temp[i][j] = M1[i][j] + M2[i][j];
        }
    }
    printMatrix( m , n , temp );
}

void subtraction( int m , int n , int M1[][n] ,int M2[][n] ){
    int temp[m][n];
    for(int i=0; i<m ; i++){
        for(int j=0; j<n; j++){
            temp[i][j] = M1[i][j] - M2[i][j];
        }
    }
    printMatrix( m , n , temp );
}

void multiplication( int m , int n , int M1[][n] ,int M2[][n] ){
    int temp[m][n];
    if(m!=n){
        printf("Multiplication not possible\n");
        return ;
    }
    for(int i=0; i<m ; i++){
        for(int j=0; j<n; j++){
            temp[i][j] = 0;
            for(int k=0; k<m; k++){
                temp[i][j] += M1[i][k]*M2[j][k];
            }
        }
    }
    printMatrix( m , n , temp );
}

void scalerSolve( int m , int n , int M1[][n] ,int M2[][n] ){
    int x , y;
    printf("Enter the value of x and y - \n");
    scanf("%d%d" , &x , &y);

    int temp[m][n];
    for(int i=0; i<m ; i++){
        for(int j=0; j<n; j++){
            temp[i][j] = x*M1[i][j] + y*M2[i][j];
        }
    }

    printMatrix( m , n , temp );
    return ;
}

int main(){
    int m, n;
    printf("Enter # of rows and columns of matrix M1- \n");
    scanf("%d%d" , &m , &n);
    int M1[m][n];
    int M2[m][n];
    printf("Enter the elements of matrix M1-\n");
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            scanf("%d" , &M1[i][j]);
        }
    }
    printf("Enter the elements of matrix M2-\n");
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            scanf("%d" , &M2[i][j]);
        }
    }
    printf("The matrix m1 - \n");
    printMatrix(m , n , M1 );
    printf("The matrix m2 - \n");
    printMatrix(m , n , M2 );

    int choice;
    printf("Enter choice - \n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Scaler Equation Solve\n");
    scanf("%d" , &choice);
    switch(choice){
        case 1:{
            addition(m , n , M1 , M2 );
            break;
        }
        case 2:{
            subtraction(m , n , M1 , M2 );
            break;
        }
        case 3:{
            multiplication(m , n , M1 , M2 );
            break;
        }
        case 4:{
            scalerSolve(m , n , M1 , M2);
            break;
        }
        default:{
            printf("You have entered wrong input.");
        }
    }


    return 0;
}