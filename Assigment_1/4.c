#include<stdio.h>

void solve(int n , int a[]){
    int temp[n]; // taking this array for checking that if one duplicate element i have added in newarray so 
                //we will not print this  element again
    for(int i=0;i<n; i++){
        temp[i] =  -1; // starting all elements of temp array with -1;
    }
    printf("The unique elements in the array - \n");
    for(int i=0 ; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(a[i] == a[j]){
                temp[j] = 0;
            }
        }
        if(temp[i] == -1){
            printf("%d " , a[i]); // printing all unique elements
        }
        temp[i] = 0;
    }
    
}
int main(){
    int n;
    printf("Enter the size of the array - \n");
    scanf("%d" , &n);
    int a[n];
    printf("Enter the element of the array - \n");
    for(int i=0; i<n; i++){
        scanf("%d" , &a[i]);
    }
    solve(n , a);
    return 0;
}