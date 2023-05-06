#include<stdio.h>
// check a2 is subset a1 , or not 
// Arrray a1 and a2 contains only unique elements
void checksubset(int A1[] , int n1 , int A2[] , int n2){
    if(n2>n1){
        printf("A2 is not subset of A1\n");
        return ;
    }
    int i=0 , j=0;
    for(i=0; i<n2; i++){
        for(j=0; j<n1; j++){
            if(A1[j] == A2[i]){
                break;
            }
        }
        if(j==n1){
            printf("A2 is not subset of A1\n");
            return ;
        }
    }
    printf("A2 is subset of A1\n");
}
int main(){
    int n1 , n2;
    printf("Enter the size of array A1 - \n");
    scanf("%d" , &n1);
    int A1[n1];
    printf("Enter the elements of array A1\n");
    for(int i=0; i<n1 ; i++)
        scanf("%d" , &A1[i]);
    printf("Enter the size of array A2 - \n");
    scanf("%d" , &n2);
    int A2[n2];
    printf("Enter the elements of array A2\n");
    for(int i=0; i<n2 ; i++)
        scanf("%d" , &A2[i]);
    checksubset(A1, n1 , A2 , n2);
    return 0;
}