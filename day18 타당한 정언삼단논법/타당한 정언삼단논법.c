#include <stdio.h>
#include <stdbool.h>

typedef struct{
	bool subjectDistribution;		//주어 주연:true, 부주연:false  
	bool predicateDistribution;		//술어 주연:true, 부주연:false 
}CategoricalProposition;

typedef struct{
	CategoricalProposition majorPremise;	//대전제 
	CategoricalProposition minorPremise;	//소전제 
	CategoricalProposition conclusion;	//결론
	int figure;				//격식 
}Syllogism;


CategoricalProposition A = {true, false};	//전칭긍정명제 
CategoricalProposition E = {true, true};	//전칭부정명제 
CategoricalProposition I = {false, false};	//특칭긍정명제 
CategoricalProposition O = {false, true};	//특칭부정명제 


CategoricalProposition SetProposition(char);

int main(void){ 
	int i;
	Syllogism input;
	char temp;
	
	printf("논증 식 : ");
	input.majorPremise = SetProposition(getchar());
	input.minorPremise = SetProposition(getchar());
	input.conclusion = SetProposition(getchar());
	getchar();
	scanf("%d", &input.figure);
	
	
	
	return 0;
}


CategoricalProposition SetProposition(char chr){
	if(chr=='A') return A;
	else if(chr=='E') return E;
	else if(chr=='I') return I;
	else if(chr=='O') return O;
}
