#include <stdio.h>

int main(void){
	int i, j, k, n1, n2;
	
	scanf("%d %d", &n1, &n2);
	
	for(i=0; i<=n1/2; i++){
		for(k=0; k<n2; k++){	
			for(j=0; j<i; j++){
				printf(" ");
			}
			for(j=0; j<n1-2*i; j++){
				printf("*");
			}
			for(j=0; j<i; j++){
				printf(" ");
			}
			printf("  ");
		}
		printf("\n");
	}
	for(i=n1/2-1; i>=0; i--){
		for(k=0; k<n2; k++){	
			for(j=0; j<i; j++){
				printf(" ");
			}
			for(j=0; j<n1-2*i; j++){
				printf("*");
			}
			for(j=0; j<i; j++){
				printf(" ");
			}
			printf("  ");
		}
		printf("\n");
	}
	
	return 0;
}
