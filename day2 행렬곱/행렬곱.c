#include <stdio.h>

int main(void)
{
	int p, q, r, s;
	
	printf("��� A\n");
	
	printf("�� ���� : ");
	scanf("%d", &p);
	
	printf("�� ���� : ");
	scanf("%d", &q); 
	
	printf("���A�� ���� %d���� �Է��ϼ���.\n", p*q); 
	
	int i, j, k, a[100][100];
	
	for(i=0; i<p; i++)
	{
		for(j=0; j<q; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	
	printf("\n��� B\n");
	
	printf("�� ���� : ");
	scanf("%d", &r);
	
	printf("�� ���� : ");
	scanf("%d", &s);
	
	if(q != r)
	{
		printf("�� ����� ���� ���ǵ��� �ʽ��ϴ�.\n");
		
		return 0;
	}
	
	printf("���B�� ���� %d���� �Է��ϼ���.\n", r*s); 
	
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
	
	printf("\n�� ����� �� AxB��\n");
	
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
