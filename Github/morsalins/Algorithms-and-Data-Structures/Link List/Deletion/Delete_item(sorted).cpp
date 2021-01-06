#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct list{
	int data;
	struct list *next;
};

typedef struct list node;

node *insert_sorted(node *);
node *delet(node *);
void display(node *);

int main()
{
	node *start;
	int choice;

	start = NULL;

	printf("1.Insert as sorted order\n2.Delete\n3.Display\n3.Exit\n");

	while(1){
		fflush(stdout);
		printf("\nEnter your choice : ");
		fflush(stdin);
		scanf("%d", &choice);

		if(choice==1)
			start=insert_sorted(start);
		else if(choice==2)
			start=delet(start);
		else if(choice==3)
			display(start);
		else if(choice==4) exit(0);
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
	printf("\n");
	return start;
}//End of function

node *delet(node *start){
	node *temp, *temp1;
	int item;

	printf("Enter an item to delete : ");
	scanf("%d", &item);

	if(start==NULL) printf("\nNo linked list"); // There is no linked list

	else if((start->next==NULL) && (start->data==item)){ //Only one linke list
		free(start);
		start=NULL;
	}
	else if(start->data==item){ //Delete the the 1st node from a linked list
		temp1=start;
		start=start->next;
		free(temp1);
	}
	else{			//middle or last deletion or no linked list found
		temp=start;

		while( (temp->next!=NULL) && (temp->next->data!=item) )
			temp=temp->next;

		if(temp->next==NULL) printf("\nThere is no such item found\n"); //Item no found
		else{
			temp1=temp->next;
			temp->next=temp1->next;
			free(temp1);
		} //End of nested else
	} //End of else

	return start;
} //End of function

void display(node *start){
	node* temp=start;

	if(start==NULL) printf("\nThere is no linked list\n");
	else{
		printf("\nCreated list : ");
		while(temp!=NULL){
			printf("%d ", temp->data);
			temp=temp->next;
		}
	}printf("\n");
}//End of function
