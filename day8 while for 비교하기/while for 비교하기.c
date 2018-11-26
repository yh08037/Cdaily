#include <stdio.h>
#include <time.h>
  

double mean(double *arr, int num){
	int i;
	double sum=0; //오버플로우?안나겠지 
	for(i=0; i<num; i++){
		sum += arr[i];
	}
	return sum/num;
}
 
int main(void)
{
	clock_t clock(void);
	double time1, time2, *time_while, *time_for;
	
	int i=0, cnt=0, input;
	long long int total=0;
	
	scanf("%d", &input);
	
	time_while = (double*)malloc(sizeof(double)*input);
	
	time_for = (double*)malloc(sizeof(double)*input);
	
	while(cnt<input){
		
		
		total = 0;
			
		
		time1 = clock();
		
		i=0;
		while(i<=100000000){
			total += i;
			i++;
		}
		
		time2 = clock();
		
		
		
		
		printf("%lf\n", (time2-time1)/1000);
		
		time_while[cnt] = (time2-time1)/1000;
		
		
		total = 0;
				
		
		
		time1 = clock();
		
		for(i=0; i<=100000000; i++){
			total += i;
		}
		
		time2 = clock();
		
		
		
		time_for[cnt] = (time2-time1)/1000;
		
		
		printf("%lf\n", (time2-time1)/1000);
		
		printf("\n");
		
		cnt++;
		
	}
	 
	 
	printf("while 평균 : %lf\n", mean(time_while, input));
	
	printf("for 평균 : %lf\n", mean(time_for, input));
	
	
	free(time_while);

	free(time_for);	
	
	return 0; 
} 
