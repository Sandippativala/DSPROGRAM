#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct stack{
	int size;
	int top;
	int *arr;
};
int isfull(struct stack *ptr){
	if(ptr -> top == ptr -> size -1){
		return 1;
	}
	else{
		return 0;
	}
}
int isempty(struct stack *ptr){
       if(ptr -> top == -1){
		return 1;
	}
	else{
		return 0;
	}
}
void push(struct stack *ptr,int val){
	if(isfull(ptr)){
		printf("stack overflow cannot push %d to the stack\n",val);
	}
	else{
		ptr -> top++;
		ptr -> arr[ptr -> top] = val;
		printf("pushed %d\n",val);
	}
}
int pop(struct stack *ptr){
	if(isempty(ptr)){
		printf("stack empty\n");
		return -1;
	}
	else{
		int val;
		val = ptr -> arr[ptr -> top];
		ptr -> top --;
		printf("poped %d\n",val);
		return val;
	}
}
void display(struct stack *ptr){
	if(isempty(ptr)){
		printf("stack empty\n");
	}
	else{
		int i;
		for(i = ptr->top;i>=0; i--){
			printf("\n\t%d\n",ptr->arr[i]);
		}
	}

}
void peep(struct stack *ptr,int val){
	if(isempty(ptr)){
		printf("stack empty\n");
	}
	else{
		int i,f=0;
		for(i=0;i<=ptr -> top; i++){
			if(ptr -> arr[i] == val){
				printf("value found at %d\n",i);
				f =1;
			}
		}
		if(f == 0){
			printf("value not found\n");
		}
	}
}
void modify(struct stack *ptr,int val){
	if(isempty(ptr)){
		printf("stack empty\n");
	}
	else{
		int i,val1,f=0;
		for(i=0; i<=ptr -> top; i++){
			if(ptr->arr[i] == val){
				printf("enter your new value :-");
				scanf("%d",&val1);
				ptr -> arr[i] = val1;
				printf("value modify...\n");
				f = 1;
			}
		}
		if(f == 0){
			printf("no value found\n");
		}
	}

}
void main(){
	int choice,val;
	struct stack *sp = (struct stack *) malloc(sizeof(struct stack));
	sp -> size = 5;
	sp -> top = -1;
	sp -> arr = (int *)malloc(sp ->size* sizeof(int));
	clrscr();

	while(1){
		printf("---- Stack ----");
		printf("\n1.push \n2.pop \n3.peep \n4.modify \n5.display \n6.exit \n");
		printf("-----------------\n");
		printf("enter your choice :-");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("enter value:-");
				scanf("%d",&val);
				push(sp,val);
			    //	printf("pushed %d",push(sp,val));
				break;
			case 2:
				pop(sp);
				break;
			case 3:
				printf("please enter value for search :- ");
				scanf("%d",&val);
				peep(sp,val);
				break;
			case 4:
				printf("enter value you want to modify :- ");
				scanf("%d",&val);
				modify(sp,val);
				break;
			case 5:
				display(sp);
				break;
			case 6:
				exit(0);
			default:
				printf("invliad choice\n");
				break;
		}
	}
}