#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct list{
	int data; 
	struct list *next;
};

typedef struct list node;

node *insert_sorted(node *);
void display(node *);

int main()
{
	node *start;
	int choice;

	start = NULL;

	printf("1.Insert as sorted order\n2.Display\n3.Exit\n");
	
	while(1){
		fflush(stdout);
		printf("\nEnter your choice : ");
		fflush(stdin);
		scanf("%d", &choice);

		if(choice==1) 
			start=insert_sorted(start);
		else if(choice==2) 
			display(start);
		else if(choice==3) exit(0);
		else printf("\nEnter a correct key.\n");
	}

	getch();
	return 0;
}

node *insert_sorted(node *start){
	node *temp, *temp1;
	int item;
	
	printf("Enter an item : ");
	scanf("%d", &item);
	
	if(start==NULL){
		start = (node *)malloc(sizeof(node));
		start->data = item;
		start->next = NULL;
	}
	else if(start->data>=item){
		temp = (node *)malloc(sizeof(node));
		temp->data=item;
		temp->next=start;
		start=temp;
	}
	else{ 
		temp = start;
		while( (temp->next!=NULL) && (temp->next->data<=item) )
			temp=temp->next;
		
		temp1=(node *)malloc(sizeof(node));

		temp1->data=item;
		temp1->next=temp->next;
		temp->next=temp1;
	}

	return start;
}//End of function

void display(node *start){
	node* temp=start;

	printf("\nCreated list : ");

	while(temp!=NULL){
		printf("%d ", temp->data);
		temp=temp->next;
	}
	printf("\n");
}//End of function
