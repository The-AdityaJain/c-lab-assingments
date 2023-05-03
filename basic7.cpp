#include<iostream>
#include<fstream>
using namespace std;

int main(){
	string str;
	ifstream input("pqr.txt");
	ofstream output("qwerty.txt");
	if(input && output){
		while(getline(input,str)){
			output<<str<<endl;
		}
	
	}
		else{
		cout<<"cannot read file"<<endl;

		}
	input.close();
	output.close();
	return 0;

}
