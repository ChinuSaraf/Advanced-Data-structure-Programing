//============================================================================
// Name        : tfr.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
using namespace std;
/*You have a business with several offices; you want to lease
 *phone lines to connect them up with each other; and the
 *phone company charges different amounts of money to connect
 *different pairs of cities. You want a set of lines that
 *connects all your offices with a minimum total cost.
 *Solve the problem by suggesting appropriate data structures.
 */
class node
{
public:
	node *next;
	int dist;
	char name[10];
	node(int x)
	{
		dist=x;
		next=NULL;
	}
	friend class graph;
};
class graph
{
public:
	node *head[10];
    int a[10][3],l,ch[15],m;
	graph()
	{
        m=0;
        l=0;
		for(int i=0;i<10;i++){
			head[i]=NULL;
		}
	}
    int add(char so[],node *t)
	{
		int j,i;

		for( i=0;i<10;i++)
		{
			if(head[i]!=NULL)
			{
				j=strcmp(head[i]->name,so);
				if(j==0)
				{
					node *temp;
					temp=head[i];
					while(temp->next!=NULL)
						temp=temp->next;
					temp->next=t;
					t->next=NULL;
					return i;
				}
			}
			else{
				node *tem;
				tem=new node(9999);
				strcpy(tem->name,so);
				head[i]=tem;
				head[i]->next=t;
                return i;
			}
		}
        return i;
	}
	void insert()
	{

		char so[10],de[10];
		int amt,i,j;
		cout<<"Enter Source city"<<endl;
		cin>>so;
		cout<<"Enter Destination City"<<endl;
		cin>>de;
		cout<<"Enter Money"<<endl;
		cin>>amt;
		node *temp;
		temp=new node(amt);
		strcpy(temp->name,de);
		i=add(so,temp);

		node *temp1;
		temp1=new node(amt);
		strcpy(temp1->name,so);
		j=add(de,temp1);

        a[l][0]=amt;
        a[l][1]=i;
        a[l][2]=j;
        l++;
	}
	void display()
	{
        int x;
		for(int i=0;i<10;i++)
		{
			if(head[i]!=NULL)
			{
				node *temp;
				temp=head[i];
				cout<<"\nSource: ";
				cout<<temp->name<<endl;
				temp=temp->next;
				cout<<"Destinations: ";
				while(temp!=NULL)
				{
					cout<<temp->name<<" "<<temp->dist<<"   ";
					temp=temp->next;
				}
			}
            else{
                break;
            }
		}

	}
    void swap(int &a,int &b){
        int temp;
        temp=a;
        a=b;
        b=temp;
    }
    void sort()
    {
        int x;
        for(int i=1;i<l;i++){
            for(int j=0;j<l-i;j++){
                if(a[j+1][0]<a[j][0]){
                    swap(a[j][0],a[j+1][0]);
                    swap(a[j][1],a[j+1][1]);
                    swap(a[j][2],a[j+1][2]);
                }
            }
        }
        for(int i=0;i<l;i++){
            x=a[i][1];
            cout<<head[x]->name<<"  ";
            x=a[i][2];
            cout<<head[x]->name<<"  ";
            cout<<a[i][0]<<endl;
        }
    }
    void detect_cycle(int z){

        int p=a[z][1];
        int q=a[z][2],cnt=0,flag1=0,flag2=0;
        if(m==0){
            ch[0]=p;
            m++;
            ch[1]=q;
            m++;
            cout<<head[p]->name<<"  ";
            cout<<head[q]->name<<"  ";
            p=a[z][0];
            cout<<p<<endl;
        }
        else{
            for(int i=0;i<m;i++){
                if(ch[i]==p){
                    flag1=1;
                    cnt++;
                }
                if(ch[i]==q){
                    flag2=1;
                    cnt++;
                }
            }
            if(cnt==2){
                return;
            }
            else{
                if(flag1==1){
                    ch[m]=q;
                    m++;
                }
                else if(flag2==1){
                    ch[m]=p;
                    m++;
                }
                else{
                    ch[m]=p;
                    m++;
                    ch[m]=q;
                    m++;
                }
                cout<<head[p]->name<<"  ";
                cout<<head[q]->name<<"  ";
                p=a[z][0];
                cout<<p<<endl;
            }
        }
    }
    void kruskal()
    {
        sort();
        int r;
        cout<<"\nMST:"<<endl;
        for(int i=0;i<l;i++){
            detect_cycle(i);
        }
    }

};
int main() {
	graph g;
	int ch;
    int c=1;
	while(c==1){
		cout<<"1.Insert"<<endl;
		cout<<"2.Display"<<endl;
        cout<<"3.MST by Kruskal"<<endl;
        cout<<"4.Exit"<<endl;
		cin>>ch;
		switch(ch)
		{
		case 1:{
			g.insert();
			break;
		}
		case 2:{
			g.display();
			break;
		}
        case 3:{
            g.kruskal();
            break;
        }
        case 4:{
            c=0;
            break;
        }
		}
	}
	return 0;
}
