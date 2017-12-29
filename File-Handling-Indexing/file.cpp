#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>

using namespace std;

int main()
{
	int roll;
	string name,address;
	fstream file;
	fstream temp;
	
	int opt;
	int n=0,i=0;
	int flag;
	
	int croll;
	string cname,caddress;
	while(1)
	{
		cout<<"\n1.Add Record\n2.Find Record\n3.Delete Record\n4.Display all records\n5.Exit";
		cin>>opt;
		switch(opt)
		{
			case 1:
				file.open("Student.txt",ios::out|ios::app);
				cout<<"Enter Roll no. : ";
				cin>>roll;
				cout<<"Enter name: ";
				cin>>name;
				cout<<"Enter address: ";
				cin>>address;
				file<<roll<<"\t"<<name<<"\t"<<address<<"\n";
				file.close();
				n++;
				break;
			case 2:
				file.open("Student.txt",ios::in|ios::app);
				cout<<"Enter roll no. to be searched: ";
				cin>>croll;
				flag=0;
				while(!file.eof())
				{
					file>>roll>>name>>address;
					if(roll==croll)
					{
						flag=1;
						break;
					}
				}
				if(flag==1)
				{
					cout<<"\nRoll no. : "<<roll;
					cout<<"\nName: "<<name;
					cout<<"\nAddress: "<<address;
				}
				else
				{
					cout<<"\nRecord not found!";
				}
				file.close();
				break;
			case  3:
				i=0;
				file.open("Student.txt",ios::in|ios::app);
				temp.open("temp.txt",ios::out|ios::app);
				cout<<"\nEnter roll no. to be deleted: ";
				cin>>croll;
				flag=0;
				while(i<=n)
				{
					file>>roll>>name>>address;
					if(roll!=croll)
					{
						temp<<roll<<"\t"<<name<<"\t"<<address<<"\n";
					}
					else
					{
						n--;
						flag=1;
					}
					
					
				}
				if(flag==0)
				{
					cout<<"\nRecord not present";
				}
				i++;
				file.close();
				temp.close();
				
				remove("Student.txt");
				rename("temp.txt","Student.txt");
				
				break;
			case 4:
				i=0;
				file.open("Student.txt",ios::in|ios::app);
				while(i<n)
				{
					file>>roll>>name>>address;
					cout<<"\nRoll no. : "<<roll;
					cout<<"\nName: "<<name;
					cout<<"\nAddress: "<<address;
					i++;
				}
				file.close();
				break;
			case 5:
				exit(0);
				break;
		}
	}
}
