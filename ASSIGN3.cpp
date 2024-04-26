#include<iostream>
#include<string.h>
using namespace std;

class node{

	string word;
	string mean;
	node *left,*right;
	friend class bintree;
	
};

class queue{
	node* qu[20];
	int rear;
	int front;
	friend class bintree;
	public:
	queue()
	{
		rear = -1;
		front = -1;
	}
	void insert(node*);
	node* deleted();
	int isempty();
};


void queue :: insert(node * temp){
	rear++;
	qu[rear] = temp;
}

node* queue :: deleted(){
	front++;
	node* temp = qu[front];
	return temp;
}

int queue :: isempty(){
	if (front == rear){
		return 1;
	}
	else{
		return 0;
	}
}
 
class bintree{
	
	node *root;
	friend class queue;
	public:
	void create_BST();
	void create_BST(node *);
	void inorder();
	void inorder(node *);
	void mirror_rec();
	void mirror_rec(node *);
	node* copy_tree_rec();
	node* copy_tree_rec(node *);
	void level_wise();
	void level_wise(node *);
	void delete_BST();
	void delete_BST(node *);
	
};

void bintree :: create_BST(){
	root = new node();
	cout<<"enter root data for word"<<endl;
	cin>>root->word;
	cout<<"enter root data for meaning"<<endl;
	cin>>root->mean;
	root->left = root->right = NULL;
	create_BST(root);
}

void bintree :: create_BST(node *root){
	char choice = 'y';
	do{
		int flag = 0;
		node *temp = root;
		node *curr = new node();
		cout<<"enter data for word"<<endl;
		cin>>curr->word;
		cout<<"enter data for meaning"<<endl;
		cin>>curr->mean;
		curr->left = curr->right = NULL;
		while(flag == 0){
			if(curr->word <= temp->word){
				if(temp->left == NULL){
					temp->left = curr;
					flag = 1;
					break;
				}
				else{
					temp = temp->left;
					flag = 0;
				}
			}
				
			else{
				if(temp->right == NULL){
					temp->right = curr;
					flag = 1;
					break;
				}
				else{
					temp = temp->right;
					flag = 0;
				}
			}
		}
		cout<<"do you want to add more(y/n)"<<endl;
		cin>>choice;
	}while(choice == 'y');
}

void bintree :: inorder(){
	inorder(root);
};

void bintree :: inorder(node * root){
	if(root != NULL){
		inorder(root->left);
		cout<<root->word<<"-"<<root->mean<<endl;
		inorder(root->right);
	}
}

void bintree :: mirror_rec(){
	mirror_rec(root);
}

void bintree :: mirror_rec(node* root){
	node *temp;
	temp = root->left;
	root->left = root->right;
	root->right = temp;
	
	if(root->left !=NULL){
		mirror_rec(root->left);
	}
	if(root->right != NULL){
		mirror_rec(root->right);
	}
}

node* bintree :: copy_tree_rec(){
	node* t1 = copy_tree_rec(root);
	inorder(t1);
}

node* bintree :: copy_tree_rec(node *root){
	node* temp = NULL;
	if(root != NULL){
		temp = new node();
		temp->word = root->word;
		temp->mean = root->mean;
		temp->left = copy_tree_rec(root->left);
		temp->right = copy_tree_rec(root->right);
	}
	return temp;
}

void bintree :: level_wise(){
	level_wise(root);
}

void bintree :: level_wise(node *root){
	queue q;
	q.insert(root);
	while(q.isempty() == 0){
		node * temp = q.deleted();
		cout<<temp->word<<"-"<<temp->mean<<endl;
		if(temp->left != NULL){
			q.insert(temp->left);
		}
		if(temp->right != NULL){
			q.insert(temp->right);
		}
	}
}
		
void bintree :: delete_BST(){
	delete_BST(root);
}

void bintree :: delete_BST(node * root){
	string key;
	cout<<"enter the word you want to delete"<<endl;
	cin>>key;
	node *temp = root;
	node *parent = NULL;
	while(temp != NULL){
		if(temp->word == key){
			break;
		}
		else if(temp->word > key){
			parent = temp;
			temp = temp->left;
		}
		else{
			parent = temp;
			temp = temp->right;
		}
	}
	
	if(temp->left == NULL && temp->right == NULL){
		if(parent->right == temp){
			parent->right = NULL;
		}
		else{
			parent->left = NULL;
		}
		delete(temp);
	}
	else if(temp->left == NULL && temp->right != NULL){
		if(parent->right == temp){
			parent->right = temp->right;
		}
		else{
			parent->left = temp->right;
		}
		temp->right = NULL;
		delete(temp);
	}
	else if(temp->left != NULL && temp->right == NULL){
		if(parent->right == temp){
			parent->right = temp->left;
		}
		else{
			parent->left = temp->left;
		}
		temp->left= NULL;
		delete(temp);
	}
	else{
		node *s = temp->left;
		node *r = temp->right;
		if(parent->right == temp){
			parent->right = r;
		}
		else{
			parent->left = r;
		}
		while(r->left != NULL){
			r = r->left;
		}
		r->left= s;
		temp->right=NULL;
		delete(temp);
	}
}
	

int main(){
	
	bintree t;
	t.create_BST();
	cout<<"the inorder of above tree is:"<<endl;
	t.inorder();
	cout<<"the mirror image of above tree is:"<<endl;
	t.mirror_rec();
	cout<<"the inorder of above tree is after mirror image is:"<<endl;
	t.inorder();
	//cout<<"the inorder of above tree after copy is:"<<endl;
	//t.copy_tree_rec();
	cout<<"the level wise traversal is"<<endl;
	t.level_wise();
	t.delete_BST();
	cout<<"the inorder of above tree after deletion is"<<endl;
	t.inorder();
	return 0;
}

