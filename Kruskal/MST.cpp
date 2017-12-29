#include <iostream>
#include<bits/stdc++.h>

using namespace std;
class mst
{
	int noe;
	int v;
	int e;
int	cost[9][9],parent[9];
public:
    int getdata()
    {
        cout<<"Enter number of offices"<<endl;
        cin>>v;
        return v;
    }
    int find(int i)
 {
	if(parent[i])
	i=parent[i];
	//cout<<"Parent is"<<parent[i];
	return i;
 }
int uni(int i,int j)
{
	if(i!=j)
	{
		parent[j]=i;
		return 1;
	}
	return 0;
}
void kruskal()
{
    int i,j,ne=1,mincost=0,u,v,a,b;
    int min;
   int n= getdata();
    for(i=1;i<=n;i++)
    {
        parent[i]=i;
    }

    cout<<"Enter Cost of phone lines:-"<<endl;

    for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
		    cout<<i<<" -->  "<<j<<endl;
			cin>>cost[i][j];
			cost[j][i]=cost[i][j];

			if(cost[i][j]==0|| cost[j][i]==0)
			{	cost[i][j]=999;
			   cost[j][i]=999;
		}
		}
	}
	cout<<"The minimum cost connection is"<<endl;
	while(ne<n)
    {
        for(i=1,min=999;i<=n;i++)
		{
			for(j=1;j <= n;j++)
			{
				if(cost[i][j] < min)
				{
					min=cost[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		u=find(u);
		v=find(v);
		if(uni(u,v))
		{
		    cout<<ne++<<" Edge  "<<"("<<a<<","<<b<<")"<<endl;


			mincost=mincost+min;
		}
		cost[a][b]=cost[b][a]=999;
	}
	cout<<"The minimum cost is"<<mincost<<endl;
    }
};

int main(void) {
	mst m;
	m.kruskal();
	return 0;
}
