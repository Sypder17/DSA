#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}node;

typedef node* list;

void initList(list *l){
   *l = NULL;
   return;
}

void append(list *l, int data){
	node* nn = (node*)malloc(sizeof(node));
	nn -> data = data;
	nn -> next = NULL;
	//printf("append");

	if( *l == NULL){
		*l = nn;
	}
	
	else{  
		node* temp = *l;
		while(temp -> next != NULL){
			temp = temp -> next;
		}
		temp -> next = nn;
		nn -> next = NULL;
		
	//printf("here");
	}
	return;

}

void reverse(list *l){
	node* head = *l;
	node* p = *l;
	while(p -> next != NULL){
		p = p->next;
	}
	
	while(p != head){
		
		printf("%d\t",p -> data);
		--p;
		--p;
	}
	printf("%d", head->data);
	
	return;
}

/*int delete(list *l){
	node* temp = *l;
	node* del;
	int element;
	while(temp){
		if(temp -> next == temp){
			del = temp;
			element = temp -> data;
			temp = temp -> next;
			free(temp);
		}
		else{
			return -1;
		}
	}
}
*/

/*int isPalindrome(list l){
	if(reverse(&l) == l){
		return 1;
	}
	
	else{
	
		return -1;
	}
	
	
}
*/
void display(list l){
	if(l == NULL){
	return;
	}
	
	node* disp = l;
	while(disp!= NULL){
		printf("%d\t",disp -> data);
		disp = disp -> next;
	}
	printf("\n");
return;
}

int main(){
	list l1,l2;
	
	initList(&l1);
	initList(&l2);
	append(&l1,10);
	append(&l1,20);
	append(&l1,30);
	display(l1);
	reverse(&l1);
	//printf("%d\n",isPalindrome(l1));
	//printf("%d\n",delete(l2));]
	
	printf("\n");
	append(&l2,11);
	append(&l2,22);
	append(&l2,33);
	display(l2);
	reverse(&l2);
	
	//printf("%d\n",delete(l2));
	//printf("%d\n",isPalindrome(l2));
	
	
	return 0;
	}
