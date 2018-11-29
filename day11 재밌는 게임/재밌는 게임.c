#include <stdio.h>

void printResult(char *arr);

float Arithmetics(int x, int y, int number);

int main(void)
{
	int i, j, num;
	char input[4];

	printf("number of test case : ");
	scanf("%d", &num);
	getchar();

	for(i=0; i<num; i++){
		printf("%d. ", i+1);
		for(j=0; j<4; j++){
			scanf("%c", input+j);
		}
		getchar();
		printResult(input);
		printf("\n");
	}


	return 0;
}

void printResult(char *arr){
	int a, b, c, d, i, j, existance=0;
	char op[] = {'+', '-', '*', '/'};

	a = arr[0] - '0';
	b = arr[1] - '0';
	c = arr[2] - '0';
	d = arr[3] - '0';

	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			if(Arithmetics(a, b, i)==Arithmetics(c, d, j)){
				printf("%c %c\n", op[i], op[j]);
				existance = 1;
			}
		}
	}
	
	if(existance==0){
		printf("does not exist\n");
	}
}

float Arithmetics(int x, int y, int number){
	float result;
	switch (number){
		case 0: result = x + y; break;
		case 1: result = x - y; break;
		case 2: result = x * y; break;
		case 3: result = (float)x / y; break;
	}
	return result;
}


/*
10
3492
5028
4122
6987
8420
9012
8173
3596
9385
2659
*/
