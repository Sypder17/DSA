#include<stdio.h>
#define SIZE 10
 
 void display(int arr[],int n){
  printf("\n");
    
    for(int j = 0 ; j < n ; j++){
        printf("%d\t",arr[j]);
    }
    
    printf("\n");
 	
 }
 void reverseArr(int arr[],int n){
 
 int temp = 0;
 
  for(int i = 0; i< n/2 ;i++){
          temp = arr[i];
          arr[i] = arr[n-i-1];
          arr[n-i-1] = temp;
    }
   
    }
int main(){
   
   int arr[SIZE] = {85 , 70 , 22 ,55 ,30 ,21 ,34 ,11 ,66 ,77};
   int n = 10;
    display(arr,n);
   reverseArr(arr,n);
   display(arr,n);
    
return 0;
}
