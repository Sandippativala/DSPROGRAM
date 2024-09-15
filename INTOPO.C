#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
	int size;
	int top;
	int *arr;
};
int stacktop(struct stack *ptr){
	return ptr -> arr[ptr -> top];
}
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
void push(struct stack *ptr,char val){
	if(isfull(ptr)){
		printf("stack overflow cannot push %d to the stack\n",val);
	}
	else{
		ptr -> top++;
		ptr -> arr[ptr -> top] = val;
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
		return val;
	}
}
int precedence(char ch){
	if(ch == '*' || ch == '/'){
		return 3;
	}
	else if(ch == '+' || ch == '-'){
		return 2;
	}
	else{
		return 0;
	}
}
isoperator(char ch){
	if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
		return 1;
	}
	else{
		return 0;
	}
}
char *infixtopostfix(char *infix){
	int i=0,j=0;
	char *postfix;

	struct stack *sp;
	sp = (struct stack*)malloc(sizeof(struct stack));
	sp -> size = 10;
	sp -> top = -1;
	sp -> arr = (char*)malloc(sp -> size * sizeof(char));

	postfix = (char*)malloc((strlen(infix)+1) * sizeof(char));
	while(infix[i]!='\0'){
		if(!isoperator(infix[i])){
			postfix[j] = infix[i];
			j++;
			i++;
		}
		else{
			if(precedence(infix[i]) > precedence(stacktop(sp))){
				push(sp , infix[i]);
				i++;
			}
			else{
				postfix[j] = pop(sp);
				j++;
			}
		}
	}
	while(!isempty(sp)){
		postfix[j] = pop(sp);
		j++;
	}
	postfix[j] = '\0';
	return postfix;
}
void main(){
	char *infix;
	clrscr();
	printf("enter infix value :-");
	scanf("%s",infix);
	printf("postfix is :- %s",infixtopostfix(infix));
	getch();
}