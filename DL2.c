#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node* next;
	struct Node* prev;
};
struct Node* start=NULL;
struct Node* end=NULL;
void insertAtB(int x);
void insertAtE(int x);
void insertAtSP(int,int);
void showAll();
void showAll2();
int countNode();
void deleteAtB();
void deleteAtE();
void deleteAtSP();
void main(){
	insertAtE(3);
	insertAtE(7);
	insertAtE(5);
	insertAtE(2);
	insertAtE(4);
	deleteAtB();
	deleteAtE();
	insertAtSP(6,4);
	insertAtSP(1,3);
	deleteAtSP(3);
	showAll();
	}

void insertAtB(int x){
	struct Node* temp=malloc(sizeof(struct Node));
	temp->data=x;
	temp->prev=NULL;
	temp->next=start;
	if(start!=NULL)start->prev=temp;
	else end=temp;
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
	temp->prev=end;
	end->next=temp;
	end=temp;
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
	struct Node* t=end;
    for(int i=1;i<countNode()-p+1;i++){
		t=t->prev;
	}
	t->prev->next=temp;
	temp->prev=t->prev;
	temp->next=t;
	t->prev=temp;
}
void showAll(){
	if(start==NULL){
		printf("List is empty");
		return;
	}
	struct Node* temp=start;
	while(temp!=NULL){
		printf("%d\n",temp->data);
		temp=temp->next;
}
}
void deleteAtB(){
    if(start==NULL){
	printf("List is empty");
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
	struct Node* temp=end;
	end=end->prev;
	end->next=NULL;
	free(temp);
}
void deleteAtSP(int p){
	if(p<=1){
		deleteAtB();
		return;
	}
	if(p>=countNode()){
		deleteAtE();
		return;
	}
	struct Node* temp=end;
	for(int i=1;i<countNode()-p+1;i++){
		temp=temp->prev;
	}
	temp->prev->next=temp->next;
	temp->next->prev=temp->prev;
	free(temp);
}
void showAll2(){
	if(start==NULL){
		printf("List is empty");
	    return;
	}
	struct Node* temp=end;
	while(temp!=NULL){
		printf("%d\n",temp->data);
		temp=temp->prev;
}
}
int countNode(){
	int d=0;
	struct Node* temp=end;
	while(temp!=NULL){
		d++;
		temp=temp->prev;
	}
	return d;
}