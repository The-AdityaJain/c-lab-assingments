#include<iostream>
#include<string>

using namespace std;

class employee
{
public:
string name;
bool gender;
string dept;
float salary;


employee(){

	name = "ashwin";
	gender = true;
	dept = "HR";
	salary = 40000;
}
employee(string name,bool gender,string dept,int salary){

	name = "ashwin";
	gender = true;
	dept = "HR";
	salary = 40000;
}

employee(employee &e1){
	name = e1.name;
	gender = e1.gender;
	dept = e1.dept;
	salary = e1.salary;
}

~employee(){
		cout<<"Contructor destroyed"<<endl;
}

inline float netpay(){

	return salary*0.5+salary*0.4;
		cout<<"this is not pay"<<endl;

}
void display(){
cout<<name<<"\t"<<gender<<"\t"<<dept<<"\t"<<salary<<"\t"<<netpay()<<"\t"<<endl;
}
void display1(){
cout<<"Name"<<"\t"<<"Gender"<<"\t"<<"Dept"<<"\t"<<"Salary"<<"\t"<<"Netpay"<<"\t"<<endl;
}

};
int main(){

employee e1;

	e1.name = "Kashish";
	e1.gender = false;
	e1.dept = "CEO";
	e1.salary = 200000000;

		e1.display1();
		e1.display();
return 0;
}
