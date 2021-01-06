#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct orthogonal {
	int row, col, data;
	struct orthogonal *right;
	struct orthogonal *down;
};

typedef struct orthogonal node;

node *prev_row, *prev_col, *prev;

node *creat(node *, int, int, int);
void display(node *);
void transpose_display(node *);

int main(){
	node *start=NULL;
	int value, m, n, i, j;
	
	printf("Enter the size of matrix : \nRow : ");
	scanf("%d", &m);
	printf("Collum : ");
	scanf("%d", &n);

	for(i=1; i<=m; i++){
		for(j=1; j<=n; j++){
			fflush(stdout);
			printf("Enter value(%d*%d) : ", i,j);
			fflush(stdin);
			scanf("%d", &value);
			start=creat(start, value, i, j);
		}
	}
	printf("\n\nMatrix : \n");
	display(start);
	printf("\n\nTranspose Matrix : \n");
	transpose_display(start);

	getch();
	return 0;
}//end of main

node *creat(node *start, int data, int row, int col){
	node *temp;

	if(start==NULL){
		start=(node *)malloc(sizeof(node));
		start->data=data;
		start->row=row;
		start->col=col;
		start->right=NULL;
		start->down=NULL;
		prev_row=start;
		prev_col=start;
	}

	else{
		temp=(node *)malloc(sizeof(node));
		temp->data=data;
		temp->row=row;
		temp->col=col;
		temp->right=NULL;
		temp->down=NULL;
		
		if(row==1){
			prev_col->right=temp;
			prev_col=temp;
		}

		else{
			if(col==1){
				prev=prev_row->right;
				prev_row->down=temp;
				prev_row=temp;
				prev_col=temp;
			}
			else{
				prev_col->right=temp;
				prev_col=temp;
				prev->down=prev_col;
				prev=prev->right;
			}
		}
	}
	return start;
}//end of creat

void display(node *start){
	node *temp_col=start, *temp_row=start;

	while(temp_row!=NULL){
		while(temp_col!=NULL){
			printf("%d ", temp_col->data);
			temp_col=temp_col->right;
		}
		printf("\n");
		temp_row=temp_row->down;
		temp_col=temp_row;
	}
	return;
}//end of display

void transpose_display(node *start){
	node *temp_col=start, *temp_row=start;

	while(temp_col!=NULL){
		while(temp_row!=NULL){
			printf("%d  ", temp_row->data);
			temp_row=temp_row->down;
		}
		printf("\n");
		temp_col=temp_col->right;
		temp_row=temp_col;
	}
	return;
}//end of transpose_display