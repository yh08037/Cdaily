#include <stdio.h>

int main(void)
{
	int a[35][35], i, j, n, cnt, result, Is_break=0;
	
	cnt = 1;
	for(i=0; i<35; i++){
		for(j=0; j<35; j++){
			a[i][j] = cnt;
			cnt++;
		}
	}
	
	printf("n : ");
	
	scanf("%d", &n);
	
	
	cnt = 1;
	
	for(i=0; i<2*35-1; i++){
		if(i<35){
			for(j=i; j>=0; j--){
				if(cnt==n){
					result = a[j][i-j];
					Is_break = 1;
					break;
				}
				cnt++;
			}
			if(Is_break){
				break;
			}
		}
		else{
			for(j=34; j>i-35; j--){
				if(cnt==n){
					result = a[j][i-j];
					Is_break = 1;
					break;
				}
				cnt++;
			}
			if(Is_break){
				break;
			}
		}
	}
	
	printf("f(%d) = %d", n, result);
	
	
	return 0;
}
