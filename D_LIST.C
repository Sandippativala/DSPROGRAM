#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
	struct node *pre;
	int data;
	struct node *next;
};
void insert(struct node **head,int ele){
	struct node *new1,*curr,*prev;
	new1 = (struct node*)malloc(sizeof(struct node));
	curr = *head;
	prev = NULL;
	if(!new1){
		printf("memory not\n");
	}
	else{
		//new -> data = ele;
	       	if(*head == NULL){
			new1 -> next = NULL;
			new1 -> pre = NULL;
			*head = new1;
		}
			while(curr != NULL && curr -> data < ele){
				prev = curr;
				curr = curr -> next;
			}
			if(curr == NULL){
				new1 -> pre = prev;
				new1 -> next = curr;
				*head = new1;
			}
			else if(curr -> next == NULL){
				curr -> next = new1;
				new1 -> pre = curr;
			}
			else{
				new1 -> next = curr;
				new1 -> pre = prev;
				prev -> next = new1;
				curr -> pre = new1;
			}
			printf("%d - %d- %d\n",new1 -> pre,new1 -> data,new1 -> next);
	}
}
int del(struct node **head){
	int ele;
	struct node *curr,*prev;
	printf("enter value you want to delete :-");
	scanf("%d",&ele);
	curr = *head;
	prev = NULL;
	if(*head == NULL){
		printf("link list is empty\n");
	}
	else{
		while(curr != NULL && curr -> data != ele){
			prev = curr;
			curr = curr -> next;
		}
		if(*head == curr){
			ele = curr -> data;
			*head = curr -> next;
			curr -> next -> pre = curr -> pre;
		}
		else{
			if(curr -> next == NULL){
				ele = curr -> data;
				prev -> next = NULL;
			}
			else{
				ele = curr -> data;
				prev -> next = curr -> next;
				curr -> next -> pre = prev;
			}
		}
	}
	return ele;
}
void modify(struct node *head,int ele){
	if(head == NULL){
		printf("list is empty\n");
	}
	else{
		int ele1;
		while(head != NULL){
			if(head -> data == ele){
				printf("enter your new value :- ");
				scanf("%d",&ele1);
				head -> data = ele1;
				printf("modify..\n");
			}
			head = head -> next;
		}
	}
}   */
void display(struct node *head){
	if(head == NULL){
		printf("list is empty\n");
	}
	else{
		while(head != NULL){
			printf("%d - %d - %d ->",head -> pre,head ->data,head -> next);
			head = head -> next;
		}
	}
}
void main(){
	int choice,ele;
	struct node *head = NULL;
	clrscr();
	while(1){
		printf("\n1.insert \n2.delete \n3.modify \n4.display \n5.exit \nenter your choice :- ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("enter value :-");
				scanf("%d",&ele);
				insert(&head,ele);
				break;
			case 2:
				printf("deleted :- %d\n",del(&head));
				break;
			case 3:
				printf("enter value you want to change :-");
				scanf("%d",&ele);
				modify(head,ele);
				break;    
			case 4:
				display(head);
				break;
			case 5:
				exit(0);
			default:
				printf("invalid choice\n");
				break;
		}
	}
}