#include<stdio.h>

void printArray(int *a,int n){
	for(int i=0;i<n;i++){
		printf("%d\t",a[i]);
	}
	
}

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

int main()
{
    int arr[]={3,5,2,1,8,5,2,7};
    int size = sizeof(arr) / sizeof(int);
    int n;
    printf(" Enter 1 for Bubble Sort :\n Enter 2 for Selection sort : \n Enter 3 for Insertion Sort :\n");
    scanf("%d",&n);

    switch(n)
    {
        case 1: bubbleSort(arr,size);
                break;
        case 2: selectionSort(arr,size);
                break;
        case 3: insertionSort(arr,size);
                break;
        default: printf("Enter a valid number..");
    }

    printArray(arr,size);

    return 0;
}
