#include<iostream>
#include<fstream>
using namespace std;

template<class T>
class Calculator{
	private: T i,j;
	public:
	Calculator(T a, T b){
	i=a;
	j=b;
}
	void display(){
	cout<<"Addition : "<<i+j<<endl;
	cout<<"Multiplication : "<<i*j<<endl;
	cout<<"Substraction : "<<i-j<<endl;
	}	
};

int main(){
	float i,j;
	cout<<"Enter I"<<endl;
	cin>>i;
	cout<<"Enter J"<<endl;
	cin>>j;
	Calculator<float>Calc(i,j);
	Calc.display();

	return 0;

}
