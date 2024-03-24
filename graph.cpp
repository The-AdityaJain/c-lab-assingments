#include<iostream>
using namespace std;
#define MAX 100
class Gnode{
    int vertex;
    Gnode *next;
    friend class Graph;
};
class Graph{
    private:
        Gnode *head[20];
        int n;
    public:
        int visited[20];
        void graph();
        void create();
        void DFS();
        void DFST(int );
};
void Graph::graph(){
    cout<<"Enter no. of vertex : ";
    cin>>n;
    for(int i = 1;i <= n-1;i++){
        head[i] = new Gnode;
        head[i]->vertex=i;
        head[i]->next=NULL;
    }
};
void Graph::create(){
    Gnode *curr,*temp;
    char choice;
    int v;
    for(int i = 1;i <= n-1;i++){
        temp = head[i];
        cout<<"Do you want to start? for "<<temp->vertex<<" : ";
        cin>>choice;
        while(choice=='y'){
            cout<<"Enter the vertex : ";
            cin>>v;
            curr = new Gnode;
            curr->vertex=v;
            curr->next=NULL;
            temp->next=curr;
            temp=temp->next;
            cout<<"Do you wish to continue(y/n)? : ";
            cin>>choice;
        }
    }
};
void Graph::DFS(){
    int v;
    for(int i  = 1;i <= n-1;i++){
        visited[i]=0;
    }
    cout<<"Enter first vertex : ";
    cin>>v;
    DFST(v);
}
void Graph::DFST(int v){
    int w;
    Gnode *curr = head[v]->next;
    cout<<v;
    visited[v]=1;
    while(curr!=NULL){
        w = curr->vertex;
        if(visited[w]!=1){
            DFST(w);
        }
        curr=curr->next;
    }

}
int main(){
    Graph g;
    g.graph();
    g.create();
    g.DFS();
}