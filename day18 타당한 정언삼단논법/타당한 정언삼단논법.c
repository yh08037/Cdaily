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


const CategoricalProposition A = {true, false};		//전칭긍정명제 
const CategoricalProposition E = {true, true};		//전칭부정명제 
const CategoricalProposition I = {false, false};	//특칭긍정명제 
const CategoricalProposition O = {false, true};		//특칭부정명제 

const char* fallacy[] = {"매개념 부주연의 오류.", "대개념 부당주연의 오류.",
			"소개념 부당주연의 오류.", "양부정전제의 오류.",
			"부당긍정의 오류.", "부당부정의 오류.", "존재가정의 오류."};

void GetSyllogism(Syllogism*);			//논증 식을 입력받아 저장합니다 
CategoricalProposition SetProposition(char);	//알파벳을 정언명제로 대입합니다 
bool UndistributedMiddle(Syllogism*);		//매개념 부주연의 오류 
bool IllicitMajor(Syllogism*);			//대개념 부당주연의 오류 
bool IllicitMinor(Syllogism*);			//소개념 부당주연의 오류 
bool ExclusivePremises(Syllogism*);		//양부정전제의 오류 
bool IllicitAffirmation(Syllogism*);		//부당긍정의 오류 
bool IllicitNegation(Syllogism*);		//부당부정의 오류 
bool ExistentialFallacy(Syllogism*);		//존재가정의 오류 
void SetFallacy(bool*, Syllogism*);		//오류배열에 결과를 대입합니다 
bool Validation(bool*, int);			//논증을 평가합니다 (타당:true)(0:아리스토텔레스, 1:부울)
void PrintFallacy(bool*, int);			//오류를 출력합니다 (0:아리스토텔레스, 1:부울)
void PrintAllCases(int);			//모든 경우를 출력합니다 (0:아리스토텔레스, 1:부울) 


int main(void){
	
	Syllogism input;
	bool fallacyTable[7];
	
	printf("논증 식 : ");
	
	GetSyllogism(&input);
	
	SetFallacy(fallacyTable, &input);
	
	printf("아리스토텔레스 : ");
	if(Validation(fallacyTable, 0)){
		printf("타당하다.\n"); 
	}
	else{
		printf("타당하지 않다. ");
		PrintFallacy(fallacyTable, 0);
		printf("\n"); 
	}
	
	printf("부울 : "); 
	if(Validation(fallacyTable, 1)){
		printf("타당하다.\n"); 
	}
	else{
		printf("타당하지 않다. ");
		PrintFallacy(fallacyTable, 1);
		printf("\n"); 
	}
		
	return 0;
}


/*논증 식을 입력받아 저장합니다*/
void GetSyllogism(Syllogism* syllogism){
	syllogism->majorPremise = SetProposition(getchar());
	syllogism->minorPremise = SetProposition(getchar());
	syllogism->conclusion = SetProposition(getchar());
	getchar();
	scanf("%d", &(syllogism->figure));
	getchar();
}

/*알파벳을 정언명제로 대입합니다*/
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

/*부당부정의 오류*/
bool IllicitNegation(Syllogism* syllogism){
	if(!(syllogism->majorPremise.predicateDistribution)){
		if(!(syllogism->minorPremise.predicateDistribution)){
			if(syllogism->conclusion.predicateDistribution){
				return true;
			}
			else return false;
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

/*오류배열에 결과를 대입합니다*/
void SetFallacy(bool* fallacyTable, Syllogism* syllogism){
	fallacyTable[0] = UndistributedMiddle(syllogism);
	fallacyTable[1] = IllicitMajor(syllogism);
	fallacyTable[2] = IllicitMinor(syllogism);
	fallacyTable[3] = ExclusivePremises(syllogism);
	fallacyTable[4] = IllicitAffirmation(syllogism);
	fallacyTable[5] = IllicitNegation(syllogism);
	fallacyTable[6] = ExistentialFallacy(syllogism);
}

/*논증을 평가합니다 (0:아리스토텔레스, 1:부울)*/
bool Validation(bool* fallacyTable, int num){
	int i, cnt=0;
	for(i=0; i<6+num; i++){
		cnt += fallacyTable[i]?1:0;
	}
	if(cnt==0) return true;
	else return false;
} 

/*오류를 출력합니다 (0:아리스토텔레스, 1:부울)*/
void PrintFallacy(bool* fallacyTable, int num){
	int i;
	for(i=0; i<6+num; i++){
		if(fallacyTable[i]){
			printf("%s ", fallacy[i]);
		}
	}	
}

/*모든 경우를 출력합니다 (0:아리스토텔레스, 1:부울)*/
void PrintAllCases(int num){
	int i, j, k, l, m, cnt, cntValid=0;
	char temp[] = "AEIO";
	Syllogism syllogism;
	bool fallacyTable[7]; 
	
	for(i=0; i<4; i++){
		syllogism.majorPremise = SetProposition(temp[i]);		
		for(j=0; j<4; j++){
			syllogism.minorPremise = SetProposition(temp[j]);
			for(k=0; k<4; k++){
				syllogism.conclusion = SetProposition(temp[k]);
				for(l=1; l<=4; l++){
					cnt = 0;
					syllogism.figure = l;
					SetFallacy(fallacyTable, &syllogism);
					printf("%c%c%c-%d   ", temp[i], temp[j], temp[k], l);
					for(m=0; m<6+num; m++){
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
} 
