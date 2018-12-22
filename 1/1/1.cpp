#include<iostream>
#include<vector>
#include<queue>
#include<stdio.h>
#include<string.h>


using namespace std;

struct city
{
	char name[20];
	int id;
};

struct train
{
	int t,v,w,c;
};


vector<city> vc;
vector<train> vt[100];


int dis[100],dic[100];
int cnt=0;
const int time=10;
const int maxn=(int)1e6;

int find(char str[]);
void getdis(int ask);
void getdic(int ask);

int main()
{
	int i,j,n,m,r,ask;
	city tmc;
	train tmt;
	cin>>n>>m>>ask;

	for(i=0;i<n;i++)
	{
		cin>>tmc.name;
		tmc.id=cnt++;
		vc.push_back(tmc);
	}
	for(i=0;i<m;i++)
	{
		char ct[2][20];
		cin>>tmt.t>>ct[0]>>ct[1]>>tmt.w>>tmt.c;
		r=find(ct[0]),tmt.v=find(ct[1]);
		printf("%s %d / %s %d\n",ct[0],r,ct[1],tmt.v);
		vt[r].push_back(tmt);
	}
	


	for(i=0;i<vc.size();i++)
		printf("%s %d\n",vc[i].name,vc[i].id);
	for(i=0;i<100;i++)
		for(j=0;j<vt[i].size();j++)
			printf("%d %d %d %d\n",vt[i][j].t,vt[i][j].v,vt[i][j].w,vt[i][j].c);
	
	getdis(ask);
	for(i=0;i<100;i++)
		printf("%d\t",dis[i]);

	getdic(ask);
	for(i=0;i<100;i++)
		printf("%d\t",dic[i]);
	return 0;
}


int find(char str[])
{
	int i;
	for(i=0;i<vc.size();i++)
		if(strcmp(str,vc[i].name)==0)
			return vc[i].id;
	return -1;
}

void getdis(int ask)
{
	char book[100];
	int i,j;
	for(i=0;i<100;i++)
	{
		dis[i]=maxn;
		book[i]=1;
	}
	dis[ask]=time;
	book[ask]=0;
	for(i=0;i<vt[ask].size();i++)
		if( dis[ask]+60 < vt[ask][i].t )
			dis[ vt[ask][i].v ]= vt[ask][i].t+vt[ask][i].w;
	
	int k=0;
	for(i=0;i<100;i++)
	{
		int minn=(int)1e5;
		for(j=0;j<100;j++)
			if(book[j] && minn>dis[j])
			{
				minn=dis[j],k=j;
			}
		book[k]=0;
		for(j=0;j<vt[k].size();j++)
		{
			if(dis[k]+60<vt[k][j].t && dis[ vt[k][j].v ] >vt[k][j].t+vt[k][j].w)
				dis[ vt[k][j].v ]=vt[k][j].t+vt[k][j].w;
		}
	}
}

void getdic(int ask)
{
	char book[100];
	int i,j;
	for(i=0;i<100;i++)
	{
		dis[i]=dic[i]=maxn;
		book[i]=1;
	}
	dis[ask]=time;
	dic[ask]=0;
	book[ask]=0;
	for(i=0;i<vt[ask].size();i++)
	{
		if( dis[ask]+60 < vt[ask][i].t )
			dis[ vt[ask][i].v ]= vt[ask][i].t+vt[ask][i].w;
		dic[ vt[ask][i].v ]=dic[ask]+vt[ask][i].c;
	}

	
	int k=0,b=0;
	for(i=0;i<100;i++)
	{
		int minn=(int)1e5;
		for(j=0;j<100;j++)
		{
			if(book[j] && minn>dic[j])
			{
				minn=dic[j],k=j;
			}
		}
		book[k]=0;
		for(j=0;j<vt[k].size();j++)
		{
			if(dis[k]+60<vt[k][j].t && dic[ vt[k][j].v ] > dic[k] + vt[k][j].c )
			{
				dis[ vt[k][j].v ]=vt[k][j].t+vt[k][j].w;
				dic[ vt[k][j].v ]=dic[k]+vt[k][j].c;
			}
		}
	}
}

/*
3 3 0
a b c
100 a b 30 40
130 a c 30 10
500 c b 30 5
*/
