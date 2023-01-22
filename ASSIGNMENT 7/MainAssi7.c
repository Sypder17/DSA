#include<stdio.h>
#include "hack.h"

int main(){
hackathonClub a ;
initList(&a);
addMembers(&a,10,"soham");
addMembers(&a,11,"pratyay");
addMembers(&a,12,"harsh");
// addMembers(&a,13,"ayush");
display(a);
// printf("\nDeleted Members  : %d",deleteMembers(&a,12));
 printf("\nDeleted Members  : %d",deleteMembers(&a,10));

 printf("\nCount : %d",count(a));
 display(a);
return 0;
}
