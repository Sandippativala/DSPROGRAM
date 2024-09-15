#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct stack{
	int size;
	int top;
	int top1;
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
void push_top(struct stack *ptr,int val){
	if(isfull(ptr)){
		printf("stack overflow cannot push %d to the stack\n",val);
	}
	else{
		if(ptr -> top == -1 && ptr -> top1 == -1){
			ptr -> top = 0;
			ptr -> top1 = 0;
			ptr -> arr[ptr -> top] = val;
		}
		else{
			ptr -> top++;
			ptr -> arr[ptr -> top] = val;
		}
		printf("pushed %d\n",val);
	}
}
void push_front(struct stack *ptr,int val){
	if(ptr -> top1 == 0){
		printf("stack overflow to front cannot push %d to the stack\n",val);
	}

	else{
		if(ptr -> top == -1 && ptr -> top1 == -1){
			ptr -> top = 0;
			ptr -> top1 = 0;
			ptr -> arr[ptr -> top1] = val;
		}
		else{
			ptr -> top1--;
			ptr -> arr[ptr -> top1] = val;
		}
		printf("pushed %d\n",val);
	}
}
int pop_top(struct stack *ptr){
	if(isempty(ptr)){
		printf("stack empty\n");
		return -1;
	}
	else{
		int val;
		if(ptr -> top == ptr -> top1){
			val = ptr -> arr[ptr -> top];
			ptr -> top = -1;
			ptr -> top1 = -1;
		}
		else{

			val = ptr -> arr[ptr -> top];
			ptr -> top --;
		}
		printf("poped %d\n",val);
		return val;
	}
}
int pop_front(struct stack *ptr){
	if(isempty(ptr)){
		printf("stack empty\n");
		return -1;
	}
	else{
		int val;
		if(ptr -> top == ptr -> top1){
			val = ptr -> arr[ptr -> top1];
			ptr -> top = -1;
			ptr -> top1 = -1;
		}
		else{

			val = ptr -> arr[ptr -> top1];
			ptr -> top1++;
		}
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
		for(i = ptr->top; i >= ptr -> top1; i--){
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
		for(i= ptr -> top1; i<=ptr -> top; i++){
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
		for(i= ptr -> top1; i<=ptr -> top; i++){
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
	sp -> top1 = -1;
	sp -> arr = (int *)malloc(sp ->size* sizeof(int));
	clrscr();

	while(1){
		printf("----- Double Stack -----");
		printf("\n1.Push_Top \n2.Push_Front \n3.Pop_Top \n4.Pop_Front \n5.Peep \n6.Modify \n7.Display \n8.Exit \n");
		printf("------------------------\n");
		printf("Enter your choice :-");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("enter value:-");
				scanf("%d",&val);
				push_top(sp,val);
				break;
			case 2:
				printf("enter value:-");
				scanf("%d",&val);
				push_front(sp,val);
				break;
			case 3:
				pop_top(sp);
				break;
			case 4:
				pop_front(sp);
				break;
			case 5:
				printf("please enter value for search :- ");
				scanf("%d",&val);
				peep(sp,val);
				break;
			case 6:
				printf("enter value you want to modify :- ");
				scanf("%d",&val);
				modify(sp,val);
				break;
			case 7:
				display(sp);
				break;
			case 8:
				exit(0);
			default:
				printf("invliad choice\n");
				break;
		}
	}
}