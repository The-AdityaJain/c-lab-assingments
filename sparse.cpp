#include<iostream>
using namespace std;

int i,j,k;

void accept(int a[10][10],int m,int n){
    cout<<"Enter elements :"<<endl;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++)
            cin>>a[i][j];
    }
}
void display(int a[10][10],int m,int n){
    cout<<"Sparse Matrix :"<<endl;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            cout<<a[i][j]<<"\t";
        }
        cout<<"\n";
    }

}

void sparse_mat(int a[10][10],int m,int n){
    int B[10][10];
    B[0][0]=m;
    B[0][1]=n;
    int t=0;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(a[i][j]!=0){
                B[t][0]=i;
                B[t][1]=j;
                B[t][2]=a[i][j];
                t++;
            }
        }
    }
    cout<<"Compact matrix :"<<endl;
    for(i=0;i<t;i++){
        for(j=0;j<3;j++){
            cout<<B[i][j]<<"\t";
        }
        cout<<"\n";
    }
}

int main(){
    int m,n;
    cout<<"Enter no of rows : ";
    cin>>m;
    cout<<"Enter no of column : ";
    cin>>n;
    int a[m][10];
    accept(a,m,n);
    display(a,m,n);
    sparse_mat(a,m,n);
    
    
}
