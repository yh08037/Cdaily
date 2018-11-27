#include <stdio.h>


int gcd(int x, int y);

int main(void)
{
	int a, b, c;

	printf("�� ���� A, B, C�� �뷮�� �Է¹޽��ϴ�.\n\n");

	printf("A�� �뷮�� ¦���̸�, B�� �뷮�� A�� �뷮�� �ݺ��� ũ�ų� ������, \nC�� �뷮�� A�� �뷮�� �ݺ��� �۰ų� �����ϴ�.\n\n");

	while(1){
		printf("A�� �뷮 : ");
		scanf("%d", &a);
		
		if(a%2==0){
			printf("\n");
			break;
		}

		printf("A�� �뷮�� ¦�������մϴ�. �ٽ� �Է��ϼ���.\n\n");
	}

	while(1){
		printf("B�� �뷮 : ");
		scanf("%d", &b);

		if(b>=a/2){
			printf("\n");
			break;
		}

		printf("B�� �뷮�� A�� �뷮�� �ݺ��� ũ�ų� ���ƾ��մϴ�. �ٽ� �Է��ϼ���.\n\n");
	}

	while(1){
		printf("C�� �뷮 : ");
		scanf("%d", &c);

		if(c<=a/2){
			printf("\n");
			break;
		}

		printf("C�� �뷮�� A�� �뷮�� �ݺ��� �۰ų� ���ƾ��մϴ�. �ٽ� �Է��ϼ���.\n\n");
	}


	if(a/2 % gcd(b, c)){
		printf("������ ����� �������� �ʽ��ϴ�.\n");
		return 0;
	}


	int waterA=a, waterB=0, waterC=0, cnt=0;

	while(1){
		waterA -= c;
		waterC = c;
		cnt++;
				
		printf("%d�ܰ� : ���� A�� ���� ���� C��, ���� C�� ���� �� ������ �״´�. (%d, %d, %d)\n", cnt, waterA, waterB, waterC);
				
		while(1){
			if(waterB + waterC <= b){
				waterB += waterC;
				waterC = 0;
				cnt++;
						
				printf("%d�ܰ� : ���� C�� ���� ���� ���� B�� �״´�. (%d, %d, %d)\n", cnt, waterA, waterB, waterC);
				break;
			}
			 
			waterC -= b - waterB;
			waterB = b;
			cnt++;
					
			printf("%d�ܰ� : ���� C�� ���� ���� B��, ���� B�� ���� �� ������ �״´�. (%d, %d, %d)\n", cnt, waterA, waterB, waterC);
			
			waterA += waterB;
			waterB = 0;
			cnt++;
			
			printf("%d�ܰ� : ���� B�� ���� ���� ���� A�� �״´�. (%d, %d, %d)\n", cnt, waterA, waterB, waterC);		
		}
		
		if(waterA==waterB){
			break;
		}
	}

	return 0;

}

int gcd(int x, int y){
	int temp, i, result;

	if(x>y){
		temp = x;
		x = y;
		y= temp;
	}

	for(i=x; i>0; i--){
		if(x%i==0 && y%i==0){
			result = i;
			break;
		}
	}

	return result;
}
