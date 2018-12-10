#include <stdio.h>
#include <stdlib.h>

void PUSH(int X);
void POP();
void SIZE();
void EMPTY();
void TOP();

int *stack, size=0;


int main(void){
	
	stack = malloc(sizeof(int)*10000);

	int num, i, X, cnt;
	char temp;

	scanf("%d", &num);
	getchar();

	for(i=0; i<num; i++){
		char command[8]="";
		cnt=0;		
		while(1){
			temp = getchar();
			if(temp==' '||temp=='\n'){
				break;
			}
			command[cnt] = temp;
			cnt++;
		}
		
		if(!strcmp(command, "push")){
			scanf("%d", &X);
			getchar();
			PUSH(X);
		}		
		else if(!strcmp(command, "pop")){
			POP();
		}
		else if(!strcmp(command, "size")){
			SIZE();
		}
		else if(!strcmp(command, "empty")){
			EMPTY();
		}
		else if(!strcmp(command, "top")){
			TOP();
		}
	}

	free(stack);

	return 0;
}



void PUSH(int X){

	stack[size++] = X;
}

void POP(){
	if(size){
		printf("%d\n", stack[(size--)-1]);
	}
	else{
		printf("%d\n", -1);
	}
}

void SIZE(){
	printf("%d\n", size);
}

void EMPTY(){
	if(size){
		printf("%d\n", 0);
	}
	else{
		printf("%d\n", 1);
	}
}

void TOP(){
	if(size){
		printf("%d\n", stack[size-1]);
	}
	else{
		printf("%d\n", -1);
	}
}
//갓
