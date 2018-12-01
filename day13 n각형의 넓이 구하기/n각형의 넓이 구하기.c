#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int x;
	int y;
}POINT;

double Area_Polygon(int len, POINT *str);

int main(void){

	int numberA, numberB, i;
	POINT *locationA, *locationB;
	double areaA, areaB;

	printf("A의 꼭짓점의 개수 : ");
	
	scanf("%d", &numberA);

	locationA = (POINT*)malloc(sizeof(POINT)*numberA);


	for(i=0; i<numberA; i++){
		printf("%d번째 점 : ", i+1); 
		scanf("%d", &(locationA+i)->x);
		scanf("%d", &(locationA+i)->y);
	}

	
	printf("\nB의 꼭짓점의 개수 : ");

	scanf("%d", &numberB);

	locationB = (POINT*)malloc(sizeof(POINT)*numberB);


	for(i=0; i<numberB; i++){
		printf("%d번째 점 : ", i+1); 
		scanf("%d", &(locationB+i)->x);
		scanf("%d", &(locationB+i)->y);
	}	
		

	areaA = Area_Polygon(numberA, locationA);
	areaB = Area_Polygon(numberB, locationB);

	printf("\nA의 영역 : %.1lf\nB의 영역 : %.1lf\n\n", areaA, areaB);
	
	
	if(areaA>areaB){
		printf("A의 영역의 넓이가 더 큽니다.\n");
	}
	else if(areaA<areaB){
		printf("B의 영역의 넓이가 더 큽니다.\n");
	}
	else{
		printf("A와 B의 영역의 넓이는 같습니다.\n");
	}
	

	free(locationA);
	free(locationB);


	return 0;
}

double Area_Polygon(int len, POINT *arr){
	int i;
	double sum=0;

	for(i=0; i<len-1; i++){
		sum += (arr+i)->x * (arr+i+1)->y - (arr+i+1)->x * (arr+i)->y;
	}
	sum += (arr+len-1)->x * (arr)->y - (arr)->x * (arr+len-1)->y;
	
	if(sum<0){
		sum = -sum;
	} 
		
	return sum/2;
}
