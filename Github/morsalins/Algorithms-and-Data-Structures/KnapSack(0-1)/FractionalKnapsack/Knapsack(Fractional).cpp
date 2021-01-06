#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

float profit[100],weight[100],unitprofit[100],proportion[100];

float knapsack(int,int);

int main(){
	int i,objects,capacity;
	float total_proft;

	printf("How much capacity: ");
	scanf("%d", &capacity);

	printf("How many objects: ");
	scanf("%d", &objects);

	printf("Enter weight & profit of every object-\n\n");

	for(i=0; i<objects; i++){
		printf("#Object %d:\n", i+1);
		printf("   Weight: ");
		scanf("%f", &weight[i]);
		printf("   Profit: ");
		scanf("%f", &profit[i]);
	}

	for(i=0;i<objects;i++){
		unitprofit[i]=profit[i]/weight[i];
	}

	/**********Sorting the Unitprofit**********/
	for(int j=0; j<objects-1; j++){
        for(i=0; i<objects-j-1; i++){
            if(unitprofit[i] < unitprofit[i+1]){

				int temp=unitprofit[i];
				unitprofit[i]=unitprofit[i+1];
				unitprofit[i+1]=temp;
				/*********Swap Unitprofit*******/

				temp=weight[i];
				weight[i]=weight[i+1];
				weight[i+1]=temp;
				/*********Swap Weight**********/

				temp=profit[i];
				profit[i]=profit[i+1];
				profit[i+1]=temp;
				/*********Swap Profit**********/
            }
        }
	}

	total_proft=knapsack(capacity,objects);

	printf("\n\nTotal Profit : %.2f ", total_proft);

	getch();
	return 0;
}


float knapsack(int capacity, int objects){
	int i;
	float p=0.0;

	for(i=0;i<objects;i++)
		proportion[i]=0.0;

	int emptyspace=capacity;

	for(i=0; i<objects;i++){
		if(weight[i]>emptyspace) break;

		proportion[i]=1;
		emptyspace=emptyspace-weight[i];
	}

	if(i<=objects)
		proportion[i]=emptyspace/weight[i];

	printf("\n");
	for(int j=0; j<=i; j++){
		p = p + (profit[j]*proportion[j]);
		printf("%.2f  " ,proportion[j]);
	}

	return p;
}



