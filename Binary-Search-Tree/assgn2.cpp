#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;

class node
{
	private:
		string word,meaning;
		node *lc,*rc;
	public:
		node();
		void getdata();
		void printdata();
		~node(){};
		friend class tree;
};
node::node()
{
	word="N/A";
	meaning="N/A";
	lc=NULL;
	rc=NULL;
}
void node::getdata()
{
	cout<<"\nEnter word: ";
	cin>>word;
	cout<<"\nEnter Meaning: ";
	cin>>meaning;
}

void node::printdata()
{
	cout<<"\nWord: "<<word;
	cout<<"\nMeaning: "<<meaning<<"\n";
}

class tree
{
	private:
		node *root;
	public:
		tree();
		void insert(node w);
		void search(string w);
		void update(string w);
		void remove(string w);
		void assign(node *w);
		void display(node *ptr);
		node* retroot();
		~tree(){};
};

tree::tree()
{
	root=NULL;
}

void tree::insert(node w)
{
	node *newnode = new node();
	*newnode=w;
	if(root==NULL)
	{
		root=newnode;
		root->lc=NULL;
		root->rc=NULL;
	}
	else
	{
		node *ptr=root;
		while(1)
		{
			if(newnode->word>ptr->word)
			{
				if(ptr->rc)
				{
					ptr=ptr->rc;
				}
				else
				{
					ptr->rc=newnode;
					newnode->lc=NULL;
					newnode->rc=NULL;
					break;
				}
			}
			else if(newnode->word<ptr->word)
			{
				if(ptr->lc)
				{
					ptr=ptr->lc;
				}
				else
				{
					ptr->lc=newnode;
					newnode->lc=NULL;
					newnode->rc=NULL;
					break;
				}
			}
			else
			{
				cout<<"Same entry not allowed";
			}
		}
	}
}

void tree::search(string w)
{
	node *ptr=root;
	while(ptr)
	{
		if(w>ptr->word)
		{
			ptr=ptr->rc;
		}
		else if(w<ptr->word)
		{
			ptr=ptr->lc;
		}
		else if(w==ptr->word)
		{
			cout<<"\nSearch successful";
			ptr->printdata();
			break;
		}
	}
	if(ptr==NULL)
	{
		cout<<"\nSearch unsuccessful";
	}
}

void tree::update(string w)
{
	node *ptr=root;
	while(ptr)
	{
		if(w>ptr->word)
		{
			ptr=ptr->rc;
		}
		else if(w<ptr->word)
		{
			ptr=ptr->lc;
		}
		else if(w==ptr->word)
		{
			cout<<"\nEnter new meaning: ";
			cin>>w;
			ptr->meaning=w;
			break;
		}
	}
	if(ptr==NULL)
	{
		cout<<"\nNo such word found!";
	}
}

void tree::remove(string w)
{
	node *p=root;
	node *q=root;
	node *r=root;
	
	while(p)
	{
		if(w>p->word)
		{
			q=p;
			p=p->rc;
		}
		else if(w<p->word)
		{
			q=p;
			p=p->lc;
		}
		else if(w==p->word)
		{
			if(p==root)
			{
				if(root->rc!=NULL && root->lc==NULL)
				{
					root=root->rc;
					delete p;
				}
				else if(root->rc==NULL && root->lc!=NULL)
				{
					root=root->lc;
					delete p;
				}
				else
				{
					r=p->rc;
					while(r->lc)
						r=r->lc;
					r->lc=p->lc;
					root=root->rc;
					delete p;
				}
			}
			else
			{
			
				if(p->rc==NULL && p->lc!=NULL && p==q->rc)
				{
					q->rc=p->lc;
					delete p;
				}
				else if(p->rc==NULL && p->lc!=NULL && p==q->lc)
				{
					q->lc=p->lc;
					delete p;
				}
				else if(p->rc==NULL && p->lc==NULL && p==q->rc)
				{
					q->rc=NULL;
					delete p;
				}
				else if(p->rc==NULL && p->lc==NULL && p==q->lc)
				{
					q->lc=NULL;
					delete p;
				}
				else
				{
					r=p->rc;
					while(r->lc)
						r=r->lc;
					r->lc=p->lc;
					if(q->lc==p)
						{
							q->lc=p->rc;
							delete p;
						}
					else if(q->rc==p)
						{
							q->rc=p->rc;
							delete p;
						}
				}
			}
			break;	
		}
	}
	if(p==NULL)
	{
		cout<<"\nNo such word found!";
	}
}

void tree::assign(node *w)
{
	if(w!=NULL)
	{
		assign(w->lc);
		this->insert(*w);
		assign(w->rc);
	}
}
void tree::display(node *ptr)
{
	if(ptr!=NULL)
	{
		display(ptr->lc);
		ptr->printdata();
		display(ptr->rc);
	}
}

node* tree::retroot()
{
	return root;
}

int main()
{
	tree dictionary,d;
	node w;
	string s;
	while(1)
	{
		int opt;
		cout<<"\n===================Menu========================\n";
		cout<<"1.Insert\n2.Search\n3.Update\n4.Delete\n5.Display\n6.Assign\n7.Exit\n";
		cin>>opt;
			switch(opt)
		{
			case 1:
				w.getdata();
				dictionary.insert(w);
				break;
			case 2:
				cout<<"\nEnter word to be searched: ";
				cin>>s;
				dictionary.search(s);
				break;
			case 3:
				cout<<"\nEnter word to be updated: ";
				cin>>s;
				dictionary.update(s);
				break;
			case 4:
				cout<<"\nEnter word to be deleted: ";
				cin>>s;
				dictionary.remove(s);
				break;
			case 5:
				dictionary.display(dictionary.retroot());
				break;
			case 6:
				d.assign(dictionary.retroot());
				cout<<"\nCopied dictionary\n";
				d.display(d.retroot());
				break;
			case 7:
				exit(0);
				break;
			default:
				break;
		}
	}
	
	return 0;
}
	
