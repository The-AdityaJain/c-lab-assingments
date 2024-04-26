#include<iostream>
using namespace std;

class node {
public:
    int user_id;
    string user_data;
    node* next;
    friend class graph;
};
class queue{
	int qu[20];
	int rear;
	int front;
	friend class graph;
	public:
	queue()
	{
		rear = -1;
		front = -1;
	}
	void insert(int );
	int deleted();
	int isempty();
};


void queue :: insert(int temp){
	rear++;
	qu[rear] = temp;
}

int queue :: deleted(){
	front++;
	int temp = qu[front];
	return temp;
}

int queue :: isempty(){
	if (front == rear){
		return 1;
	}
	else{
		return 0;
	}
};

class stack {
    int st[20];
    int top;
    friend class graph;
public:
    stack() {
        top = -1;
    }
    void push(int );
    int pop();
    int isempty();
};

void stack::push(int temp) {
    top++;
    st[top] = temp;
}

int stack::pop() {
    int t;
    t = st[top];
    top--;
    return t;
}

int stack::isempty() {
    if (top == -1) {
        return 1;
    }
    else
        return 0;
}

class graph {
    friend class stack;
public:
    void create_adj_list();
    void display();
    node* head[14];
    int visited[16];
    int n;
    void DFT_recursive();
    void DFT_rec(int );
    void DFT_nonrec();
    void BFT_nonrec();
};

void graph::create_adj_list() {
    cout << "enter no of vertices" << endl;
    cin >> n;
    char ch, choice;
    node* temp, * curr;

    for (int i = 0; i < n; i++) {
        head[i] = new node();
        head[i]->user_id = i;
        cout << "enter the name of user " << i << endl;
        cin >> head[i]->user_data;
        head[i]->next = NULL;
    }

    for (int i = 0; i < n; i++) {
        temp = head[i];
        do {
            cout << "Is there any vertex connected with user " << head[i]->user_id << " ?" << endl;
            cin >> ch;
            if (ch == 'y') {
                curr = new node();
                cout << "Enter connected user_id" << endl;
                cin >> curr->user_id;
                curr->user_data = head[curr->user_id]->user_data;
                cout<<"the connected name is : "<<curr->user_data<<endl;
                curr->next = NULL;
                temp->next = curr;
                temp = curr;
            }
            cout << "Do you want to add more? "<<endl;
            cin >> choice;
        } while (choice == 'y');
    }
}

void graph::display() {
    for (int i = 0; i < n; i++) {
        node* temp = head[i]->next;
        cout << "the connections of user " << head[i]->user_id << " are " << endl;
        while (temp != NULL) {
            cout << "the user id is " << temp->user_id << " and the name of user is " << temp->user_data << endl;
            temp = temp->next;
        }
    }
}

void graph::DFT_recursive() {
	int v;
	cout<<"enter start vertex id";
	cin>>v;
	for(int i=0;i<n;i++){
		visited[i] = 0;
	}
	visited[v] = 1;
	DFT_rec(v);
}

void graph::DFT_rec(int v) {
	cout<<v<<"->"<<head[v]->user_data<<endl;
	node *temp;
	temp = head[v]->next;
	while(temp!=NULL){
		if(visited[temp->user_id] == 0){
			visited[temp->user_id] = 1;
			DFT_rec(temp->user_id);
		}
		temp = temp->next;
	}
}

void graph :: DFT_nonrec(){
	int v;
	cout<<"enter start vertex id"<<endl;
	cin>>v;
	stack s;
	for(int i=0;i<n;i++){
		visited[i] = 0;
	}
	visited[v] = 1;
	s.push(v);
	while(s.isempty() == 0){
		v = s.pop();
		cout<<v<<"->"<<head[v]->user_data<<endl;
		node *temp =head[v]->next;
		while(temp != NULL){
			if(visited[temp->user_id] == 0){
				s.push(temp->user_id);
				visited[temp->user_id] = 1;
			}
		temp = temp->next;
		}
	}
}

void graph :: BFT_nonrec(){
	int v;
	cout<<"enter start vertex id"<<endl;
	cin>>v;
	queue q;
	for(int i=0;i<n;i++){
		visited[i] = 0;
	}
	visited[v] = 1;
	q.insert(v);
	while(q.isempty() == 0){
		v = q.deleted();
		cout<<v<<"->"<<head[v]->user_data<<endl;
		node *temp =head[v]->next;
		while(temp != NULL){
			if(visited[temp->user_id] == 0){
				q.insert(temp->user_id);
				visited[temp->user_id] = 1;
			}
		temp = temp->next;
		}
	}
}

int main() {
    graph g;
    g.create_adj_list();
    g.display();
    //g.DFT_recursive();
    //g.DFT_nonrec();
    g.BFT_nonrec();
    return 0;
}
