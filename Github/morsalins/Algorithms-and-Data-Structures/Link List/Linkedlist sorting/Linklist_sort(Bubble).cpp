#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>

struct list{
	int data;
	struct list *next;
};

typedef struct list node;

node *sort(node *);
void display(node *);

int main()
{
	node *start,*temp,*prev;
	int data,n;
	char ch;

	printf("Enter value to creat list : \n\n");
	start=NULL;
	while(1){
		printf("Do you want to creat a node? (y/n)\n");
		fflush(stdin);
		ch=getchar();
		if( toupper(ch)=='Y' ){
			printf("Enter a number: ");
			scanf("%d", &data);

			if(start==NULL){
				start = (node *)malloc(sizeof(node));
				start->data=data;
				start->next=NULL;
				prev=start;
			}

			else{
				temp = (node *)malloc(sizeof(node));
				temp->data=data;
				temp->next=NULL;
				prev->next=temp;
				prev=temp;
			}
		}
		else break;
	}
	printf("\nInputed order: ");
	display(start);
	printf("\nSorted Order: ");
	sort(start);
	display(start);

	getch();
	return 0;

}//end of main

void display(node *start){
	node *temp=start;

	printf("\nCreated list : ");

	while(temp!=NULL){
		printf("%d ", temp->data);
		temp=temp->next;
	}
	printf("\n");
}//End of function


/***********************SORTING FUNCTION**********************************/

node *sort(node *start){
	node *temp=start,*temp1;
	int temporary;

	while(temp!=NULL){
		temp1=start;

		while(temp1->next!=NULL){
			if(temp1->next->data < temp1->data){

				temporary=temp1->next->data;
				temp1->next->data=temp1->data;
				temp1->data=temporary;
			}
			temp1=temp1->next;
		}

		temp=temp->next;
	}
	return start;
}

/**********************SORTING FUNCTION END***************************/
