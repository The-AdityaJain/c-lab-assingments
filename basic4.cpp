#include<iostream>
#include<string>
using namespace std;

class student_info
{
	public:
	string name;
	int roll_no;
	
	void put_data()
	{
		cout<<"Enter Name"<<endl;
		cin>>name;
		cout<<"Enter Roll No"<<endl;
		cin>>roll_no;
	}
	void get_data(){
		cout<<"Name : "<<name<<"\nRoll No. : "<<roll_no<<endl;
	}
};
class course
{
	public:
	string cours;
	void put_data(){
		cout<<"Enter your choice of course\n1.B.tech\n2.B.Sc\n3.B.Des"<<endl;
		cin>>cours;
	
	}
	void get_data(){
		cout<<"Course Name : "<<cours<<endl;
	}
};
class dept:public student_info,public course
{
	public:
	string dep;
	void put_data();
	void get_data();
};
	void dept::put_data()
	{
		student_info::put_data();
		course::put_data();
		cout<<"Enter your branch"<<endl;
		cin>>dep;
	}
	void dept::get_data()
	{
		student_info::get_data();
		course::get_data();
		cout<<"Branch : "<<dep<<endl;
	}
int main(){
	dept d1;
	d1.put_data();
	d1.get_data();
	dept d2;
	d2.put_data();
	d2.get_data();
	dept d3;
	d3.put_data();
	d3.get_data();
return 0;
}
