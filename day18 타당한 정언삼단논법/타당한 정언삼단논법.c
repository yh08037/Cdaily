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
bool IllicitAffirmation(Syllogism*);		//부당긍정의 오류 
bool ExistentialFallacy(Syllogism*);		//존재가정의 오류 


int main(void){
	/*
	Syllogism input;
	
	printf("논증 식 : ");
	
	GetSyllogism(&input);
	*/
	
	int i, j, k, l, m, cnt, cntValid=0;
	char temp[] = "AEIO";
	Syllogism input;
	bool fallacyTable[6]; 
	
	for(i=0; i<4; i++){
		input.majorPremise = SetProposition(temp[i]);		
		for(j=0; j<4; j++){
			input.minorPremise = SetProposition(temp[j]);
			for(k=0; k<4; k++){
				input.conclusion = SetProposition(temp[k]);
				for(l=1; l<=4; l++){
					cnt = 0;
					input.figure = l;
					fallacyTable[0] = UndistributedMiddle(&input);
					fallacyTable[1] = IllicitMajor(&input);
					fallacyTable[2] = IllicitMinor(&input);
					fallacyTable[3] = ExclusivePremises(&input);
					fallacyTable[4] = IllicitAffirmation(&input);
					fallacyTable[5] = ExistentialFallacy(&input);
					printf("%c%c%c-%d   ", temp[i], temp[j], temp[k], l);
					for(m=0; m<6; m++){
						printf("%d ", fallacyTable[m]);
						cnt += fallacyTable[m]?1:0;
					}
					if(cnt==0){
						printf("  VALID");
						cntValid++;
						printf(" %d", cntValid);
					}
					printf("\n");
				}
			}
		}
	}
	
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
	switch(syllogism->figure){
		case 1:
			if(!(syllogism->majorPremise.subjectDistribution)){
				if(!(syllogism->minorPremise.predicateDistribution)){
					return true;
				}
				else return false;
			}
			else return false;
			break;
		case 2:
			if(!(syllogism->majorPremise.predicateDistribution)){
				if(!(syllogism->minorPremise.predicateDistribution)){
					return true;
				}
				else return false;
			}
			else return false;
			break;
		case 3:
			if(!(syllogism->majorPremise.subjectDistribution)){
				if(!(syllogism->minorPremise.subjectDistribution)){
					return true;
				}
				else return false;
			}
			else return false;
			break;
		case 4:
			if(!(syllogism->majorPremise.predicateDistribution)){
				if(!(syllogism->minorPremise.subjectDistribution)){
					return true;
				}
				else return false;
			}
			else return false;
			break;
	}
} 

/*대개념 부당주연의 오류*/
bool IllicitMajor(Syllogism* syllogism){
	switch (syllogism->figure){
		case 1:
		case 3:
			if(!(syllogism->majorPremise.predicateDistribution)){
				if(syllogism->conclusion.predicateDistribution){
					return true;
				}
				else return false;
			}
			else return false;
			break;
		case 2:
		case 4:
			if(!(syllogism->majorPremise.subjectDistribution)){
				if(syllogism->conclusion.predicateDistribution){
					return true;
				}
				else return false;
			}
			else return false;
			break;
	}
}

/*소개념 부당주연의 오류*/
bool IllicitMinor(Syllogism* syllogism){
	switch (syllogism->figure){
		case 1:
		case 2:
			if(!(syllogism->minorPremise.subjectDistribution)){
				if(syllogism->conclusion.subjectDistribution){
					return true;
				}
				else return false;
			}
			else return false;
			break;
		case 3:
		case 4:
			if(!(syllogism->minorPremise.predicateDistribution)){
				if(syllogism->conclusion.subjectDistribution){
					return true;
				}
				else return false;
			}
			else return false;
			break;
	}
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
bool IllicitAffirmation(Syllogism* syllogism){
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
