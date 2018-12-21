#include <stdio.h>
#include <stdbool.h>

typedef struct{
	bool subjectDistribution;		//주어 (주연:true, 부주연:false)
	bool predicateDistribution;		//술어 (주연:true, 부주연:false) 
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


void GetSyllogism(Syllogism*);			//논증 식을 입력받아 저장합니다 
CategoricalProposition SetProposition(char);	//알파벳을 정언명제로 대입합니다 
bool UndistributedMiddle(Syllogism*);		//매개념 부주연의 오류 
bool IllicitMajor(Syllogism*);			//대개념 부당주연의 오류 
bool IllicitMinor(Syllogism*);			//소개념 부장주연의 오류 
bool ExclusivePremises(Syllogism*);		//양부정전제의 오류 
bool AffirmativeFromNegative(Syllogism*);	//부당긍정의 오류 
bool ExistentialFallacy(Syllogism*);		//존재가정의 오류 


int main(void){
	Syllogism input;
	
	printf("논증 식 : ");
	
	GetSyllogism(&input);
	 
	printf("%d", ExclusivePremises(&input));
	
	
	return 0;
}


void GetSyllogism(Syllogism* syllogism){
	syllogism->majorPremise = SetProposition(getchar());
	syllogism->minorPremise = SetProposition(getchar());
	syllogism->conclusion = SetProposition(getchar());
	getchar();
	scanf("%d", &(syllogism->figure));
	getchar();
}

CategoricalProposition SetProposition(char chr){
	if(chr=='A') return A;
	else if(chr=='E') return E;
	else if(chr=='I') return I;
	else if(chr=='O') return O;
}

/*매개념 부주연의 오류*/
bool UndistributedMiddle(Syllogism* syllogism){
	switch (syllogism->figure){
		case 1:
		case 2:
		case 3:
		case 4:
	}
} 

/*대개념 부당주연의 오류*/
bool IllicitMajor(Syllogism* syllogism){
	
}

/*소개념 부당주연의 오류*/
bool IllicitMinor(Syllogism* syllogism){
	
}

/*양부정전제의 오류*/
bool ExclusivePremises(Syllogism* syllogism){
	if(syllogism->majorPremise.predicateDistribution){
		if(syllogism->minorPremise.predicateDistribution){
			return true;
		}	
		else return false;
	}
	else return false;
}

/*부당긍정의 오류*/
bool AffirmativeFromNegative(Syllogism* syllogism){
	if(syllogism->majorPremise.predicateDistribution||syllogism->minorPremise.predicateDistribution){
		if(!(syllogism->conclusion.predicateDistribution)){
			return true;
		}
		else return false;
	}
	else return false;
}

/*존재가정의 오류*/
bool ExistentialFallacy(Syllogism* syllogism){
	if(syllogism->majorPremise.subjectDistribution){
		if(syllogism->minorPremise.subjectDistribution){
			if(!(syllogism->conclusion.subjectDistribution)){
				return true;
			}
			else return false;
		}
		else return false;
	}
	else return false;
}
