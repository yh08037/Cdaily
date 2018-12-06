#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct{
	char name[20];
	int turn;
	int point;
}PLAYER;

int main(void){
	srand(time(NULL));

	int number, i, cnt, temp, result;

	const int goal = rand()%301;

	printf("goal : %d\n", goal);

	printf("player number : ");
	scanf("%d", &number);
	printf("\n");

	PLAYER * list;

	list = (PLAYER*)malloc(sizeof(PLAYER)*number);

	printf("put player names\n");

	for(i=0; i<number; i++){
		scanf("%s", &(list+i)->name);
		getchar();
	}

	printf("\n");

	for(i=0; i<number; i++){
		cnt = 1;
		result = 100;
		printf("%s's turn\n", (list+i)->name);

		while(1){
			printf("turn %d : ", cnt);
			scanf("%d", &temp);
			if(abs(temp-goal)<=15){
				printf("ok.");
				(list+i)->turn = cnt;
				(list+i)->point = result;
				break;
			}
			if(result>0){
				result -= 10;
			}
			if(temp < goal){
				printf("up\n");
			}
			else if(temp > goal){
				printf("down\n");
			}
			cnt++;
		}

		printf("\n\n");

	}

	printf("name\tturn\tpoint\n");

	for(i=0; i<number; i++){
		printf("%4s\t%4d\t%5d\n", (list+i)->name, (list+i)->turn, (list+i)->point);
	}


	free(list);
	
	return 0;
}
