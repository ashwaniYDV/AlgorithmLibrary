#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

struct doubly_list{
	int data;
	struct doubly_list *prev, *next;
};

typedef struct doubly_list node;

node *previous; // Global variable for creat list

node *creat_list(int, node *);
node *ascending_insertion(int, node *);
node *descending_insertion(int, node *);
void display(node *);
void rev_display(node *);
node *insert_begin(int, node *);
node *insert_after(int, int, node *);
node *deletion(int, node *);
int node_count(node *);

int main(void){
	node *start;
	int i, n, choice, data, item;
	char ans;

	start=NULL;

	printf("\n\t     ###########################################\n");
	printf("\t     ##\t1.Creat list     2.Sorted insertion   ##\n\t     ##\t3.Display        4.Insert at begin    ##\n\t     ##\t5.Insert after   6.Deletion           ##\n\t     ##\t7.Node counting  #.Any others to exit ##\n");
	printf("\t     ###########################################\n");

	while(1){
		fflush(stdout);
		printf("\nEnter your choice (1-7): ");
		fflush(stdin);
		scanf("%d", &choice);

		if(choice==1){
			fflush(stdout);
			printf("\nDo you want to creat a list (y/n) : ");
			fflush(stdin);
			ans = toupper(getchar());

			if(ans=='Y'){
				fflush(stdout);
				printf("\nHow many numbers :  ");
				fflush(stdin);
				scanf("%d", &n);
				fflush(stdout);
				printf("\n");

				for(i=1; i<=n; i++){
					fflush(stdout);
					printf("Number %d :  ", i);
					fflush(stdin);
					scanf("%d", &data);
					start = creat_list(data, start);
				} // end of for
			} // end of if ans==Y

			else continue;

		} // end of 1st if choice==1

		else if(choice==2) {
			while(1){
				fflush(stdout);
				printf("\n    Press =>> 'a' for ascending order or 'd' for descending order insertion\n");
				fflush(stdout);
				printf("\nEnter your choice (a/d): ");
				fflush(stdin);
				ans = toupper( getchar() );
				if(ans=='A'){
					fflush(stdout);
					printf("\nHow many numbers : ");
					fflush(stdin);
					scanf("%d", &n);
					for(i=1; i<=n; i++){
						fflush(stdout);
						printf("Number %d : ", i);
						fflush(stdin);
						scanf("%d", &data);
						start = ascending_insertion(data, start);
					}break; //end of for loop
				}//end of if
				else if(ans=='D'){
					fflush(stdout);
					printf("\nHow many numbers : ");
					fflush(stdin);
					scanf("%d", &n);
					for(i=1; i<=n; i++){
						fflush(stdout);
						printf("Number %d : ", i);
						fflush(stdin);
						scanf("%d", &data);
						start = descending_insertion(data, start);
					}break; //end of for loop
				}//end of else if
				else{
					fflush(stdout);
					printf("\nWRONG!!!!!\n");continue;
				}
			}//end of while
		}//end of else if choice==2

		else if(choice==3) {
			while(1){
				fflush(stdout);
				printf("\n    Press =>> 'd' for Normal Order Display or 'r' for Reverse Order Display\n");
				fflush(stdout);
				printf("\nEnter your choice (d/r): ");
				fflush(stdin);
				ans=toupper( getchar() );

				if(ans=='D') {display(start);break;}
				else if(ans=='R') {rev_display(start);break;}
				else{
					fflush(stdout);
					printf("\nWRONG!!!!!!\n");
					continue;
				}
			} //end of while
		}// end of else if choice==3

		else if(choice==4){
			fflush(stdout);
			printf("\nEnter a number to insert at begin : ");
			fflush(stdin);
			scanf("%d", &data);
			start = insert_begin(data, start);
		} // end of else if choice==4

		else if(choice==5){
			fflush(stdout);
			printf("\nEnter a number to insert after : ");
			fflush(stdin);
			scanf("%d", &data);
			fflush(stdout);
			printf("After which number : ");
			fflush(stdin);
			scanf("%d", &item);

			start = insert_after(data, item, start);
		}//end of else if choice==5

		else if(choice==6){
			fflush(stdout);
			printf("\nEnter a number to delete : ");
			fflush(stdin);
			scanf("%d", &data);

			start = deletion(data, start);
		}// end of else if choice==6

		else if(choice==7){
			n = node_count(start);
			printf("\nTotal Nodes : %d\n", n);
		}

		else{
			fflush(stdout);
			printf("\n\t\t\tDo you want to Exit (y/n) : ");
			fflush(stdin);
			ans=toupper( getchar() );
			if( ans=='Y' ){
				fflush(stdout);
				printf("\n\n\t\t\t   ..........END..........\n\n");
				break;
			}
			else continue;
		}// end of else

	}// end of while

	getch();
	return 0;

}// end of main function

node *creat_list(int data, node *start){
	node *temp;

	if(start==NULL){
		start=(node *)malloc(sizeof(node));
		previous=start;
		start->data=data;
		start->next=NULL;
		start->prev=NULL;

	}// end of if

	else{
		temp=(node *)malloc(sizeof(node));
		temp->data=data;
		temp->next=NULL;
		previous->next=temp;
		temp->prev=previous;
		previous=temp;
	}// end of else

	return start;
}// end of creat_list function

node *ascending_insertion(int data, node *start){
	node *temp, *temp1;

    if(start==NULL){
        start=(node *)malloc(sizeof(node));
        start->data=data;
        start->next=NULL;
        start->prev=NULL;
    }

    else if(start->data>=data){
        temp=(node *)malloc(sizeof(node));
        temp->data=data;
        temp->next=start;
        start->prev=temp;
        temp->prev=NULL;
        start=temp;
    }

    else{
        temp=start;
        while( (temp->next!=NULL) && (temp->next->data<=data) )
            temp=temp->next;

        temp1=(node *)malloc(sizeof(node));
        temp1->data=data;
        temp1->next=temp->next;
        if(temp->next!=NULL)
                temp->next->prev=temp1;
        temp->next=temp1;
        temp1->prev=temp;
    }
	return start;
}

node *descending_insertion(int data, node *start){
	node *temp, *temp1;

    if(start==NULL){
        start=(node *)malloc(sizeof(node));
        start->data=data;
        start->next=NULL;
        start->prev=NULL;
    }

    else if(start->data<=data){
        temp=(node *)malloc(sizeof(node));
        temp->data=data;
        temp->next=start;
        start->prev=temp;
        temp->prev=NULL;
        start=temp;
    }

    else{
        temp=start;
        while( (temp->next!=NULL) && (temp->next->data>=data) )
            temp=temp->next;

        temp1=(node *)malloc(sizeof(node));
        temp1->data=data;
        temp1->next=temp->next;
        if(temp->next!=NULL)
                temp->next->prev=temp1;
        temp->next=temp1;
        temp1->prev=temp;
    }
	return start;
}

void display(node *start){
	node *temp=start;

	printf("\nDisplaying list : ");

	if(temp==NULL) printf("No linked list\n");

	else{
		while(temp!=NULL){
			printf(" %d", temp->data);
			temp=temp->next;
		}
	}//end of else

	printf("\n\n\t\t\t.......Press any key to continue.......\n");
	getch();
	return;
}// end of display function

void rev_display(node *start){
	node *temp=start;

	printf("\nReverse Display : ");

	if(temp==NULL) {
		printf("No linked list\n");
		return;
	}

	while(temp->next!=NULL) temp=temp->next; // searching for last node & naming it as temp

	while(temp!=NULL){             // start from last node & printing it through reverse order
		printf(" %d", temp->data);
		temp=temp->prev;
	}
	printf("\n\n\t\t\t.......Press any key to continue.......\n");
	getch();
	return;
}// end of reverse display function

node *insert_begin(int data, node *start){
	node *temp=(node *)malloc(sizeof(node));

	temp->data=data;
	temp->next=start;
	start->prev=temp;
	temp->prev=NULL;

	return temp;
}

node *insert_after(int data, int item, node *start){
	node *temp=start, *temp1;

	if(temp==NULL) {
		printf("\nNo linked list\n");
		return start;
	}

	while( (temp!=NULL) && (temp->data!=item) )
		temp=temp->next;

	if(temp==NULL) printf("\nNo such item found to insert after\n");

	else{
		temp1=(node *)malloc(sizeof(node));
		temp1->data=data;
		temp1->next=temp->next;
		if(temp->next!=NULL)
			temp->next->prev=temp1;
		temp->next=temp1;
		temp1->prev=temp;
	}

	return start;
}// end of insert_after funcion

node *deletion(int data, node *start){
	node* temp=start;

	if(temp==NULL) printf("\nNo linked list\n");

	else if(start->data==data){
		start=start->next;
		start->prev=NULL;
		free(temp);
	}

	else{
		while( (temp!=NULL) && (temp->data!=data) )
			temp=temp->next;

		if(temp==NULL) printf("\nNo such item found to Delete\n");

		else{
			temp->prev->next=temp->next;
			if(temp->next!=NULL)
				temp->next->prev=temp->prev;
			free(temp);
		}
	}//end of else

	return start;
}//end of deletion function

int node_count(node *start){
	int count=0;
	node *temp=start;

	while(temp!=NULL){
		count++;
		temp=temp->next;
	}
	return count;
}//end of node_count function


