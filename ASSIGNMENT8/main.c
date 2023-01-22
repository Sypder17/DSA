#include<stdio.h>
#include"palindrome.h"

int isPalindrome(stack *s,char *str,int size){
    if(isEmpty(*s))
    return -1;
    
    for(int i = 0; i<size;i++){
       char c = pop(s);
        if(str[i] != c)
        return 0;
        }
        return -1;
    }
void printReversed(stack *s, char *str, int size){
    for(int i=0;i<size;i++){
        char c = pop(s);
        printf("%c",c);
    }
}

void pushstring(stack *s,char *str,int size){
    for(int i=0;i<size;i++){
        push(s,str[i]);
    }
}



int main(){
    char str[]="level";
    int size = sizeof(str)/sizeof(char);
    stack s;
    initStack(&s,size-1);
    pushstring(&s,str,size-1);
    if(isPalindrome(&s,str,size-1))
        printf("The given string is palindrome\n");
    else
        printf("The given string is not palindrome\n");

    printf("First string is  :  %s\n",str);
    pushstring(&s,str,size-1);
    printf("String after being reversed   :  ");
 
    printReversed(&s,str,size-1);
    printf("\n");
    return 0;
}
