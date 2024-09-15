#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct queue{
	int size;
	int front;
	int rear;
	int *arr;
};
void insert(struct queue *ptr,int val){
	if(ptr -> rear == ptr -> size -1){
		printf("Queue is full");
	}
	else{
		if(ptr -> front == -1 && ptr -> rear == -1){
			ptr -> front = 0;
			ptr -> rear =0;
			ptr -> arr[ptr -> rear] = val;
			printf("value inserted...\n");
		}
		else{
			ptr -> rear = ptr -> rear +1;
			ptr -> arr[ptr -> rear] = val;
			printf("value insert\n");
		}
	}
}
int del(struct queue *ptr){
	int val;
	if(ptr->front == -1 && ptr->rear == -1){
		printf("Queue is empty\n");
	}
	else{
		val = ptr -> arr[ptr -> front];
		if(ptr -> front == ptr -> rear){
			ptr -> front = -1;
			ptr -> rear = -1;
		}
		else{
			ptr -> front = ptr -> front +1;
		}
	}
	return val;
}
void display(struct queue *ptr){
	if(ptr->front == -1 && ptr->rear == -1){
		printf("Queue is empty\n");
	}
	else{
		int i;
		for(i = ptr->front; i<= ptr->rear; i++){
			printf("\n\t%d\n",ptr -> arr[i]);
		}
	}

}
void modify(struct queue *ptr,int val){
	int val1,f=0;
	if(ptr->front == -1 && ptr->rear == -1){
		printf("Queue is empty\n");
	}
	else{
		int i;
		for(i = ptr->front; i<= ptr->rear; i++){
			if(ptr -> arr[i] == val){
				printf("enter your new value :- ");
				scanf("%d",&val1);
				ptr -> arr[i] = val1;
				printf("modify..\n");
				f = 1;
			}
		}
		if(f == 0){
			printf("no value found");
		}
	}
}
void main(){
	int choice,val;
	struct queue *qp = (struct queue *) malloc(sizeof(struct queue));
	qp -> size = 5;
	qp -> front = -1;
	qp -> rear = -1;
	qp -> arr = (int *)malloc(qp ->size* sizeof(int));
	clrscr();

	while(1){
		printf("---- Queue ----");
		printf("\n1.insert \n2.delete \n3.modify \n4.display \n5.exit \n");
		printf("---------------\n");
		printf("enter your choice :-");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("enter value:-");
				scanf("%d",&val);
				insert(qp,val);
				break;
			case 2:
			   //	del(qp);
				printf("deleted value is :- %d\n",del(qp));
				break;
			case 3:
				printf("enter value you want to modify :- ");
				scanf("%d",&val);
				modify(qp,val);
				break;
			case 4:
				display(qp);
				break;
			case 5:
				exit(0);
			default:
				printf("invliad choice\n");
				break;
		}
	}
}