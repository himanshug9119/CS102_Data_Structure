#include<stdio.h>

void printarray(int n , int a[]){
    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

void solve(int a[] , int n){
    int lsum = 0, rsum =0;
    for(int i=0; i<n; i++)
        rsum += a[i];
    int maxvalue=-10000; // declare max value;
    int maxindex;
    for(int i=0; i<n; i++){
        rsum -= a[i];
        lsum += a[i];
        if(rsum*lsum > maxvalue){
            maxindex = i;
            maxvalue = rsum*lsum;
        }
    }
    printf("The maximum multiplication of left subarray sum and right subarray sum is = %d and the index for partition = %d\n" , maxvalue , maxindex);
    printf("The left subarray - \n");
    printarray(maxindex+1 , a); // addition of one for including maxindex value in left subarray
    printf("The right subarray - \n");
    for(int j=maxindex+1 ; j<n; j++){
        printf("%d " , a[j]);
    }
    printf("\n");
    return ;
}
int main(){
    int n ;
    printf("Enter number of element\n");
    scanf("%d" , &n);
    int a[n];
    for(int i=0; i<n; i++){
        scanf("%d" , &a[i]);
    }
    solve(a , n);
    return 0;
}