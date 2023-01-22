#include<stdio.h>
#include "search.h"
#include "sort.h"
#include<stdlib.h>

void printArray(int *a,int n){
	for(int i=0;i<n;i++){
		printf("%d\t",a[i]);
	}
	printf("\n");
}

int main()
{
    int arr[]= {3,522,343,5,3,2};
    int no= sizeof(arr)/sizeof(int);
    int n;
    int b;
    int key;
    
    printf("Enter 1 for Selection Sort :\n");
    printf("Enter 2 for Bubble Sort : \n");
    printf("Enter 3 for Insertion sort : \n");
    
    scanf("%d",&n);
    

   switch(n){
   
   case 1 :
   selectionSort(arr,no);
   break;
   
   case 2 : 
   bubbleSort(arr,no);
   break;
   
   case 3 :
   insertionSort(arr,no);
   break;
   
   
   default:
   printf("\nEnter a valid number..");
   break;
   }
   
   printArray(arr,no);
   
   printf("Enter 1 for Linear search :\n");
   printf("Enter 2 for binary search :\n");
   scanf("%d",&b);
   
   printf("Enter the key :\n");
   scanf("%d",&key);
   switch(b){
   
   case 1:
   printf("%d\n",linearS(arr,no,key));
   break;
   
   case 2:
   printf("%d\n",BinaryS(arr,no,key));
   break;
   
   default: 
   printf("\nEnter the valid number..");
   break;
   }
   
    return 0;
}
