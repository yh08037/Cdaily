#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randomABCD(char *arr);

int mark(char *arr1, char *arr2);


int main(void)
{
	srand(time(NULL));
	
	int i, j, number;
	char right_answer[10];
	
	char **answer;
	
	
	printf("학생 수를 입력하세요. ");
	scanf("%d", &number);
	
	answer = (char**)malloc(sizeof(char*)*number);
	answer[0] = (char*)malloc(sizeof(char)*10*number);
	for(i=1; i<number; i++){
		answer[i] = answer[i-1]+10;
	}
	
	
	randomABCD(right_answer);
	
	printf("\n정답 : ");
	for(i=0; i<10; i++){
		printf("%c ", right_answer[i]);
	}
	printf("\n\n"); 

	for(i=0; i<number; i++){
		randomABCD(answer[i]);
		
		printf("학생%d : ", i+1);
		for(j=0; j<10; j++){
			printf("%c ", answer[i][j]);
		}
		printf("\n"); 
	}
	
	for(i=0; i<number; i++){
		printf("\n%d번째 학생의 점수는 %d점입니다.", i+1, mark(right_answer, answer[i]));
	}

	free(answer[0]);
	free(answer);

	return 0;
}


void randomABCD(char *arr){
	int i;
	
	for(i=0; i<10; i++){
		arr[i] = 'A' + rand()%5;
	}
}

int mark(char *arr1, char *arr2){
	int i, result=0;
	
	for(i=0; i<10; i++){
		if(arr1[i]==arr2[i]){
			result++;
		}
	}
	
	return result;
}
