#include<iostream>
#include<string.h>

using namespace std;

class data {
	public :
	
	int price;
	string dish;
		
		void get_data(){
	
			cout<<"Enter price"<<endl;
			cin>>price;
			cout<<"Enter dish"<<endl;
			cin>>dish;
		}
	
		void error(){
		
			try{
				if(price<100 || price>200){
				throw 1;
				}
				else if(dish == "chicken","sea food","egg"){
				throw 2;
				}
			}
			catch(int n){
				switch(n){
				case 1:
				cout<<("Invalid Price!!!Our cafe have pdt b/w Rs.100 to Rs.200")<<endl;
				case 2:
				cout<<("This is a Pure Veg cafe.No non-veg dishes")<<endl;
				break;
				}
			}
		
		}
};
int main(){

data d1;
d1.get_data();
d1.error();

return 0;
}
