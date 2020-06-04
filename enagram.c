#include<stdio.h>
void main(){
	char *s1="medical";
	char *s2="decimal s";
	int i,hash[26]={0};
	for(i=0;s1[i]!='\0';i++){
		int temp=s1[i]-97;
		hash[temp]++;
	}
	int flag=1;
	for(i=0;s2[i]!='\0';i++){
		
		int temp=s2[i]-97;
		hash[temp]--;
		if(hash[temp]<0){
		printf("NOT  ENagram\n");
			flag=0;
			break;
		}
	}
	if(flag){
		printf(" ENagram\n");
	}
	
}
