#include <stdio.h>
#include <stdbool.h>

typedef struct{
	bool subjectDistribution;		//주연:true 
	bool predicateDistribution;		//부주연:false 
}CategoricalProposition;

typedef struct{
	CategoricalProposition major_premise;	//대전제 
	CategoricalProposition minor_premise;	//소전제 
	CategoricalProposition conclusion;	//결론
	int figure;				//격식 
}syllogism;


CategoricalProposition A = {true, false};	//전칭긍정명제 
CategoricalProposition E = {true, true};	//전칭부정명제 
CategoricalProposition I = {false, false};	//특칭긍정명제 
CategoricalProposition O = {false, true};	//특칭부정명제 


void SetProposition(char);


int main(void){ 
	int i;
	char temp[6];
	syllogism input;
	
	printf("논증 식 : ");
	gets(temp);
	
	
	return 0;
}


void SetProposition(char chr){
	if(chr=='A')
	else if(chr=='E')
	else if(chr=='I')
	else if(chr=='O')
	else
}
