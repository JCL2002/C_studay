#include<stdio.h>
#include<string.h>
int main(){
	int team=1,star=1;
	char Team[7],Star[7];
	gets(Team);gets(Star);
	int l_t,l_s;
	l_t=strlen(Team);l_s=strlen(Star);
	int i;//ÓÃÓÚÑ­»·
	for(i=0;i<l_t;i++){
		team*=(int)(Team[i]-'A'+1);
	} 
	for(i=0;i<l_s;i++){
		star*=(int)(Star[i]-'A'+1);
	}
	if(team%47==star%47){
		printf("GO");
	}
	else{
		printf("STAY");
	}
	return 0;
}
