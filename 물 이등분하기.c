#include <stdio.h>

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

int main(void)
{
	int a, b, c;

	printf("세 물통 A, B, C의 용량을 입력받습니다.\n\n");

	printf("A의 용량은 짝수이며, B의 용량은 A의 용량의 반보다 크거나 같으며, \nC의 용량은 A의 용량의 반보다 작거나 같습니다.\n\n");
		
	while(1){
		printf("A의 용량 : ");
		scanf("%d", &a);

		if(a%2==0){
			printf("\n");
			break;
		}

		printf("A의 용량은 짝수여야합니다. 다시 입력하세요.\n\n");
	}

	while(1){
		printf("B의 용량 : ");
		scanf("%d", &b);

		if(b>=a/2){
			printf("\n");
			break;
		}

		printf("B의 용량은 A의 용량의 반보다 크거나 같아야합니다. 다시 입력하세요.\n\n");
	}

	while(1){
		printf("C의 용량 : ");
		scanf("%d", &c);

		if(c<=a/2){
			printf("\n");
			break;
		}

		printf("C의 용량은 A의 용량의 반보다 작거나 같아야합니다. 다시 입력하세요.\n\n");
	}
	



	if(a/2 % gcd(b, c)){
		printf("가능한 방법이 존재하지 않습니다.\n");
	}

	


	int waterA=a, waterB=0, waterC=0, cnt=0;

	while(1){
		 waterA -= c;
		 waterC = c;
		 cnt++;

		 printf("%d단계 : 물통 A의 물을 물통 C에, 물통 C가 가득 찰 때까지 붓는다. (%d, %d, %d)\n", cnt, waterA, waterB, waterC);

		 while(1){
			waterC -= b - waterB;
			waterB = b;
			cnt++;

			if(waterC==0){
				printf("%d단계 : 물통 C의 물을 전부 물통 B에 붓는다. (%d, %d, %d)\n", cnt, waterA, waterB, waterC);
				break;
			}

			printf("%d단계 : 물통 C의 물을 물통 B에, 물통 B가 가득 찰 때까지 붓는다. (%d, %d, %d)\n", cnt, waterA, waterB, waterC);

			waterA += waterB;
			waterB = 0;
			cnt++;

			printf("%d단계 : 물통 B의 물을 전부 물통 A에 붓는다. (%d, %d, %d)\n", cnt, waterA, waterB, waterC);
		 }

		 if(waterB==waterA/2){
			 break;
		 }

	}
	

	return 0;
}
