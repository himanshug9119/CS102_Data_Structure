#include<stdio.h>

int abs(int n){
    return n>0 ? n : (-1)*n;
}

void solve(int a[] , int n){
    int lsum =0, rsum =0;
    for(int i=0; i<n; i++)
        rsum+= a[i]; // storing sum of whole array in a variable rsum
    for(int i=0; i<n; i++){
        rsum -= a[i];
        int temp = a[i];
        a[i] = abs(rsum - lsum);
        lsum += temp;
    }
    // printing the whole array 
    for(int i=0; i<n; i++)
        printf("%d " , a[i]);
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