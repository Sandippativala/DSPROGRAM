#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct queue{
	int size;
	int front;
	int rear;
	int *arr;
};
int isfull(struct queue *ptr){
	if(ptr -> rear == ptr -> size -1){
		return 1;
	}
	else{
		return 0;
	}
}
int isempty(struct queue *ptr){
	if(ptr -> front == -1 && ptr -> rear == -1){
		return 1;
	}
	else{
		return 0;
	}
}
void insert_front(struct queue *ptr,int val){
	if(ptr -> front == 0){
		printf("Queue is full from front.\n");
	}
	else{
		if(ptr -> front == -1 && ptr -> rear == -1){
			ptr -> front =0;
			ptr -> rear = 0;
		}
		else{
			ptr -> front --;
		}
		ptr -> arr[ptr -> front] = val;
		printf("value inserted in front %d\n",val);
	}
}
void insert_rear(struct queue *ptr,int val){
	if(isfull(ptr)){
		printf("Queue is full.\n");
	}
	else{
		if(ptr -> front == -1 && ptr -> rear == -1){
			ptr -> front =0;
			ptr -> rear = 0;
		}
		else{
			ptr -> rear = ptr -> rear +1;
		}
		ptr -> arr[ptr -> rear] = val;
		printf("value inserted %d\n",val);
	}
}

void del_front(struct queue *ptr){
	int val;
	if(isempty(ptr)){
		printf("Queueu is empty.\n");
	}
	else{
		if(ptr -> front == ptr -> rear){
			val = ptr -> arr[ptr -> front];
			ptr -> front = -1;
			ptr -> rear = -1;
			printf("deleted %d\n",val);
		}
		else{
			val = ptr -> arr[ptr -> front];
			printf("deleted %d\n",val);
			ptr -> front = ptr -> front + 1;
		}
	}
}
void del_rear(struct queue *ptr){
	int val;
	if(isempty(ptr)){
		printf("Queueu is empty.\n");
	}
	else{
		if(ptr -> front == ptr -> rear){
			val = ptr -> arr[ptr -> front];
			ptr -> front = -1;
			ptr -> rear = -1;
			printf("deleted %d\n",val);
		}
		else{
			val = ptr -> arr[ptr -> rear];
			printf("deleted %d\n",val);
			ptr -> rear --;
		}
	}
}
void modify(struct queue *ptr,int val){
	if(isempty(ptr)){
		printf("Queue is empty\n");
	}
	else{
		int i,val1,f=0;
		for(i = ptr -> front; i <= ptr -> rear; i++){
			if(ptr -> arr[i] == val){
				printf("enter new value :-");
				scanf("%d",&val1);
				ptr -> arr[i] = val1;
				f = 1;
				printf("modify\n");
			}
		}
		if(f == 0){
			printf("no value found\n");
		}
	}
}
void display(struct queue *ptr){
	if(isempty(ptr)){
		printf("Queue is empty\n");
	}
	else{
		int i;
		for(i =ptr -> front;i<= ptr -> rear;i++){
			printf("\n\t%d\n",ptr->arr[i]);
		}
	}
}
void main(){
	int choice,val;
	struct queue *qp = (struct queue*)malloc(sizeof(struct queue));
	qp -> size = 5;
	qp -> front = -1;
	qp -> rear = -1;
	qp -> arr = (int*)malloc(qp -> size * sizeof(int));
	clrscr();
	while(1){
		printf("---- Double Queue ----");
		printf("\n1.Insert_Front \n2.Insert_Rear \n3.Delete_Front \n4.Delete_Rear \n5.Modify \n6.Display \n7.Exit \n");
		printf("----------------------\n");
		printf("Enter your choice :-");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("enter value :-");
				scanf("%d",&val);
				insert_front(qp,val);
				break;
			case 2:
				printf("enter value :-");
				scanf("%d",&val);
				insert_rear(qp,val);
				break;
			case 3:
				del_front(qp);
				break;
			case 4:
				del_rear(qp);
				break;
			case 5:
				printf("enter value to modify :-");
				scanf("%d",&val);
				modify(qp,val);
				break;
			case 6:
				display(qp);
				break;
			case 7:
				exit(0);
			default:
				printf("invliad choice.\n");
				break;

		}
	}
}