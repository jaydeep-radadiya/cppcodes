#include<bits/stdc++.h>
using namespace std;

void fastIO(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

class Node{
public:
	int data;
	Node *next;
};

Node *last = NULL;

void printlinkedlist(){
	if(last==NULL){
		cout<<"list is empty"<<"\n";
		return;
	}
	// points to first node of list
	Node *ptr = last->next;
	do{
		cout<<ptr->data<<" ";
		ptr = ptr->next;
	}while(ptr!=last->next);
	cout<<"\n";
}

void addatbeginning(int val){
	Node *temp = new Node();
	temp->data = val;
	temp->next = last->next;
	last->next = temp;
}

void addtoempty(int val){
	Node *temp = new Node();
	temp->data = val;
	last = temp;
	last->next = last;
}

void addatend(int val){
	Node *temp = new Node();
	temp->data = val;
	temp->next = last->next;
	last->next = temp;
	last = temp;
}

void addafter(int target,int val){
	if(last==NULL){
		cout<<"list is empty"<<"\n";
		return;
	}
	Node *ptr = last->next;
	do{
		if(ptr->data==target){
			Node *temp = new Node();
			temp->data = val;
			temp->next = ptr->next;
			ptr->next = temp;
			if(ptr==last)
				last = temp;
			return;
		}
		ptr = ptr->next;
	}while(ptr!=last->next);
	cout<<"target is not found in the list"<<"\n";
}

void deletefirstnode(){
	Node *temp = last->next;
	last->next = last->next->next;
	delete temp;
}

void deleteonlynode(){
	delete last;
	last = NULL;
}

void deletebetween(int val){
	Node *ptr = last->next;
	while(ptr->next!=last){
		if(ptr->next->data==val){
			Node *temp = ptr->next;
			ptr->next = temp->next;
			delete temp;
			return;
		}
		ptr = ptr->next;
	}
	if(last->data==val){
		Node *temp = last;
		ptr->next = last->next;
		last = ptr;
		delete temp;
		return;
	}
	cout<<"value not found in the list"<<"\n";
}

int main(){
	fastIO();

	addtoempty(12);
	addatend(24);
	addafter(12,20);
	addatbeginning(10);
	printlinkedlist();

	return 0;
}