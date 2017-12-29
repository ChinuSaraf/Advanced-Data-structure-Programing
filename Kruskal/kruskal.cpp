#include<iostream>
using namespace std;

class graph
{
	int cost[100][100],visited[100];
public:
	graph()
	{
		for(int i=1;i<=100;i++)
		{
			for(int j=1;j<=100;j++)
				cost[i][j]=999;
		}
		for(int i=1;i<=100;i++)
		{
			visited[i]=0;
		}
	}
	void addedges(int n)
	{
		int i,j;
    		cout<<"Enter Cost of phone lines:-"<<endl;

    		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
			    cout<<i<<" -->  "<<j<<endl;
				cin>>cost[i][j];
				cost[j][i]=cost[i][j];

				if(cost[i][j]==0|| cost[j][i]==0)
				{	
					cost[i][j]=999;
				   	cost[j][i]=999;
				}
			}
		}
	}
	void kruskal(int v)
	{
		int ne=1,i,j,mincost=0,min,a,b;
		while(ne<v)
		{
			int flag=1;
			min=998;
			for(i=1;i<=v;i++)
			{
				for(j=1;j<=v;j++)
				{
					if(cost[i][j]<=min && (visited[i]==0 || visited[j]==0))
					{
						min=cost[i][j];
						a=i;
						b=j;
						flag=0;
					}
					else if(cost[i][j]<=min && flag==1)
					{
						min=cost[i][j];
						a=i;
						b=j;
					}
				}
			}
			visited[a]=1;
			visited[b]=1;
			ne++;
			mincost+=min;
			cost[a][b]=cost[b][a]=999;
			cout<<"\nEdge \t"<<a<<"->"<<b<<"\n";
		}
		cout<<"\nWeight of minimum spanning tree is "<<mincost<<endl;
	}
};

int main()
{
	int n;
	graph g;
	cout<<"\nEnter the number of companies:";
	cin>>n;
	g.addedges(n);
	g.kruskal(n);
	return 0;
}
