#include <stdio.h>
#include <math.h>

double arithmetic_mean(int * arr, int num);

double standard_deviation(int * arr, int num);

int main(void){
	int num, i, arr[100];
	
	scanf("%d", &num);
	
	for(i=0; i<num; i++){
		scanf("%d", arr+i);
	}
	
	printf("%lf\n", arithmetic_mean(arr, num));

	printf("%lf\n", standard_deviation(arr, num));
		
	
	return 0;
}

double arithmetic_mean(int * arr, int num){
	double result=0;
	int i;

	for(i=0; i<num; i++){
		result += arr[i];
	}

	result /= num;

	return result;
}

double standard_deviation(int * arr, int num){
	double result=0, mean;
	int i;

	mean = arithmetic_mean(arr, num);

	for(i=0; i<num; i++){
		result += (arr[i]-mean)*(arr[i]-mean);
	}

	result = sqrt(result/num);
	
	return result;	
}