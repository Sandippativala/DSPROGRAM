#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct cqueue{
	int size;
	int front;
	int rear;
	int *arr;
};
int isfull(struct cqueue *ptr){
	if((ptr -> front == 0 && ptr -> rear == ptr -> size -1) || ptr -> rear == ptr -> front -1){
		return 1;
	}
	else{
		return 0;
	}
}
int isempty(struct cqueue *ptr){
	if(ptr -> front == -1 && ptr -> rear == -1){
		return 1;
	}
	else{
		return 0;
	}
}
void insert(struct cqueue *ptr,int val){
	if(isfull(ptr)){
		printf("Cqueue is full\n");
	}
	else{
		if(ptr -> front == -1 && ptr -> rear == -1){
			ptr -> front = 0;
			ptr -> rear = 0;
		}
		else{
			if(ptr -> rear == ptr -> size -1 && ptr -> front != 0){
				ptr -> rear = 0;
			}
			else{
				ptr -> rear = ptr -> rear +1;
			}
		}
		ptr -> arr[ptr -> rear] = val;
		printf("value inserted\n");
	}
}
int del(struct cqueue *ptr){
	int val;
	if(isempty(ptr)){
		printf("Cqueue is empty\n");
	}
	else{
		if(ptr -> front == ptr -> rear){
			val =ptr -> arr[ptr -> front];
			ptr -> front = -1;
			ptr -> rear = -1;
		}
		else{
			val = ptr -> arr[ptr -> front];
			ptr -> front = ptr -> front +1;
		}
		return val;
	}
}
void modify(struct cqueue *ptr,int val){
	int f = 0;
	if(isempty(ptr)){
		printf("Cqueue is empty\n");
	}
	else{
		int i,j,val1;
		if(ptr -> front <= ptr -> rear){
			for(i = ptr -> front; i <= ptr -> rear; i++){
				if(ptr -> arr[i] == val){
					printf("enter new value :-");
					scanf("%d",&val1);
					ptr -> arr[i] = val1;
					f =1;
					printf("modify :- %d\n",val1);
				}
			}
			printf("\n");
		}
		else if(ptr -> front > ptr -> rear){
			for(i = ptr -> front; i <= ptr -> size -1; i++){
				printf("enter new value :-");
				scanf("%d",&val1);
				ptr -> arr[i] = val1;
				f =1;
				printf("modify :- %d\n",val1);
			}
			for(j = 0; j <= ptr -> rear; j++){
				printf("enter new value :-");
				scanf("%d",&val1);
				ptr -> arr[i] = val1;
				f =1;
				printf("modify :- %d\n",val1);
			}
			printf("\n");
		}
	}
	if(f == 0){
		printf("no value found.\n");
	}
}
void display(struct cqueue *ptr){
	if(isempty(ptr)){
		printf("Cqueue is empty\n");
	}
	else{
		int i,j;
		if(ptr -> front <= ptr -> rear){
			for(i = ptr -> front; i <= ptr -> rear; i++){
				printf("%d\t",ptr -> arr[i]);
			}
			printf("\n");
		}
		else if(ptr -> front > ptr -> rear){
			for(i = ptr -> front; i <= ptr -> size -1; i++){
				printf("%d\t",ptr -> arr[i]);
			}
			for(j = 0; j <= ptr -> rear; j++){
				printf("%d\t",ptr -> arr[j]);
			}
			printf("\n");
		}
	}
}
void main(){
	int choice,val;
	struct cqueue *cq = (struct cqueue*)malloc(sizeof(struct cqueue));
	cq -> size = 5;
	cq -> front = -1;
	cq -> rear = -1;
	cq -> arr = (int *)malloc(cq -> size * sizeof(int));
	clrscr();
	while(1){
		printf("---- Circular Queue ----\n");
		printf("\n1.insert \n2.delete \n3.modify \n4.display \n5.exit \n");
		printf("------------------------\n");
		printf("enter your choice :-");

		scanf("%d",&choice);
		printf("\n");
		switch(choice){
			case 1:
				printf("enter value :-");
				scanf("%d",&val);
				insert(cq,val);
				break;
			case 2:
				printf("value deleted is %d\n",del(cq));
				break;
			case 3:
				printf("enter value you want to update :-");
				scanf("%d",&val);
				modify(cq,val);
				break;
			case 4:
				display(cq);
				break;
			case 5:
				exit(0);
			default:
				printf("invalid choice\n");
				break;
		}
	}
}