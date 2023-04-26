#include<iostream>
using namespace std;
class Shape{
	public :
		int h,w,r;
			
		virtual void area(int h,int w,int r){
			}
};
class Circle : public Shape {
	public :
		int r;
	
		void area(int r){
		
			cout<<"Enter radius"<<endl;
			cin>>r;
			cout<<"Area of circle :"<<3.14*r*r<<endl;
		}
};
class Rectangle : public Shape {
	public :
		int h;
		int w;
		void area(int h,int w){
		
			cout<<"Enter ht. and wt."<<endl;
			cin>>h>>w;
			cout<<"Area of Rectangle :"<<h*w<<endl;
		}
};
int main(){
int h,w,r;
Shape s1;
Circle c1;
c1.area(r);
Rectangle r1;
r1.area(h,w);


	return 0;
}
