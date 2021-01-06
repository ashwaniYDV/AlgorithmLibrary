#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct list{
	int data;
	struct list *next;
};

typedef struct list node;

void insert_begin(node *);
void insert_end(node *);
void display(node *); 

int main()
{
	node *start; 
    int value, choice;
	
	start = (node *)malloc(sizeof(node));
	start->next = NULL;
	
	printf("1.insert at Begin\n2.Insert at end\n3.Display\n4.Exit\n");

	while(1){
		fflush(stdout);
		printf("\nEnter your choice : ");
		fflush(stdin);
		scanf("%d", &choice);

		if(choice==1)
			insert_begin(start);
		else if(choice==2)
			insert_end(start);
		else if(choice==3)
			display(start);
		else if(choice==4) exit(0);
		else printf("\nWrong! Enter a corret key to choice\n");
	}//end of while

	getch();
	return 0;
} //end of main

void insert_begin(node *start){
	node *temp;
	
	temp = (node *)malloc(sizeof(node));

	fflush(stdout);
	printf("\nEnter your data : ");
	fflush(stdin);
	scanf("%d", &temp->data);

	temp->next = start->next;
	start->next = temp;

} //end of function;

void insert_end(node *start){
	node *temp = (node *)malloc(sizeof(node));
	
	fflush(stdout);
	printf("\nEnter your data : ");
	fflush(stdin);
	scanf("%d", &temp->data);

	while(start->next!=NULL)
		start = start->next;

	start->next = temp;
	temp->next = NULL;
}
void display(node *start){
	
	if(start->next==NULL) printf("\nNo link exist");
	
	else{
		printf("\nDisplay : ");
		start = start->next;
		while(start!=NULL){
			printf("%d ", start->data);
			start = start->next;
		}//end of while
	}//end of else
	printf("\n");
}//end of function

