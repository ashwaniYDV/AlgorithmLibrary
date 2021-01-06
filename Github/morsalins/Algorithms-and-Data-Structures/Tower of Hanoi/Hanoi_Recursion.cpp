#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void hanoi(int,int,int,int);

int main(void){
	int n;

	printf("How many disks : ");
	scanf("%d", &n);

	hanoi(n,1,2,3);

	getch();
	return 0;
}

void hanoi(int disks, int firstpole, int temppole, int lastpole){

	if(disks==1)
		printf("\n\nMove disk #%d   -->   From pole %d to pole %d", disks, firstpole, lastpole);
	
	else
	{
		hanoi(disks-1, firstpole, lastpole, temppole);
		printf("\n\nMove disk #%d   -->   From pole %d to pole %d", disks, firstpole, lastpole);
		hanoi(disks-1, temppole, firstpole, lastpole);
	}
	return;
}