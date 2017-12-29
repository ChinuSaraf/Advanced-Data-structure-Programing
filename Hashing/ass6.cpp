/*
Implement all the functions of a dictionary (ADT) using hashing. Data:  Set of (key, value) pairs, Keys are mapped to values, Keys must be comparable, Keys must be unique Standard Operations:  Insert(key, value), Find(key), Delete(key)
*/
//============================================================================
// Name    	: ASS6_hash.cpp
// Author  	: 
// Version 	:
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<stack>
using namespace std;

class hash
{
    string h[26];
public:

    /*void lowercase(string &t)
    {
   	 int i=0;
   	 while(t[i])
   	 {
   		 t[i]=tolower(t[i]);
   		 i++;
   	 }
    }*/
    void insert_wo_repl(string key)
    {
   	// lowercase(key);
   	 int t=key[0];
   	 t=t-97;
   	 int a=t;
   	 do
   	 {
   		 if(h[t]==key)
   		 {
   			 cout<<"Word already Exist \n";
   			 return;

   		 }
   		 else if(h[t]=="\0")
   		 {
   			 h[t]=key;
   			 return;
   		 }
   		 else
   		 {
   			 t=(t+1)%26;
   		 }

   	 }while(t!=a);

   	 cout<<"Hash Table is Full\n";
    }

 /*   void insert_w_repl(string key)
    {
   	 //lowercase(key);
   	 int t=key[0];
   	 t=t-97;
   	 int a=t;
   	 do
   	 {
   		 string q=h[t];
   		 int j=q[0];
   		 j=j-97;
   		 if(j!=t)
   		 {
   			 h[t]=key;
   			 insert_wo_repl(h[t]);
   			 return;
   		 }
   		 else
   		 {
   			 t=(t+1)%26;
   		 }

   	 }while(t!=a);

   	 cout<<"Hash Table is Full\n";
    }*/

    void disp()
    {
   	 for(int i=0;i<26;i++)
   	 {
   		 cout<<i<<" "<<h[i]<<endl;
   	 }
    }




    int search(string key)
    {
   	 lowercase(key);
   	 int t=key[0];
   	 t=t-97;
   	 int a=t;

   	 do
   	 {
   		 if(h[t]==key)
   		 {
   			 return 1;
   		 }
   		 else
   		 {
   			 t=(t+1)%26;
   		 }

   	 }while(t!=a);

   	 return 0;
    }

 /*   void deletekwithreplc(string key)
    {
   	 stack <string> s;
   	 string c;
   	 lowercase(key);
   	 int t=key[0];
   	 bool flag=0;
   	 t=t-97;
   	 int a=t;
   	 do
   	 {
   		 c=h[t];
   		 if(c[0]==key[0])
   		 {
   			 if(c==key)
   			 {
   				 flag=1;
   			 }
   			 s.push(h[t]);
   			 h[t]="\0";
   		 }
   		 else if(c=="\0")
   		 {
   			 break;
   		 }
   		 else
   		 {
   			 t=(t+1)%26;
   		 }

   	 }while(t!=a);

   	 if(flag==0)
   	 {
   		 cout<<"Word does not Exist\n";
   	 }
   	 while(!s.empty())
   	 {
   		 c=s.top();
   		 s.pop();
   		 if(c!=key)
   		 {
   			 insert_wo_repl(c);
   		 }
   	 }
    }*/

     void deletek(string key)
    	{
        	lowercase(key);
        	int t=key[0];
        	t=t-97;
        	int a=t;
        	do
        	{
            	if(h[t]==key)
            	{
                	h[t]="\0";
                	return;
            	}
            	else
            	{
                	t=(t+1)%26;
            	}

        	}while(t!=a);

        	cout<<"Word does not Exist\n";
    	}


};

int main() {
    hash h;
    string k;
    int c;
    do
    {
   	
   	 cout<<"1.Insert \n2.Find \n3.Delete \n0.Exit \nEnter Your option:";
   	 cin>>c;

   	 switch(c)
   	 {
   	 case 0:
   		 break;

   	 case 1:
   	  	 cout<<"Enter the keyword :";
   	 	 cin>>k;
   		 h.insert_wo_repl(k);
   		 break;

   	 case 2:
   	 	 cout<<"Enter the keyword :";
   	  	 cin>>k;
   		 if(h.search(k))
   		 {
   			 cout<<"Found \n";
   		 }
   		 else
   		 {
   			 cout<<"Not Found \n";
   		 }
   		 break;

   	 case 3:
   	 	 cout<<"Enter the keyword :";
   	 	 cin>>k;
   		 h.deletek(k);
   		 break;

   	 default:
   		 cout<<"Invalid option \n";
   		 break;
   	 }

   	 cout<<endl;
    }while(c);

    h.disp();

    return 0;
}




