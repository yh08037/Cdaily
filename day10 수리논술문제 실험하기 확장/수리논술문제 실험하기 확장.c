#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int g(int **a, int **b, int n);

int main(void)
{
	int input, i, n;
	
	printf("input : ");
	scanf("%d", &input);
	
	int **a, **b;
	
	a = (int**)malloc(sizeof(int*)*input);
	a[0] = (int*)malloc(sizeof(int)*input*input);
	for(i=1; i<input; i++){
		a[i] = a[i-1] + input;
	}
	
	b = (int**)malloc(sizeof(int*)*input);
	b[0] = (int*)malloc(sizeof(int)*input*input);
	for(i=1; i<input; i++){
		b[i] = b[i-1] + input;
	}
	
	for(i=1; i<=input; i++){
		printf("%d ",g(a, b, i));
	}
	
	
	free(a[0]);
	free(a);
	free(b[0]);
	free(b);
	
	return 0;
}

int g(int **a, int **b, int n){
	int i, j, cnt=1;
	
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			a[i][j] = cnt;
			cnt++;
		}
	}
	
	cnt = 1;
	for(i=0; i<2*n-1; i++){
		if(i<n){
			for(j=i; j>=0; j--){
				b[j][i-j] = cnt;
				cnt++;
			}
		}
		else{
			for(j=n-1; j>i-n; j--){
				b[j][i-j] = cnt;
				cnt++;
			}
		}
	}
	
	
	cnt = 0;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if(a[i][j]==b[i][j]){
				cnt++;
			}
		}
	}
	
	
	if(n%2){
		cnt++;
	}
	
	return cnt;
}
	
