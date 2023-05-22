#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* prev;
	struct Node* next;
};
struct Node* start;
void insertAtB(int);
void showAll();
void showAll2();
void insertAtE(int);
void insertAtSP(int,int);
int countNode();
void deleteAtB();
void deleteAtE();
void deleteAtSP(int);
int search(int);
void main(){
	insertAtE(9);
	insertAtE(10);
	insertAtE(8);
	insertAtE(7);
	insertAtSP(66,3);
	showAll();
	deleteAtSP(3);
	printf("\n");
	printf("index of 8 is %d\n",search(8));
	showAll2();
	}
void insertAtB(int x){
	struct Node* temp=malloc(sizeof(struct Node));
	temp->data=x;
	temp->prev=NULL;
	temp->next=start;
	if(start!=NULL)start->prev=temp;
	start=temp;
}
void insertAtE(int x){
    if(start==NULL){
		insertAtB(x);
		return;
	}
    struct Node* temp=malloc(sizeof(struct Node));
	temp->data=x;
    temp->next=NULL;
	struct Node* t=start;
    while(t->next!=NULL){
		t=t->next;
	}
    t->next=temp;
    temp->prev=t;	
}
void showAll(){
		struct Node* temp=start;
		while(temp!=NULL){
			printf("%d\n",temp->data);
			temp=temp->next;
		}
}
int countNode(){
	int d=0;
	struct Node* temp=start;
	while(temp!=NULL){
		d++;
		temp=temp->next;
	}
	return d;
}

void insertAtSP(int x,int p){
	if(p<=1){
		insertAtB(x);
		return;
	}
    if(p>countNode()){
		insertAtE(x);
		return;
	}
	struct Node* temp=malloc(sizeof(struct Node));
	temp->data=x;
	struct Node* t=start;
	for(int i=1;i<p-1;i++){
		t=t->next;
	}
	temp->next=t->next;
	t->next=temp;
	temp->prev=t;
}

void deleteAtB(){
	if(start==NULL){
		printf("list is empty");
		return;
	}
	struct Node* temp=start;
	start=start->next;
	if(start->next!=NULL)start->prev=NULL;
	free(temp);
}
void deleteAtE(){
	if(start==NULL || start->next==NULL){
		deleteAtB();
		return;
	}
	struct Node* temp=start;
	while(temp->next->next!=NULL)temp=temp->next;
	struct Node* t=temp->next;
	temp->next=NULL;
	free(t);
}
void deleteAtSP(int p){
	if(p<=1){
		deleteAtB();
		return;
	}
	if(p>=countNode()){
		deleteAtB();
		return;
	}
	struct Node* temp=start;
	struct Node* t=start->next;
	for(int i=1;i<p-1;i++){
		temp=temp->next;
		t=t->next;
	}
	temp->next=t->next;
    t->next->prev=temp;
	free(t);
}
void showAll2(){
		struct Node* temp=start;
		while(temp->next!=NULL)temp=temp->next;
		while(temp!=NULL){
			printf("%d\n",temp->data);
			temp=temp->prev;
		}
}

int search(int x){
	int index=-1;
	if(start==NULL){
		return index;
	}
	struct Node* temp=start;
	while(temp!=NULL){
		index++;
		if(temp->data==x)return index;
		temp=temp->next;
	}
	return -1;
}