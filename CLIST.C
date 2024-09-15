#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

void insert(struct node **head, int ele) {
    struct node *new1 = (struct node*)malloc(sizeof(struct node));
    struct node *curr = *head, *prev = NULL;
    new1->data = ele;

    if (!new1) {
	printf("Memory allocation failed\n");
	return;
    }

    if (*head == NULL) {
	*head = new1;
	new1->next = *head;
    }
    else {

	if (curr->data >= ele) {
	    while (curr->next != *head) {
		curr = curr->next;
	    }
	    new1->next = *head;
	    curr->next = new1;
	    *head = new1;
	}
	else {
		prev = *head;
		curr = curr ->next;
	    while (curr != *head && curr -> data < ele) {
		prev = curr;
		curr = curr->next;
	    }
	    prev->next = new1;
	    new1->next = curr;
	}
    }

    printf("Inserted %d \n", ele);
}

int del(struct node **head, int ele) {

    struct node *curr = *head,*prev = NULL,*temp = *head;
    int val;

    if (*head == NULL) {
	printf("List is empty\n");
	return -1;
    }

    if (curr->next == *head && curr->data == ele) {
	val = curr->data;
	free(curr);
	*head = NULL;
	printf("Deleted element %d\n", val);
	return val;
    }

    if (curr->data == ele) {
	while (curr->next != *head) {
	    curr = curr->next;
	}
       // struct node *temp = *head;
	val = temp->data;
	*head = temp->next;
	curr->next = *head;
	free(temp);
	printf("Deleted element %d\n", val);
	return val;
    }
     prev = *head;
    curr = curr->next;
    while (curr != *head && curr->data != ele) {
	prev = curr;
	curr = curr->next;
    }

    if (curr == *head) {
	printf("Element %d not found in the list\n", ele);
	return -1;
    }

    val = curr->data;
    prev->next = curr->next;
    free(curr);

    printf("Deleted element %d\n", val);
    return val;
}

void modify(struct node *head, int ele) {
    struct node *curr = head;
    int newVal;

    if (head == NULL) {
	printf("List is empty\n");
	return;
    }

    do {
	if (curr->data == ele) {
	    printf("Enter new value: ");
	    scanf("%d", &newVal);
	    curr->data = newVal;
	    printf("Value modified.\n");
	    return;
	}
	curr = curr->next;
    } while (curr != head);

    printf("Element %d not found in the list.\n", ele);
}

void display(struct node *head) {
     struct node *curr = head;
    if (head == NULL) {
	printf("List is empty\n");
	return;
    }

    do{
	printf("%d -> ", curr->data);
	curr = curr->next;
    }while(curr != head);

    printf("HEAD (%d)\n", head->data);
}

void main() {
    int choice, ele;
    struct node *head = NULL;
    clrscr();

    while (1) {
        printf("---- Circular Linked List ----\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Modify\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("--------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &ele);
                insert(&head, ele);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &ele);
                del(&head, ele);
                break;
            case 3:
                printf("Enter value to modify: ");
                scanf("%d", &ele);
                modify(head, ele);
                break;
            case 4:
                display(head);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
    }
}
