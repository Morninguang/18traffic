#include<stdlib.h>
#include<stdio.h>


int main()
{
	FILE *fp;
	
	int tmp=1,cnt=2;
	char ch[5];
	
	if((fp=fopen("2.txt","w"))==NULL)
		exit(-1);
	if(fwrite("hello",sizeof("hello")+1,1,fp) !=1)
		exit(-1);
	fclose(fp);

	if((fp=fopen("2.txt","r"))==NULL)
		exit(-1);
	if(fread(ch,sizeof(ch)+1,1,fp)!=1)
		exit(-1);
	printf("%s",ch);
	fclose(fp);
	/*
	if((fp=fopen("2.txt","w"))==NULL)
		exit(-1);
	if(fwrite(&tmp,sizeof(tmp),1,fp) !=1)
		exit(-1);
	fclose(fp);
	
	if((fp=fopen("2.txt","r"))==NULL)
		exit(-1);
	if(fread(&cnt,sizeof(cnt),1,fp)!=1)
		exit(-1);
	printf("%d",cnt);*/

	fclose(fp);
	return 0;
}
