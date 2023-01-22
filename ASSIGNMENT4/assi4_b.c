#include<stdio.h>

int ThirdMaxD(int *arr,int n){
    int temp = 0;
	for(int i=0;i<3;i++){
		for(int j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
			  temp = arr[j+1];
			  arr[j+1]=arr[j];
			  arr[j]=temp;		    
            }
	}
    }


	int latch = 0;
	if(n>=3){
		int temp = arr[n-3];
		for(int i=n-1;i>n-3;i--){
			if(temp == arr[i]){
				latch = 1;
				}
		}
	}
	
	if(latch == 1)
		return arr[n-4];
    
	if(n>=3){
	   return arr[n-3];
	}
	
	else{
	return 0;;
	}
}

int main(){

	int arr[]={2,1,1,4};
	int n =sizeof(arr)/sizeof(int);
	int no = ThirdMaxD(arr,n);
	if(no){
        printf("Third Distinct Max element is : %d\n",no);
    }
    else{
        printf("The third Max element does not exists , hence Max elemnt is  : %d\n",arr[n-1]);
    }
		
	return 0;
}
