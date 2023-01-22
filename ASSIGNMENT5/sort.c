#include<stdio.h>
#include<stdlib.h>


void bubbleSort(int *arr,int n){
        int temp = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
			   temp = arr[j];
			   arr[j] = arr[j+1];
			   arr[j+1] = temp;		    
		}
	}
}
}

void selectionSort(int *arr,int n){
	for(int i=0;i<n;i++){
		int min=i;
		int temp =0;
		for(int j=i+1;j<n;j++){
			if(arr[j]<arr[min])
			  min=j;
		}
		if(min!=i){
		 temp = arr[i];
	         arr[i] = arr[min];
		 arr[min] = temp;		    
		   }
		}
	}


void insertionSort(int *arr,int n){
	int val,j;
        int temp =0;
	for(int i=1;i<n;i++){
		val=arr[i];
		j=i-1;
		while(j >= 0 && arr[j] > val){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=val;
	}
}
