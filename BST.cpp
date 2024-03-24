//#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
#include<cstring>

#define MAX 100;
using namespace std;

class treenode{
	char data[10];
	treenode *left;
	treenode *right;
	friend class tree;
};
class tree{
	treenode *root;
	public:
		tree();
		void create_nr();
		void inorder_nr();
        void BFS();

		void mirror_r();
		void mirror_r(treenode *);
        
		void copy_r();
		treenode *copy_r(treenode *);

		void delete(treenode *,treenode *);

		
};
tree::tree(){
	root = NULL;
}
class stack{
    int top;
    treenode *data[30];
    public:
    stack() {
        top=-1;
    }
    void push(treenode *temp) ;
    treenode *pop();
    int empty();
    friend class tree;
};
void stack ::push(treenode *temp){
    data[++top] = temp;
}
treenode* stack ::pop(){
	treenode *temp;
	temp = data[top];
	top--;
	return temp;
}
int stack ::empty(){
	if(top==-1){
		return 1;
	}
	else{
		return 0;
	}
}
class queue{
    int front,rear;
    treenode *data[10];
    public:
    queue(){
        front = -1;
        rear = -1;
    }
    void AddQ(treenode *temp);
    treenode *DeleteQ();
    int isEmpty();
    friend class tree;

};
void queue::AddQ(treenode *temp){
    rear=rear+1;
    data[rear]=temp;
}
treenode *queue::DeleteQ(){
    treenode *temp;
    front = front + 1;
    temp = data[front];
    return temp;
}
int queue ::isEmpty(){
	if(front==rear){
		return 1;
	}
	return 0;
}
void tree::create_nr(){
	int flag;
	char ch;
	treenode *temp,*curr;

	if(root==NULL){
		root = new treenode;
		cout<<"Enter the root : ";
		cin>>root->data;
		root->right= NULL;
		root->left= NULL;
	}

	do{
		temp = root;
		flag = 0;

		curr = new treenode;
		cout<<"Enter the data for new word : ";
		cin>>curr->data;	
		curr->left=NULL;
		curr->right=NULL;	

		while(flag==0){
			
			int cmp = strcmp(curr->data,temp->data);

			if(cmp<0){
				if(temp->left==NULL){
					temp->left=curr;
					flag=1;
				}
				temp=temp->left;
			}
			else if(cmp>0){
				if(temp->right==NULL){
					temp->right=curr;
					flag=1;
				}
				temp=temp->right;
			}
			else if(cmp==0){
				cout<<"The word already exists"<<endl;
			}
		}
		cout<<"Do you want to continue(y/n) : ";
		cin>>ch;
	}while(ch=='y');
}

void tree ::inorder_nr(){
	treenode *temp;
	temp=root;
	stack st;
	while(1){
		while(temp!=NULL){
			st.push(temp);
			temp = temp->left;
		}
		if(st.empty()){
			break;
		}
		temp = st.pop();
		cout<<temp->data<<"\t";
		temp = temp->right;
	}

}
void tree::BFS(){
    queue q;
    treenode *temp;
    if(root==NULL){
        cout<<"BST is empty!"<<endl;
    }
    else{
        int p=1,r=0;
        temp = root;
        q.AddQ(temp);
        while(!q.isEmpty()){
            for(int i = 0; i<p;i++){
                temp = q.DeleteQ();
                cout << temp -> data<< "\t";
                if(temp -> left != NULL){
                    q.AddQ(temp->left);
                    r++;
                }
				if(temp->right != NULL){
                    q.AddQ(temp->right);
                    r++;
                }
            }
            cout << endl;
            p=r;
            r=0;
        }
    }
    
}
void tree::mirror_r(){
	mirror_r(root);
	BFS();
}
void tree::mirror_r(treenode *temp){
	if(temp!=NULL){
		treenode *temp2 = new treenode;
		temp2 = temp->left;
		temp->left=temp->right;
		temp->right=temp2;
		if(temp->left!=NULL){
			mirror_r(temp->left);
		}
		if(temp->right!=NULL){
			mirror_r(temp->right);
		}
	}
}
void tree::copy_r(){
	treenode *root1;
	root1 = copy_r(root);
	BFS();
}
treenode *tree::copy_r(treenode *root){
    treenode *temp = NULL;
    if(root!=NULL){
        treenode *curr = new treenode;
		curr = root;
        temp =  new treenode;
        strcpy(temp->data,curr->data);
		temp -> left = copy_r(curr->left);
		temp -> right = copy_r(curr->right);
    }
}
void tree:: delete_node(treenode *parent,treenode *temp){ 
	
	c=0; //case variable
	if(temp!=root){ //deletion of node which is not root	
		if((temp->left == NULL) && (temp->right == NULL)) //deletion of a leaf // case 1
			c=1;
		else{
			//node with one child //case 2
			if((temp->left = NULL)&& (temp->right != NULL) || (temp->left != NULL) && (temp->right = NULL))
				c=2;
			else{
				if((temp->left != NULL) && (temp->rightc != NULL)) //both children //case 3
					c=3;
			}
		}
	}
	else{
		c=4 // delete root
	}
}
int main(){
	tree bt;
	bt.create_nr();
	//cout<<"Inorder : "<<endl
	//bt.inorder_nr();
    cout<<"BFS : "<<endl;
	bt.BFS();
	cout<<"Mirrored Tree : "<<endl;
	bt.mirror_r();
	cout<<"Copied tree :"<<endl;
	bt.copy_r();
    return 0;
}