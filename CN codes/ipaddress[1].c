#include<stdio.h>
#include<stdlib.h>
int main()
{
	char ipadd[16];
	gets(ipadd);
	puts(ipadd);
	int count=0;
	 int ipstored[12]={0};
	 int i=0;
	while(ipadd[i]!='\0'&&count<12)
	{
		if(ipadd[i]=='.')
		{
			i++;
		}
		else
		{
			ipstored[count]=atoi(&ipadd[i]);
			count++;
			while(ipadd[i]!='\0'&& ipadd[i]!='.')
			{
			i++;
		   }
		}
	}
	for(i=0;i<count;i++)
	{
		printf("\n Octate %d>>%d",i+1,ipstored[i]);
	}
} 
