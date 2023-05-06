#include<stdio.h>

void printarray(int a[] , int n){
    for(int i = 0; i<n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void reverseArray(int a[] , int n){
    int x;
    for(int i=0; i<n/2; i++){
        x = n - i-1;
        int temp  = a[i];
        a[i] = a[x];
        a[x] = temp;
    }
    printarray(a , n);
    return ;
}
// sorting an array
void sort(int a[] , int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n; j++){
            if(a[j]>a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    return ;
}
// finding kth largest and smallest array which containes duplicate elements also
void kthlargestsmall(int nums[] , int n){
    int k;
    printf("Enter the value of k\n");
    scanf("%d" , &k);
    sort(nums ,n); // sorting the given array
    int count = 1; 
    int prev = nums[0]; 
    for (int i=0; i<n; i++) {
        if (nums[i] != prev) { // If current element is not same as previous element
            count++; // Increment the count
            prev = nums[i]; // Update the previous element to current element
        }
        if (count == k) { // If count is equal to k
            break;
        }
    }
    printf("%dth smallest number in the given array = %d\n" , k , nums[k-1]); // printing the kth smallest element
    // next code for calculating the kth largest number in the whole array
    count = 1; 
    prev = nums[0]; 
    for (int i=n-1; i>=0; i--) {
        if (nums[i] != prev) { 
            count++; // Increment the count
            prev = nums[i]; // Update the previous element to current element
        }
        if (count == k) { // If count is equal to k
            break;
        }
    }
    printf("%dth largest number in the given array = %d\n" , k , nums[count]); // printing the kth largest element
}

// finding subarray of given sum 

void Subarraysum(int a[] , int n){
    int sum =0;
    printf("Enter the value of sum-\n");
    scanf("%d", &sum);
    int flag=0;
    for(int i=0; i<n; i++){
        int localsum =0;
        for(int j=i+1; j<n; j++){
            localsum += a[i];
            if(localsum == sum){
                flag = 1;
                printf("The index start from %d to %d", i , j);
                break;
            }
        }
        if(a[i] == sum)
            printf("The sum found at index %d\n" , i);
        if(flag)
            break;
    }
}

// moving negative elements in one side of array

void Movenegativeaside(int a[] , int n){

    // Mathed - 1 by sorting in this the relative order will be lost
    // for(int i=0; i<n-1; i++){
    //     for(int j=0; j<n; j++){
    //         if(a[j]>a[j+1]){
    //             int temp = a[j];
    //             a[j] = a[j+1];
    //             a[j+1] = temp;
    //         }
    //     }
    // }
    // printarray(a , n);

    // second mathed by storing positive element in one array and negative element in second array
    int countp =0;
    for(int i=0; i<n; i++){
        if(a[i]>=0)
            countp++;
    }
    int negative[n-countp]; // array of size all negative numbers 
    int positive[countp]; // array of size all positive numbers 
    int i=0, j=0, k=0;
    // storing all elements in repective to positive and negative
    for(k=0; k<n; k++){
        if(a[k]>=0){
            positive[i] = a[k];
            i++;
        }else{
            negative[j] = a[k];
            j++;
        }
    }
    // now merge both array, negative first and then positive
    i=0;
    for(k=0; k<j; k++)
        a[k] = negative[k];
    for(k; k<n, i<countp; k++)
        a[k] = positive[i++];

    printarray(a , n); // printing the final array
}

// finding first repeating and non repeating elements

void First_repeatandnonrepeat(int a[] , int n){
    int flag=1;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(a[i]==a[j]){
                flag = 0;
                printf("The first repeating element = %d\n", a[i]);
                break;
            }
        }
        if(flag == 0)
            break;
    }

    int count =0;
    for(int i=0; i<n; i++){
        flag = 1;
        for(int j=i+1; j<n; j++){
            if(a[i]==a[j]){
                flag = 0;
                break;
            }
        }

        if(flag == 1){
            printf("The first non repeating element = %d\n", a[i]);
            break;
        }
    }
}


// main funciton 

int main(){
    int n ;
    printf("Enter number of element\n");
    scanf("%d" , &n);
    int a[n];
    for(int i=0; i<n; i++){
        scanf("%d" , &a[i]);
    }
    int choice;
    printf("Enter choice - \n");
    printf("1. Reverse Array\n2. Kth largest and kth smallest\n3. Subarray sum\n4. Move aside negatives.\n5. First-repeating and Non repeating element\n");
    scanf("%d" , &choice);
    switch(choice){
        case 1:{
            reverseArray(a , n);
            break;
        }
        case 2:{
            kthlargestsmall(a , n);
            break;
        }
        case 3:{
            Subarraysum(a , n);
            break;
        }
        case 4:{
            Movenegativeaside(a , n);
            break;
        }
        case 5:{
            First_repeatandnonrepeat(a , n);
            break;
        }
    }
    return 0;
}