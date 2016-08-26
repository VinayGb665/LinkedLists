#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *prev,*next;
} node;
node *head = NULL;
node *h2=NULL;


void insert(int k,int at,int val){
	if(k==1){node *temp=head;
	node *nnode=(node*)malloc(sizeof(node));
	nnode->data=val;
	nnode->prev=NULL;
	nnode->next=NULL;
	if(head==NULL) {head=nnode;return;}
	while(temp->next!=NULL){
		if(temp->data==at){
			nnode->next=temp->next;
			nnode->prev=temp;
			temp->next->prev=nnode->next;
			temp->next=nnode;
			break;
		}
		temp=temp->next;
	}
	if(temp==head){
		head->next=nnode;
		nnode->prev=head->next;
	}
	if(temp->next==NULL){nnode->prev=temp;temp->next=nnode;nnode->next=NULL;}
	}
	if(k==2){
	node *temp=h2;
	node *nnode=(node*)malloc(sizeof(node));
	nnode->data=val;
	nnode->prev=NULL;
	nnode->next=NULL;
	if(h2==NULL) {h2=nnode;return;}
	while(temp->next!=NULL){
		if(temp->data==at){
			nnode->next=temp->next;
			nnode->prev=temp;
			temp->next->prev=nnode->next;
			temp->next=nnode;
			break;
		}
		temp=temp->next;
	}
	
	if(temp==h2){
		h2->next=nnode;
		nnode->prev=h2->next;
	}
	if(temp->next==NULL){nnode->prev=temp;temp->next=nnode;nnode->next=NULL;}
	}
	}
	void print(node *h){
	node *t = 0;
    for(t = h; t; t = t->next) {
        printf("%d\n", t->data);
    }
}

int main() {
    insert(1,5,6);
	insert(1,8,5);
	insert(1,6,7);
	insert(1,7,8);
	insert(1,8,9);
	insert(2,5,6);
	insert(2,8,5);
	insert(2,6,7);
	int hcnt=count(head);
	int ncnt=count(h2);
	//printf("\n    %d  %d\n",hcnt,ncnt);
	printf("List 1:\n");
	print(head);
	
	printf("List2:\n");
	
	print(h2);
	//printf("%d",h2->next->data);
	if(hcnt>ncnt){
	 node *y=NULL;
	 y=head;
	
	for(y=head;y;y=y->next){
		if(h2!=NULL){
		insert(1,y->data,h2->data);
		h2=h2->next;
		y=y->next;

		}
	 }
	 printf("List 1 After :\n");
  print(head);
  
	}
	else if(hcnt<ncnt){
		node *y=NULL;
		y=h2;
		for(y=h2;y->next;y=y->next){
			if(head->next!=NULL ){
				insert(2,y->data,head->data);
				head=head->next;
				y=y->next;
			}
		}
		if(head->next==NULL){insert(2,h2->data,head->data);head=NULL;}
	
	printf("List 2 After :\n");
  print(h2);
}
else {
node *y=NULL;
		y=h2;
		for(y=h2;y->next;y=y->next){
			if(head->next!=NULL ){
				insert(2,y->data,head->data);
				head=head->next;
				y=y->next;
			}
		}
	insert(2,y->data,head->data);
	head=NULL;
	printf("List 2 After :\n");
	print(h2);
}

}
int count(node *j){
	node *temp=j;
	int count=0;
	while(temp->next!=NULL){
		count++;
		temp=temp->next;
		
	}
	count++;
	return count;
}