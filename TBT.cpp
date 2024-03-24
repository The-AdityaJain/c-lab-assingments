#include<stdlib.h>
#include<iostream>
#include<cstring>

using namespace std;

class tbtnode{
    char data;
    bool lbit;
    bool rbit;
    tbtnode *rightc;
    tbtnode *leftc;
    friend class tbt;
    public :
        tbtnode();
};
tbtnode::tbtnode(){
    lbit = 0;
    rbit = 0;
}
class tbt{
    tbtnode *head;
    public:
        void create();
        void preorder();
        tbtnode *presuccr(tbtnode *);
        void inorder();
        tbtnode *insuccr(tbtnode *);
        tbt();
};
tbt::tbt(){
    head = new tbtnode;
    head->rbit = 1;
    head->leftc=head;
    head->rightc=head;
}
void tbt::create(){
    tbtnode *root;
    root = new tbtnode;
    char choice = 'y';
    if(head->lbit==0){
        cout<<"Enter data for root : ";
        cin >> root->data;
        head->lbit = 1;
        root->leftc=head;
        root->rightc=head;
        head->leftc=root;
    }
    while(choice=='y'){
        int flag=0;
        tbtnode *temp;
        temp = root;
        tbtnode *curr = new tbtnode;
        cout<< "Enter data for new node : ";
        cin >> curr->data;
        while(flag==0){
            char ch;
            cout<<"Enter choice to add node (l/r) : ";
            cin >> ch;
            if(ch=='l'){
                if(temp->lbit==0){
                    curr->rightc=temp;
                    curr->leftc=temp->leftc;
                    temp->leftc=curr;
                    temp->lbit=1;
                    flag=1;
                }
                else{
                    temp=temp->leftc;
                }
            }
            else if(ch=='r'){
                if(temp->rbit==0){
                    curr->leftc=temp;
                    curr->rightc=temp->rightc;
                    temp->rightc=curr;
                    temp->rbit=1;
                    flag=1;
                }
                else{
                    temp=temp->rightc;
                }
            }
            else{
                cout<<"Enter only (l/r)"<<endl;
            }
        }
        cout<<"Do you wish to continue (y/n) : ";
        cin>>choice;
    }
}
void tbt::inorder(){
    tbtnode *temp=head;
    while(1){
        temp=insuccr(temp);
        if(temp==head){
            break;
        }
        cout<<temp->data<<" ";
    }
}
tbtnode *tbt::insuccr(tbtnode *temp){
    tbtnode *x = temp->rightc;
    if(temp->rbit==1){
        while(x->lbit==1){
            x=x->leftc;
        }
    }
    return x;
}
void tbt::preorder(){
    tbtnode *temp = head->leftc;
    while(temp!=head){
        cout<<temp->data;
        while(temp->lbit!=0){
            temp=temp->leftc;
            cout<<temp->data;
        }
        while(temp->rbit==0){
            temp=temp->rightc;
        }
        temp=temp->rightc;
    }
}
int main(){
    tbt t;
    t.create();
    cout<<"Inorder : ";
    t.inorder();
    cout<<endl;
    cout<<"Preorder : ";
    t.preorder();
}