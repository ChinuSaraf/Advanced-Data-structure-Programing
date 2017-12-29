#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

class student
{
private:
int roll_no;
char name[100];
char address[100];

public:
void get_input();
void print_data();
void filein(int);
void fileout();
int countstudent();
};

void student::filein(int pn)
{
ifstream infile;
infile.open("Student.txt",ios::binary);
infile.seekg(pn*sizeof(student));
infile.read((char*) this,sizeof(*this));
}

void student::fileout()
{
ofstream outfile;
outfile.open("Student.txt",ios::app|ios::binary);
get_input();
outfile.write((char*)this,sizeof(*this));
}

int student::countstudent()
{
ifstream infile;
infile.open("Student.txt",ios::binary);
infile.seekg(0,ios::end);
int n=infile.tellg()/sizeof(student);
return n;
}

void student::get_input()
{
cout<<"\nEnter roll-no: ";
cin>>roll_no;
cout<<"\nEnter name: ";
getchar();
cin.getline(name,100);
cout<<"\nAddress: ";
cin.getline(address,100);

}



void student::print_data()
{
cout<<"\n\nRoll : "<<roll_no;
cout<<"\n\nName : "<<name;
cout<<"\n\nAddress : "<<address;

}


int main()
{
student s;
int n;
char ch;
do
{
cout<<"Enter data for student\n\n";
s.fileout();
cout<<"Enter another(Y/N):";
cin>>ch;
}while(ch=='Y'||ch=='y');
n=s.countstudent();
for(int i=0;i<n;i++)
{
cout<<"\n\nStudent "<<i+1<<"\n";
s.filein(i);
s.print_data();
}
return 0;
}


