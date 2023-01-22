#include<stdio.h>
#include "main.h"
#include<stdlib.h>

int isSymmetric(Sparse s){
	if(s.i != s.j){
		return 0;
	}

	for(int i = 0 ; i < s.i ; i++){
		node* p = s.rows[i];
		node* q = s.col[i];
	
		while(p && q){
			
			if(p -> i != q -> i && q -> j != p -> j)
				
		    if( p -> i == q -> j && q -> i == p -> j  && p -> data != q -> data)
			{
					return 0;
			}
			// }
			p = p -> next;
			q = q -> down;
		}
		if(p || q)
		return 0;
	}
	return 1;
}

void rowsDisplay(Sparse s){
printf("\n");
node* rows;
     for(int i = 0 ; i < s.i; i++){
         rows = s.rows[i];
	  while(rows){
	   printf("%d\t",rows -> data);
	    rows = rows -> next;
	}
	printf("\n");
     }
}

void colDisplay(Sparse s){
   printf("\n");
   node* col;
     for(int i = 0 ; i < s.j; i++){
       col = s.col[i];
        while(col){
          printf("%d\t",col -> data);
            col = col -> down;
       }
    printf("\n");
    }
}



void AddNodeToList(int temp,Sparse **s,int i , int j){
	node* newnode = (node*) malloc(sizeof(node));
	newnode -> i = i;
	newnode -> j = j;
	newnode -> data = temp;
	newnode -> next = NULL;
	newnode -> down = NULL;
	
	node* p;
	if(!(*s) -> rows[i]){
		(*s) -> rows[i] = newnode;
	}
	else{
		p = (*s) -> rows[i];
		while(p -> next){
			p = p -> next;
		}
		   p -> next = newnode;
	}
	
	i = j;
	
	if(!(*s) -> col[i]){
		(*s) -> col[i] = newnode;
	}
	else{
		node* q;
		q = (*s) -> col[i];
		while(q -> down){
		
		q  = q -> down;
		}
		q -> down = newnode;
	
	}	
}
void initSparseMatrix(Sparse *s,char filename[]){

	FILE *fp = fopen(filename,"r");
	int rows;
	int col;
	fscanf(fp,"%d\n",&rows);
	fscanf(fp,"%d\n",&col);
	printf("Rows : %d and col : %d",rows,col);
	
	s -> rows =  (node**)malloc(sizeof(node*)*rows);
	s -> col = (node**)malloc(sizeof(node*)*col);
	
	s -> i = rows;
	s -> j = col;
	for(int i = 0 ; i < rows; i++){
	    int temp ;
	       for(int j = 0 ; j < col; j++){
		    fscanf(fp,"%d\n",&temp);
		      if(temp)
		          AddNodeToList(temp,&s,i,j);
	 }
	}

	return ;
}
void initMatrix(Sparse *s,int i,int j){
	s -> rows =  (node**)malloc(sizeof(node*)*i);
	s -> col = (node**)malloc(sizeof(node*)*j);
	node* ab = s -> rows[0];
	
	s -> i = i;
	s -> j = j;
}

Sparse addTwoMatrix(Sparse s1,Sparse s2){
	
	Sparse s3;
	int rows = s1.i > s2.i ? s1.i : s2.i ;
	int col = s2.j > s2.j ? s1.j : s2.j;
	
	initMatrix(&s3,rows,col);	
	
	for(int i = 0 ; i < rows ; i++){
		node* p1 = s1.rows[i];
		node* p2 = s2.rows[i];
		Sparse* as= &s3;
		  while(p1 && p2){
	
			int sum = 0;
			
			if(p1 -> j == p2 -> j){
				sum = p1 -> data + p2 -> data;
				if(sum != 0)
				  AddNodeToList(sum,&as,p1 -> i,p2 -> j);
				  p1 = p1 -> next;
				  p2 = p2 -> next;
			}
			else if(p1 -> j > p2 -> j){
				  sum = p2 -> data;
				  if(sum != 0)
				  AddNodeToList(sum,&as,p2 -> i,p2 -> j);
				  p2 = p2 -> next;
			}
			else{
				sum = p1 -> data;
				if	(sum != 0)
				AddNodeToList(sum,&as,p1 -> i,p1 -> j);
				p1 = p1 -> next;
			}
		}
		
		  while(p1)
		{
			int sum = 0;
			sum = p1 -> data;
			if(sum != 0)
			AddNodeToList(sum,&as,p1 -> i,p1 -> j);
			p1 = p1 -> next;
		}
		
		  while(p2)
		{
			int sum = 0;
			sum = p2 -> data;
			AddNodeToList(sum,&as,p2 -> i,p2 -> j);
			p2 = p2 -> next;
		}
		printf("\n");
	}
	return s3;
}


void transposeMatrix(Sparse *s1){
	
		for(int i = 0 ; i < s1 -> i; i++){
		node *p = s1 -> rows[i];
		node* temp = NULL;
	
		while(p){
			temp = p -> next;
			swapLinks(&p -> next,&p -> down);
			p = temp;
			}
		}
		int tempMain = s1 -> i;
		(*s1).i = (*s1).j;
		(*s1).j = tempMain ;
		printf("**** %d %d ",s1 -> i , s1 -> j);
		node **as = s1 -> rows;
			s1 -> rows = s1 -> col;
			s1 -> col = as;
}

Sparse subtractTwoMatrix(Sparse s1,Sparse s2){
	
	Sparse s3;
	int rows = s1.i > s2.i ? s1.i : s2.i ;
	int col = s2.j > s2.j ? s1.j : s2.j;
	
	initMatrix(&s3,rows,col);	
	
	for(int i = 0 ; i < rows ; i++){
		node* p1 = s1.rows[i];
		node* p2 = s2.rows[i];
		Sparse *as = &s3;
		while(p1 && p2){
		
			int diff = 0;
			if(p1 -> j == p2 -> j){
				diff = p1 -> data - p2 -> data;
				if(diff != 0)
				AddNodeToList(diff,&as,p1 -> i,p2 -> j);
				p1 = p1 -> next;
				p2 = p2 -> next;
			}
			else if(p1 -> j > p2 -> j){
				diff = p2 -> data;
				if(diff != 0)
				AddNodeToList(diff,&as,p2 -> i,p2 -> j);
				p2 = p2 -> next;
			}
			else{
				diff = p1 -> data;
				AddNodeToList(diff,&as,p1 -> i,p1 -> j);
				p1 = p1 -> next;
			}
			
		}
		
		while(p1)
		{
			int diff = 0;
			diff = p1 -> data;
			if(diff != 0)
			AddNodeToList(diff,&as,p1 -> i,p1 -> j);
			p1 = p1 -> next;
			
		}
		
		while(p2)
		{
			int diff = 0;
			diff = p2 -> data;
			if(diff != 0)
			AddNodeToList(diff,&as,p2 -> i,p2 -> j);
			p2 = p2 -> next;
			
		}
		printf("\n");
	}
	return s3;
}



void swapLinks(node **s1,node **s2){
	node **temp = s1;
	*s1 = *s2;
	*s2 = *temp; 
}	

