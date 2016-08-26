#include<stdio.h>
//#include<conio.h>

typedef struct node{
	int data;
	struct node *next;
} node;

typedef struct dnode{
	int data;
	struct dnode *prev;
	struct dnode *next;
} dnode;


node *head=NULL;
node *head2=NULL;
void rdupl();
void split();
void replace(int,int);
void addf(int);
void addafter(int,int);
void create(int);
void print(node *);
void delete(int);
int count(int);
void rev();
void addend(int);
int issorted();

main(){
	addafter(10,1);
	addafter(100,2);
	addafter(0,3);
	addafter(0,4);
	addafter(0,5);
	addafter(5,13);
	replace(13,49);
	addafter(0,6);
	addafter(6,6);
	addafter(6,6);
	addafter(0,7);
	addafter(0,8);
	addafter(0,9);
	addafter(0,10);
	create(35);
	rdupl();
	delete(7);
	addafter(10,1);
	int c=count(1);
	int v=issorted();
	printf("\nCount(1):%d\n",c);
	printf("\nSorted:%d\n",v);
	printf("Before Splitting:");
	print(head);
	printf("\n");
	printf("\nAfter Adding 33 next to 5:\n");
	addafter(5,33);
	print(head);
	printf("\n");
	split();
	printf("After Splitting:\n\n");
	printf("List 1:");
	print(head);
	printf("List 2:");
	print(head2);

	}

void create(int val){
	if(head!=NULL) return;
	head=(node*)malloc(sizeof(node));
	head->data=val;
	head->next=NULL;
}

void addafter(int b,int val){
	node *temp=head;
	node *nnode=NULL;
	if(head==NULL) {create(val);return;}
	
	while(temp->next!=NULL && temp->data!=b ){
		
		temp=temp->next;
	}
	
	nnode=(node*)malloc(sizeof(node));
	nnode->data=val;
	nnode->next=temp->next;
	temp->next=nnode;
	
}
void delete(int val){
	node *temp=head;
	if(!isfound(val)) return;
	while(temp->next!=NULL ){
		if(temp->next->data==val) break;
		temp=temp->next;
	}
	
	temp->next=temp->next->next;	
}

void addf(int val){
	node *temp=NULL;
	temp=(node*)malloc(sizeof(node));
	temp->data=val;
	temp->next=head;
	head=temp;
	
}

int isfound(int val){
	node *temp=head;
	while(temp->next!=NULL){
		if(temp->data==val) return 1;
		temp=temp->next;
	}
	if(temp->data==val) return 1;
	return 0;
}
void print(node *a){
	node *temp=a;
	while(temp->next!=NULL){
		printf(" %d ",temp->data);
		temp=temp->next;
	}
	printf(" %d \n",temp->data);
}

int count(int val){
	node *temp=head;
	int count=0;
	while(temp->next!=NULL){
		if(temp->data==val) count++;
		temp=temp->next;

	}
	if(temp->data==val) count++;
	return count;
}

void replace(int val,int nval){
	node *temp=head;
	while(temp->next!=NULL){
		if(temp->data==val) break;
		temp=temp->next;
	}
	if(temp->data==val) temp->data=nval;
	
}
int issorted(){
	node*temp=head;
	int dec=0;
	int inc=0;
	//printf("%d",temp->data);
	int flag=1;
	while(temp->next!=NULL){
		if((temp->data)<(temp->next->data)) dec++;
		else if(temp->data>temp->next->data) inc++;
		temp=temp->next;
	}
	if(dec!=0 && inc!=0) return 0;
	return 1;
}

void rdupl(){
	node *temp=head;
	while(temp->next!=NULL){
		if(temp->data==temp->next->data){
			delete(temp->data);
			rdupl();
		}
		temp=temp->next;
	}
	
}
void rev(){
	node *temp=head->next;
	node*temp2=head;
	while(temp->next!=NULL){
		addf(temp->data);
		temp=temp->next;
	}
	addf(temp->data);
	temp2->next=NULL;
}

void split(){
	node *temp=head;
	int i=0;
	int count=1;
	while(temp->next!=NULL){
		if(count%2==0) {addf(temp->data);delete(temp->data);}
		temp=temp->next;
		count++;
	}
	if(count%2==0) addf(temp->data);
	node *temp2=head;
	temp2=temp2->next;
	for(i=2;i<count/2;i++){
		temp2=temp2->next;
	}
	head2=temp2->next;
	temp2->next=NULL;
	rev(head);
	
}
void addend(int data){
	node*temp=head;
	node *nnode=NULL;
	nnode=(node*)malloc(sizeof(node));
	nnode->data=data;
	nnode->next=NULL;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=nnode;
}
