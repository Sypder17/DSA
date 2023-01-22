#include<stdio.h>
int main(){
 // taking character input 
 char n;
 printf("ENter the Alphabet : ");
 scanf("%c",&n);
 
 //for lowercase -> uppercase
 if( n >= 97 && n <= 122){
     n = n-32;
     printf("%c \n", n);
 }
 
 // for uppercase -> lowercase
 else if(n >= 65 && n <= 90){
     n = n+32;
     printf("%c \n ",n);
 }
 else{
     printf("Enter the valid character");
 }

return 0;
}
