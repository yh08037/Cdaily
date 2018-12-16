#include <stdio.h>
#include <stdbool.h>

typedef struct{
	bool subject_distribution;	//주연:true 
	bool predicate_distribution;	//부주연:false 
}Categorical_Proposition;

typedef struct{
	Categorical_Proposition major_premise;	//대전제 
	Categorical_Proposition minor_premise;	//소전제 
	Categorical_Proposition conclusion;	//결론
	int figure;				//격식 
}syllogism;


Categorical_Proposition A = {true, false};	//전칭긍정명제 
Categorical_Proposition E = {true, true};	//전칭부정명제 
Categorical_Proposition I = {false, false};	//특칭긍정명제 
Categorical_Proposition O = {false, true};	//특칭부정명제 




int main(void){ 
	int i;
	
	printf("논증 식 : ");

	
	
	
	return 0;
}
