#include <bits/stdc++.h>

using namespace std;

#define MAX 50

int prims(int n,int cost[10][10],int stv,int nearest[10],int t[10][3]){
    int min,r,j,min_cost=0;
    nearest[stv]=-1;
    for(int i = 0;i < n;i++){
        if(i!=stv){
            nearest[i]=stv;
        }
    }
    r=0;
    for(int i = 0;i < n-1;i++){
        min=999;
        for(int k = 0;k < n;k++){
            if(nearest[k]!=-1 && cost[k][nearest[k]]<min){
                j=k;
                min = cost[k][nearest[k]];
            }
        }
        t[r][0]=j;
        t[r][1]=nearest[j];
        t[r][2]=cost[j][nearest[j]];
        r++;
        min_cost = min_cost + cost[j][nearest[j]];
        nearest[j]=-1;
        for(int k = 0;k < n;k++){
            if(nearest[k]!=-1 && cost[k][nearest[k]]>cost[k][j]){
                nearest[k]=j;
            }
        }
    }
    return min_cost;
}
int main() {
    // Your code here
    int n;
    cout<<"Enter no. of vertex : ";
    cin>>n;
    int cost[10][10],stv,nearest[10],t[10][3],cost_v,minimum_cost;
    for(int i = 0;i<n;i++){
        for(int j=i;j<n;j++){
            if (i==j)
            {
                cost[i][i]=999;
            }
            else{
                cout<<"Enter cost for "<<i<<" "<<j<<" : ";
                cin>>cost_v;
                cost[i][j]=cost_v;
                cost[j][i]=cost_v;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<cost[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"Enter the starting vertex : ";
    cin>>stv;
    minimum_cost = prims(n,cost,stv,nearest,t);
    cout<<minimum_cost;

    return 0;
}
