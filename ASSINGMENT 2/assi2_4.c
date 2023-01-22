#include<stdio.h>

int decToBin(int n){
    int binaryN [32];
    int i=0;
    //loop for storing remainder 
    while(n!=0){
      binaryN[i] = n%2;
      n = n/2;
      i++;
    }
    
    //loop for printing binary in reverse 
    int j = i-1;
    for(j = i-1;j>=0;j--){
         printf("%d\n",binaryN[j]);
    }
    binaryN[j];
    //counting number of 1's in the binary number
    j =i;
    int count=0;
    for(int i = 0; i<=j;i++){
        if(binaryN[i]==1){
             count++;
        } 
       
     
 }   
  printf("Number of one's : %d",count);
}

int main(){
int n;
printf("Enter the no : ");
scanf("%d",&n);
decToBin(n);
return 0;
}
