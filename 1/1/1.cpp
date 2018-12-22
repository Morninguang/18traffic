#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>

using namespace std;

struct city
{
	char name[20];
	int id;
};

struct train
{
	int tb,u,v,w,c;
};

struct path
{
	int v,w,c;
	path(){v=w=c=0;}
	path(int e,int f,int g):v(e),w(f),c(g){}

};

vector<city> vc;
vector<train> vt;
vector<path> vp[100];

char book[100];
int dis[100];
int cnt=0;
const int time=10;
const int maxn=(int)1e6;


int find(char str[])
{
	int i;
	for(i=0;i<vc.size();i++)
		if(strcmp(str,vc[i].name)==0)
			return vc[i].id;
	return -1;
}
int main()
{
	int i,j,n,m,t,k,r;
	city tmc;
	train tmt;
	path tmp;
	cin>>n>>m;

	for(i=0;i<n;i++)
	{
		cin>>tmc.name;
		tmc.id=cnt++;
		vc.push_back(tmc);
	}
	for(i=0;i<m;i++)
	{
		char ct[2][20];
		cin>>tmt.tb>>ct[0]>>ct[1]>>tmt.w>>tmt.c;
		tmt.u=find(ct[0]),tmt.v=find(ct[1]);
		printf("%s %d / %s %d\n",ct[0],tmt.u,ct[1],tmt.v);
		vt.push_back(tmt);
		vp[tmt.u].push_back(path(tmt.v,tmt.tb-time+tmt.w,tmt.c));
	}
	


	for(i=0;i<vc.size();i++)
		printf("%s %d\n",vc[i].name,vc[i].id);
	for(i=0;i<100;i++)
		for(j=0;j<vp[i].size();j++)
			printf("%d %d %d\n",vp[i][j].v,vp[i][j].w,vp[i][j].c);

	int ask=0;
	for(i=0;i<100;i++)
	{
		dis[i]=maxn;
		book[i]=1;
	}
	dis[ask]=0;
	for(i=0;i<vp[ask].size();i++)
	{
		dis[vp[ask][i].v]=vp[ask][i].w;//Ê±¼ä×î¶Ì
	}
	
	int flag=1;
	for(i=0;i<100;i++)
	{
		int minn=(int)1e5;
		for(j=0;j<100;j++)
			if(book[j] && minn>dis[j])
			{
				minn=dis[j],k=j;
			}
		book[k]=0;
		for(j=0;j<vp[k].size();j++)
		{
			if(dis[ vp[k][j].v ] >dis[k]+vp[k][j].w)
				dis[ vp[k][j].v ]=dis[k]+vp[k][j].w;
		}
	}

	for(i=0;i<100;i++)
		printf("%d\t",dis[i]);
	return 0;
}


/*
2 1
a b
20 a b 30 40
*/