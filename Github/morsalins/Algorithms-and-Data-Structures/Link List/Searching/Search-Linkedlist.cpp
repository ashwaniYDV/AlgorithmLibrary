#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>

struct list{
    int data;
    struct list *next;
};

typedef struct list node;

void display(node *head);
int search_list(node *head);

int main(void){
    node *start,*prev,*temp;
    char ans, ch;
	int flag;

    start=NULL;
    do{
        fflush(stdout);
        printf("Do u want to creat a node(Y/N):=");

		fflush(stdin);
		scanf("%c", &ch);

		ans=toupper(ch);

        if(ans=='Y'){
            if(start==NULL){
                start=(node*)malloc(sizeof(node));
                fflush(stdout);
                printf("\nEnter data :=");
                fflush(stdin);
                scanf("%d",&start->data);
                start->next=NULL;
                prev=start;
            }
            else{
                temp=(node*)malloc(sizeof(node));
                fflush(stdout);
                printf("\nEnter data:=");
                fflush(stdin);
                scanf("%d",&temp->data);
                temp->next=NULL;
                prev->next=temp;
                prev=temp;
            }
        }
		printf("\n");
	}while(ans=='Y');

    display(start);

	flag = search_list(start);
	
	if(flag==1)printf("\nItem found in linked list");
	else if(flag==2)printf("\nThere is no linked list");
	else printf("\nItem not found in linked list");
	
	getch();
    return 0;
}
void display(node *head){
    node *temp;
    printf("\nCreated list :=");
    temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    return;
}

int search_list(node *head){
	node *temp=head;
	int item;
	
	printf("\n\nEnter an item to search : ");
	scanf("%d", &item);
	
	if(temp==NULL)return 2;
	
	else{
		while(temp!=NULL){
			if(temp->data==item)
			return 1;
		
		else temp = temp->next;
			
		}return 0;
	}//End of else

}//End of function