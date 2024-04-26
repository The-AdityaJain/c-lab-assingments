#include<iostream>
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
		void create_r();
		void create_r(treenode *);
		void inorder_r();
		void inorder_r(treenode *);
		void preorder_r();
		void preorder_r(treenode *);
		void postorder_r();
		void postorder_r(treenode *);

		void create_nr();
		void inorder_nr();
		//void inorder_nr(treenode *);
		void preorder_nr();
		//void preorder_nr(treenode *);
		void postorder_nr();
		//void postorder_nr(treenode *);
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
//****************************************************Recursive Code*********************************************************//
void tree::create_r(){
	root = new treenode;
	cout<<"Enter data for root"<<endl;
	cin>>root->data;
	root->left=NULL;
	root->right=NULL;
	create_r(root);
}
void tree::create_r(treenode *temp){
	char ch;
	cout<<"input choice at left of "<<temp->data<<" y/n"<<endl;
	cin>>ch;
	if(ch=='y'){
		treenode *curr;
		curr = new treenode;
		cin>>curr->data;
		curr->left=NULL;
		curr->right=NULL;
		temp->left=curr;
		create_r(curr);
	}
	cout<<"input choice at right of "<<temp->data<<" y/n"<<endl;
	cin>>ch;
	if(ch=='y'){
		treenode *curr;
		curr = new treenode;
		cin>>curr->data;
		curr->left=NULL;
		curr->right=NULL;
		temp->right=curr;
		create_r(curr);
	}
}
//Inorder
void tree::inorder_r(){
	inorder_r(root);
}
void tree::inorder_r(treenode *temp){
	if(temp!=NULL){
		inorder_r(temp->left);
		cout<<temp->data;
		inorder_r(temp->right);
	}
}
//Preorder
void tree::preorder_r(){
	preorder_r(root);
}
void tree::preorder_r(treenode *temp){
	if(temp!=NULL){
		cout<<temp->data;
		preorder_r(temp->left);
		preorder_r(temp->right);
	}
}
//Postorder
void tree::postorder_r(){
	postorder_r(root);
}
void tree::postorder_r(treenode *temp){
	if(temp!=NULL){
		postorder_r(temp->left);
		postorder_r(temp->right);
		cout<<temp->data;
	}
}
//****************************************************Non - Recursive Code*********************************************************//
void tree ::create_nr(){
	int flag;
	char ch,lr;
	treenode *temp,*curr;
	
	if(root==NULL){
		root = new treenode;
		cout<<"enter data for root :"<<endl;
		cin>>root->data;
		root->left=NULL;
		root->right=NULL;
	}

	do{	
		temp = root;
		flag = 0;
		curr = new treenode;
		cout<<"Enter data for new node"<<endl;
		cin>>curr->data;
		curr->left=NULL;
		curr->right=NULL;

		while(flag==0){
			cout<<"Add node to left(l) or right(r)"<<endl;
			cin>>lr;
			if(lr=='l'){
				if(temp->left==NULL){
					temp->left = curr;
					flag=1;
				}
				temp=temp->left;
			}
			else if(lr=='r'){
				if(temp->right == NULL){
					temp->right = curr;
					flag=1;
				}
				temp = temp->right;
			}
			else{
				cout<<"choice should be l or r only"<<endl;
			}
		}
		cout<<"Do you choose to continue(y/n)"<<endl;
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
		cout<<"\t"<<temp->data;
		temp = temp->right;
	}

}
void tree ::postorder_nr(){
	treenode *temp;
	temp=root;
	stack st;
	while(1){
		while(temp!=NULL){
			st.push(temp);
			temp = temp->left;
		}
		if(st.data[st.top]->right==NULL){
			temp = st.pop();
			cout<<"\t"<<temp->data;
		}
		while(!st.empty() && st.data[st.top]->right==temp){
			temp = st.pop();
			cout<<"\t"<<temp->data;
		}
		if(st.empty()){
			break;
		}
		temp = st.data[st.top]->right;
	}
}
int main(){
	tree bt;
	// bt.create_r();
	// cout<<"Inorder :";
	// bt.inorder_r();
	// cout<<"\n";
	// cout<<"Preorder :";
	// bt.preorder_r();
	// cout<<"\n";
	// cout<<"Postorder :";
	// bt.postorder_r();
	// cout<<"\n";
	bt.create_nr();
	cout<<"Inorder : ";
	bt.inorder_nr();
	cout<<"\n";
	cout<<"Postorder : ";
	bt.postorder_nr();
	cout<<"\n";
	return 0;
}
