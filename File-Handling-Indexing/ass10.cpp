/*
Department maintains a student information. The file contains roll number, name, division and address.   Allow user to add, delete information of student. Display information of particular employee.  If record of student does not exist an appropriate message is displayed. If it is, then the system displays the student details. Use sequential file to main the data.
*/
//============================================================================
// Name        : fileh.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream d;
	ofstream f;
	ofstream t;
	int r;
	int rol;
	bool flag=0;
	int n=0,i;
	string name,add;


	do{
		cout<<"1.Enter new record \n2.Find the record  \n3.Delete the record \n4.Exit \nEnter your choice :";
			cin>>r;
	switch(r)
	{
	case 1:

		f.open("data.txt",ios::out | ios::app);
		if(f.is_open())
		{
			cout<<"file opened successfully"<<endl;
		}
		else
		{
			cout<<"file not opened "<<endl;
			break;
		}
		cout<<"Enter the roll_no :";
		cin>>r;
		cout<<"Enter the Name :";
		cin>>name;
		cout<<"Enter the City :";
		cin>>add;


		f<<r<<"\t"<<name<<"\t"<<add<<endl;
		n++;
		f.close();

		break;

	case 2:

		d.open("data.txt",ios::in);
		if(d.is_open())
		{
			cout<<"file opened successfully"<<endl;
		}
		else
		{
			cout<<"file not opened "<<endl;
			break;
		}
		flag=0;

		cout<<"Enter the roll no to be searched :";
		cin>>rol;
		while(!d.eof())
		{
			d>>r>>name>>add;
			//cout<<r<<endl;
			if(r==rol)
			{
				cout<<"Record found !!!"<<endl;
				flag=1;
				break;
			}

		}

		if(flag==1)
		{
			cout<<"Roll No:"<<r<<"\nName: "<<name<<"\nLocation: "<<add<<endl;
		}
		else
		{
			cout<<"Not found"<<endl;
		}

		d.close();

			break;


	case 3:
		t.open("temp.txt",ios::out|ios::app);
		d.open("data.txt",ios::in|ios::app);
		if(d.is_open())
		{
			cout<<"file opened successfully"<<endl;
		}
		else
		{
			cout<<"file not opened "<<endl;
			break;
		}

		flag=0;
		i=0;
		cout<<"Enter the roll no to be deleted :";
		cin>>rol;
		while(i<=n)
		{
			d>>r>>name>>add;
			cout<<r<<endl;
			if(r!=rol)
			{
				//cout<<"Record found !!!"<<endl;
				t<<r<<"\t"<<name<<"\t"<<add<<endl;

			}
			else
			{
				flag=1;
				n--;
				
			}
			i++;

		}

		if(flag==0)
		{
			cout<<"Not found"<<endl;
		}


		t.close();
		d.close();

		remove("data.txt");
		rename("temp.txt","data.txt");

		break;

	case 4:
		r=0;
		break;

	default:
		cout<<"Wrong option";
		break;
	}

	}while(r);



	return 0;
}
