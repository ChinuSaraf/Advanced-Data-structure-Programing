#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;

class hash
{
	private:
		string h[26];
		int hashfunc(string x);
	public:
		int insert(string x);
		int remove(string x);
		int find(string x);
		void display();
};

int hash::hashfunc(string x)
{
	int key=x[0];
	if(key>=97 && key<=122)
		key-=97;
	else if(key>=65 && key<=90)
		key-=65;
	else
		cout<<"Enter valid string";
		
	return key;
}

int hash::insert(string x)
{
	int key=hashfunc(x);
	do
	{
		if(h[key]=="\0")
		{
			h[key]=x;
			return key;
		}
		else if(h[key]==x)
		{
			cout<<"Key already present";
			return key;
		}
		else
		{
			key=(key+1)%26;
		}
	}while(key!=hashfunc(x));
	
	cout<<"Hash table full!!";
	return -1;
}

int hash::remove(string x)
{
	int key=hashfunc(x);
	do
	{
		if(h[key]!=x)
		{
			key=(key+1)%26;
		}
		else if(h[key]==x)
		{
			h[key]='\0';
			return key;
		}
	}while(key!=hashfunc(x));
	cout<<"Key not present!!";
	return -1;
}

int hash::find(string x)
{
	int key=hashfunc(x);
	do
	{
		if(h[key]!=x)
		{
			key=(key+1)%26;
		}
		else if(h[key]==x)
		{
			cout<<"Key found";
			return key;
		}
	}while(key!=hashfunc(x));
	cout<<"Key not present!!";
	return -1;
}

void hash::display()
{
	for(int i=0;i<26;i++)
	{
		cout<<i<<"\t"<<h[i]<<endl;
	}
}

int main()
{
	hash obj;
	int opt;
	string word;
	while(1)
	{
		cout<<"\n1.Add Word\n2.Delete Word\n3.Find Word\n4.Display\n5.Exit"<<endl;
		cin>>opt;
		switch(opt)
		{
			case 1:
				cout<<"\nEnter word to be inserted: ";
				cin>>word;
				obj.insert(word);
				break;
			case 2:
				cout<<"\nEnter word to be deleted: ";
				cin>>word;
				obj.remove(word);
				break;
			case 3:
				cout<<"\nEnter word to be searched: ";
				cin>>word;
				opt=obj.find(word);
				cout<<"at position "<<opt;
				break;
			case 4:
				obj.display();
				break;
			case 5:
				exit(0);
				break;
		}
	}
}
