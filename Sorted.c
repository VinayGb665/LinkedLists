#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *prev,*next;
} node;
node *head = 0;
//node *h2=0;

void insert(int value){
    node* temp = (node*) malloc (sizeof (node));
    temp -> data = value;
    temp -> next = 0;
    temp -> prev = 0;
    if(head == 0) {
        head = temp;
    } else if(value > head->data) {
        temp->next = head;
        head->prev = temp;
        head = temp;
    } else {
        node *this = head;
        node *prev = 0;
        while(this && this->data > value) {
            prev = this;
            this = this->next;
        }
        temp->next = this;
        temp->prev = prev;
        prev->next = temp;
        if(this) {
            this->prev = temp;
        }
    }
}
void print(node *h){
	node *t = 0;
    for(t = h; t; t = t->next) {
        printf("%d\n", t->data);
    }
}

int main() {
    insert(1);
	insert(6);
    insert(3);
    insert(4);
	/*insert2(10);
	insert2(5);
	node *temp=h2;
	printf("%d"temp->data);*/
   
}