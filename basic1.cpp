#include <iostream>

using namespace std;
class actor 
{
    public:
        string name;
        int age;
        bool gender;
        int hits;
        int flops;
};

int main()
{
    actor arr[3];
    arr[0].name="kartik";
    arr[0].age=24;
    arr[0].gender=1;
    arr[0].hits=3;
    arr[0].flops=2;
    
    arr[1].name="kiara";
    arr[1].age=27;
    arr[1].gender=0;
    arr[1].hits=4;
    arr[1].flops=1;
    
    arr[2].name="sidd";
    arr[2].name=30;
    arr[2].gender=1;
    arr[2].hits=8;
    arr[2].flops=4;
    
    for(int i=0;i<=2;i++){
        cout<<"name = ";
        std::cout << arr[i].name << std::endl;
         cout<<"age = ";
        std::cout << arr[i].age << std::endl;
         cout<<"gender = ";
        std::cout << arr[i].gender << std::endl;
         cout<<"hits = ";
        std::cout << arr[i].hits << std::endl;
         cout<<"flops = ";
        std::cout << arr[i].flops << std::endl;
    }
    return 0;
}
