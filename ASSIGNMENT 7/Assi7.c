#include "hack.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void initList(hackathonClub* list){
    *list = NULL;
    return;
}

    //same as display 
void display(hackathonClub h){
    hackathonClub temp = h;
    printf("\n");
    while(temp){
       printf("Prn :%d \tName : %s\n", temp -> PRN ,temp -> name);
        temp = temp -> next;
    }
    printf("\n");

    return ;
} 

//count members in the clubs except president and secretary
int count(hackathonClub memberCt){ 
    studentClub* temp = memberCt;
    int c= 0 ;
    if(!temp){
        return 0;
    }
    while(temp){
        c++;
        temp = temp -> next;
    }
    if(c <= 2)
    return 0;
    return c-2;
}
 
int deleteMembers(hackathonClub *h,int PRN)
{
    if(!h)  // if h is null
        return -1;
    
    studentClub* pr = (*h);
    studentClub* cu = (*h) -> next;
    if(pr -> PRN == PRN){
    int element = pr -> PRN;
    pr -> next = NULL;
        (*h) = cu;
        free(pr);
        return element;
    }
    while(cu && cu -> PRN != PRN){ //until my !current and current -> next != PRN 
        pr = cu;
        cu = cu -> next;
    }

    studentClub* temp = cu -> next;
    
    int element = cu -> PRN;
     cu -> next = NULL;
     pr -> next = temp;  //pr -> next = cu -> next
    free(pr);
    return element;
}

void addMembers(hackathonClub* h,int PRN,char name[]){
    studentClub* newnode = (studentClub*)malloc(sizeof(studentClub));
    if(!newnode)
    return ;

    newnode -> PRN = PRN;
    newnode -> next = NULL;
    strcpy(newnode -> name,name);//newnode -> next is the name which we saved
    

    if(!(*h)){
         *h = newnode;
         return ;
    }
        studentClub* temp = (*h) -> next;
        (*h) -> next = newnode;
        newnode -> next = temp;
    }
    
    

