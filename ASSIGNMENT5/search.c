#include<stdio.h>

#include "search.h"
int linearS(int arr[], int n, int key){
    
    for(int i = 0; i<=n ; i++){
        if(arr[i] == key){
             return i;
        }
             return -1;
        
    }

}


int BinaryS(int arr[],int n,int key){
    int start = 0;
    int end = n;
    int mid = (start+end)/2;
    while(start<=end){
       if(arr[mid]==key){
           return mid;
       }
       
       else if(arr[mid]>key){
             end = mid - 1;
       }
       
       else{
           start = mid + 1;
       }
    }
    
   return -1; 
}
