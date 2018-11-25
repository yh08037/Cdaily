#include <stdio.h>

int main(void)
{
	int i, j, cnt=1, result, Is_break=0;
	
	int a[35][35], b[35][35];
	
	for(i=0; i<35; i++){
		for(j=0; j<35; j++){
			a[i][j] = cnt;
			cnt++;
		}
	}
	
	cnt = 1;
	for(i=0; i<2*35-1; i++){
		if(i<35){
			for(j=i; j>=0; j--){
				b[j][i-j] = cnt;
				cnt++;
			}
		}
		else{
			for(j=34; j>i-35; j--){
				b[j][i-j] = cnt;
				cnt++;
			}
		}
	}

	for(i=0; i<35; i++){
		for(j=0; j<35; j++){
			if(a[i][j]==b[i][j]){
				printf("f(%d) = %d\n", b[i][j], a[i][j]);
			}
		}
	}
	
	
	return 0;
}
