#include<stdio.h>
void main()
{
	char *s="infynity";
	long int h=0,a;
	int i;
	for(i=0;s[i]!='\0';i++){
		a=1;
		int temp=(int)s[i]-97;
		a=a<<temp;
		if(a&h){   
			printf("%c\n",s[i]);
		}
		else{
			h=a|h;
		}
	}
	
}
