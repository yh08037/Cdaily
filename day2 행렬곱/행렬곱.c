#include <stdio.h>

int main(void)
{
	int p, q, r, s;
	
	printf("행렬 A\n");
	
	printf("행 개수 : ");
	scanf("%d", &p);
	
	printf("열 개수 : ");
	scanf("%d", &q); 
	
	printf("행렬A의 성분 %d개를 입력하세요.\n", p*q); 
	
	int i, j, k, a[100][100];
	
	for(i=0; i<p; i++)
	{
		for(j=0; j<q; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	
	printf("\n행렬 B\n");
	
	printf("행 개수 : ");
	scanf("%d", &r);
	
	if(q != r)
	{
		printf("두 행렬의 곱이 정의되지 않습니다.\n");
		
		return 0;
	}
	
	printf("열 개수 : ");
	scanf("%d", &s);
	
	printf("행렬B의 성분 %d개를 입력하세요.\n", r*s); 
	
	int b[100][100];
	
	for(i=0; i<r; i++)
	{
		for(j=0; j<s; j++)
		{
			scanf("%d", &b[i][j]);
		}
	}
	
	int c[100][100]={0,};
	
	for(i=0; i<p; i++)
	{
		for(j=0; j<s; j++)
		{	
			for(k=0; k<q; k++)
			{
				c[i][j] += a[i][k] * b[k][j]; 
			}
		}
	}
	
	printf("\n두 행렬의 곱 AxB는\n");
	
	for(i=0; i<p; i++)
	{
		for(j=0; j<s; j++)
		{
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
