#include<bits/stdc++.h>
using namespace std;

void fastIO(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

class Node{
public:
	int data;
	Node *prev;
	Node *next;
};

Node *head = NULL;

// print the list
void printlinkedlist(){
	Node *ptr = head;
	if(ptr==NULL){
		cout<<"list is empty"<<"\n";
		return;
	}
	else{
		while(ptr!=NULL){
			cout<<ptr->data<<" ";
			ptr = ptr->next;
		}
		cout<<"\n";
	}
}

// add value at the beginning
void addatbeginning(int val){
	Node *temp = new Node();
	temp->data = val;
	temp->next = head;
	temp->prev = NULL;
	head->prev = temp;
	head = temp; 
}

// add value in the empty list
void addtoempty(int val){
	Node *temp = new Node();
	temp->data = val;
	temp->next = NULL;
	temp->prev = NULL;
	head = temp;
}

// add value at the end
void addatend(int val){
	Node *ptr = head;
	while(ptr->next!=NULL)
		ptr = ptr->next;
	Node *temp = new Node();
	temp->data = val;
	temp->next = NULL;
	temp->prev = ptr;
	ptr->next = temp;
}

// add node after the target 
void addafter(int target,int val){
	Node *ptr = head;
	while(ptr!=NULL){
		if(ptr->data==target){
			Node *temp = new Node();
			temp->data = val;
			temp->prev = ptr;
			temp->next = ptr->next;
			if(ptr->next!=NULL)
				ptr->next->prev = temp;
			ptr->next = temp;
			return;
		}
		ptr = ptr->next;
	}
	cout<<"target value is not present in the list"<<"\n";
}

// add node before the target 
void addbefore(int target,int val){
	Node *ptr = head;
	if(ptr==NULL){
		cout<<"list is empty"<<"\n";
		return;
	}
	else if(ptr->data==target){
		addatbeginning(val);
	}
	else{
		while(ptr!=NULL){
			if(ptr->data==target){
				Node *temp = new Node();
				temp->data = val;
				temp->prev = ptr->prev;
				temp->next = ptr;
				ptr->prev->next = temp;
				ptr->prev = temp;
			}
			ptr = ptr->next;
		}
		cout<<"target is not present in the list"<<"\n";
	}
}

// delete the first node
void deletefirstnode(){
	Node *temp = head;
	head = head->next;
	head->prev = NULL;
	delete temp;
}

// delete value node which is between the list
void deletebetween(int val){
	Node *temp = head;
	while(temp->next!=NULL){
		if(temp->data==val){
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			delete temp;
			return;
		}
		temp = temp->next;
	}
	cout<<"val is not present in the list"<<"\n";
}

// delete the last node
void deletelastnode(){
	Node *temp = head;
	while(temp->next!=NULL)
		temp = temp->next;
	temp->prev->next = temp->next;
	delete temp;
}

// reverse the list
void reverselist(){
	Node *p1,*p2;
	p1 = head;
	p2 = head->next;
	p1->next = NULL;
	p1->prev = p2;
	while(p2!=NULL){
		p2->prev = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p2->prev;
	}
	head = p1;
}

int main(){
	fastIO();

	addtoempty(12);
	addatbeginning(10);
	addatend(15);
	addafter(10,11);
	deletebetween(12);
	reverselist();
	printlinkedlist();

	return 0;
}