#include <iostream>
#include<string.h>
using namespace std;


class node
{
	string key;
	string meaning;
	node *left;
	node *right;
	friend class AVL;
};

class AVL
{
    node *root;
     int count;

    /*node *findmin(node *rt)
    {

   	 if(rt->left!=NULL)
   	 {
   		 findmin(rt->left);
   	 }
   	 return rt;
    }*/

    node * insert(node *temp,node *rot)
    {
   	 if(rot==NULL)
   	 {
   		 rot=temp;
   	 }
   	 else
   	 {
   		 if(rot->key==temp->key)
   		 {
   			 cout<<"Word is repeated"<<endl;
   			 return rot;
   		 }
   		 else if(rot->key>temp->key)
   		 {
   			 rot->left=insert(temp,rot->left);
   			 rot=balance(rot);
   		 }
   		 else if(rot->key<temp->key)
   		 {
   			 rot->right=insert(temp,rot->right);
   			 rot=balance(rot);
   		 }

   	 }

   	 return rot;
    }
public:

	AVL()
	{
    	root=NULL;
    	count=0;
	}

	void create(string ikey, string imeaning)
	{
    	node *new1=new node;
    	new1->key=ikey;
    	new1->meaning=imeaning;
    	new1->left=new1->right=NULL;

    	root=insert(new1,root);

	}
	
	void bisearch(node *rt,string ikey)
	{
		if(rt==NULL)
    	{
   		 cout<<"Word Does not Exist \n";
    	}
    	else if(rt->key==ikey)
    	{
   		 cout<<rt->meaning<<endl;
   		 cout<<"No. of comparisons: "<<count;
    	}
    	else if(rt->key>ikey)
    	{
   		bisearch(rt->left,ikey);
    	}
    	else if(rt->key<ikey)
    	{
   		 bisearch(rt->right,ikey);
    	}

	}


	void update(node *rt ,string ikey)
	{
   	 if(rt==NULL)
   	 {
   		 cout<<"Word does not exist !!!!!!"<<endl;
   		 return;
   	 }
   	 string newmeaning;
   	 if(rt->key==ikey)
   	 {
   		 cout<<"Word Found \nEnter the new meaning :";
   		 cin>>newmeaning;
   		 rt->meaning=newmeaning;
   	 }
   	 else if(rt->key>ikey)
   	 {
   		 update(rt->left,ikey);
   	 }
   	 else if(rt->key<ikey)
   	 {
   		 update(rt->right,ikey);
   	 }
	}



	node* deleten(node *rt, string  val)
	{
   	 if (rt==NULL)
   	 {
   		 cout<<"Word does not exist"<<endl;
   		 return rt;
   	 }

   	 if(rt->key==val)
   	 {
   		 if(rt->left==NULL && rt->right==NULL)
   		 {
   			 delete rt;
   			 rt=NULL;
   			 return rt;
   		 }
   		 else if(rt->left==NULL)
   		 {
   			 node *t=rt;
   			 rt=rt->right;
   			 delete t;
   			 return rt;
   		 }
   		 else if(rt->right==NULL)
   		 {
   			 node *t=rt;
   			 rt=rt->left;
   			 delete t;
   			 return rt;
   		 }
   		 else
   		 {
   			 node *temp=findmin(rt->right);
   			 rt->key=temp->key;
   			 rt->meaning=temp->meaning;
   			 rt->right=deleten(rt->right,temp->key);
   			 rt=balance(rt);
   		 }
   	 }
   	 else if(rt->key<val)
   	 {
   		 rt->right=deleten(rt->right, val);
   		 rt=balance(rt);
   	 }
   	 else if(rt->key>val)
   	 {
   		 rt->left=deleten(rt->left, val);
   		 rt=balance(rt);
   	 }
   	 return rt;
	}

	void displayasc(node *rt)
	{
		if(rt==NULL) return;
		displayasc(rt->left);
		cout<<rt->key<<" "<<rt->meaning<<" "<<heightdiff(rt)<<endl;;
		displayasc(rt->right);
	}

	void displayinod(node *rt)
	{
		if(rt==NULL) return;
		cout<<rt->key<<" "<<rt->meaning<<" "<<heightdiff(rt)<<endl;
		displayinod(rt->left);
		displayinod(rt->right);
	}

	int max(int l,int r)
	{
		if(l>r)
		{
			return l;
		}
		return r;
	}

	int height(node *t)
	{
		int h=0;
		if(t!=NULL)
		{
			int lh=height(t->left);
			int rh=height(t->right);
			int mx=max(lh,rh);
			h=mx+1;
		}
		return h;

	}

	int heightdiff(node *t)
	{
		int lh,rh;
		lh=height(t->left);
		rh=height(t->right);
		int diff=lh-rh;
		return diff;
	}

	node *rr(node *t)
	{
		//cout<<"rr "<<t->key<<endl;
		node *temp;
		temp=t->right;
		t->right=temp->left;
		temp->left=t;
		return temp;

	}

	node *ll(node *t)
	{
		//cout<<"ll "<<t->key<<endl;
		node *temp;
		temp=t->left;
		t->left=temp->right;
		temp->right=t;
		return temp;
	}

	node *rl(node *t)
	{
		//cout<<"rl "<<t->key<<endl;
		node *temp;
		temp=t->right;
		t->right=ll(temp);
		return rr(t);
	}

	node *lr(node *t)
	{
		//cout<<"lr "<<t->key<<endl;
		node *temp;
		temp=t->left;
		t->left=rr(temp);
		return ll(t);
	}

	node *balance(node *t)
	{
		int l=heightdiff(t);
		if(l>1)
		{
			if(heightdiff(t->left)>0)
			{
				t=ll(t);
			}
			else
			{
				t=lr(t);
			}

		}
		else if(l<-1)
		{
			if(heightdiff(t->right)>0)
			{
				t=rl(t);
			}
			else
			{
				t=rr(t);
			}
		}
		return t;
	}

	node *get()
	{
		return root;
	}

};

int main() {
	//cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	AVL b;
	string mean;
		string val;
		int c;


		do
		{
	   	 cout<<"1:Enter the new word \n2:Delete the word \n3:Update the keyword meaning \n4:Display the tree in Ascending order \n5.Find the meaning of keyword \n6.Exit\nEnter your choice:";
	   	 cin>>c;
	   	 cout<<endl;
	   	 switch(c)
	   	 {
	   		 case 1:
	   			 cout<<"Enter the keyword :";
	   			 cin>>val;
	   			 cout<<"Enter its meaning :";
	   			 cin>>mean;
	   			 b.create(val,mean);
	   			 break;

	   		 case 2:
	   			 cout<<"Enter the keyword to be deleted:";
	   			 cin>>val;
	   			 b.deleten(b.get(),val);
	   			 break;

	   		 case 3:
	   			 cout<<"Enter the Keyword whose meaning is to be changed :";
	   			 cin>>val;
	   			 b.update(b.get(),val);
	   			 break;

	   		 case 4:
	   			 b.displayasc(b.get());
	   			 cout<<endl;
	   			 break;

	   		 case 5:
	   			 cout<<"Enter the Keyword whose meaning is to be changed :";
	   			 cin>>val;
	   			 b.bisearch(b.get(),val);
	   			 break;
	   		 case 6:
	   			 break;

	   		 default:
	   			 cout<<"Invalid Option \n";
	   			 break;
	   	 }

		}while(c!=6);




	return 0;
}


