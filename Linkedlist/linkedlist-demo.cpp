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

// count the length of list
int lengthoflist(){
	Node *ptr = head;
	int cnt = 0;
	while(ptr!=NULL){
		ptr = ptr->next;
		cnt++;
	}
	return cnt;
}

// search target by position
void searchbypos(int target){
	Node *ptr = head;
	int pos = 0;
	while(ptr!=NULL){
		if(ptr->data==target){
			cout<<"value found at position "<<pos<<"\n";
			return;
		}
		ptr = ptr->next;
		pos++;
	}
	cout<<"value not found in the list"<<"\n";
}

// add value at the beginning
void addatbeginning(int val){
	Node *temp = new Node();
	temp->data = val;
	temp->next = head;
	head = temp;
}

// add value at the end
void addatend(int val){
	Node *ptr = head;
	while(ptr->next!=NULL){
		ptr = ptr->next;
	}
	Node *temp = new Node();
	temp->data = val;
	temp->next = NULL;
	ptr->next = temp;
}

// add node after the target value
void addafter(int target,int data){
	Node *ptr = head;
	while(ptr!=NULL){
		if(ptr->data==target){
			Node *temp = new Node();
			temp->data = data;
			temp->next = ptr->next;
			ptr->next = temp;
			return;
		}
		ptr = ptr->next;
	}
	cout<<"target value is not present in the list"<<"\n";
}

// add node before the target value
void addbefore(int target,int data){
	Node *ptr = head;
	if(ptr==NULL){
		cout<<"list is empty"<<"\n";
		return;
	}
	else if(ptr->data==target){
		addatbeginning(data);
	}
	else{
		while(ptr->next!=NULL){
			if(ptr->next->data==target){
				Node *temp = new Node();
				temp->data = data;
				temp->next = ptr->next;
				ptr->next = temp;
				return;
			}
			ptr = ptr->next;
		}
		cout<<"target is not present in the list"<<"\n";
	}
}

// add node at the given position
void addatpos(int pos,int data){
	Node *ptr = head;
	if(pos==1){
		addatbeginning(data);
		return;
	}
	for(int i=1;i<pos-1 && ptr!=NULL;i++)
		ptr = ptr->next;
	if(ptr==NULL)
		cout<<"you entered invalid position"<<"\n";
	else{
		Node *temp = new Node();
		temp->data = data;
		temp->next = ptr->next;
		ptr->next = temp;
	}
}

// delete the first node
void deletefirstnode(){
	Node *temp = head;
	head = head->next;
	delete temp;
}

// delete val node which is between the list
void deletebetween(int val){
	Node *ptr = head;
	while(ptr->next!=NULL){
		if(ptr->next->data==val){
			Node *temp = ptr->next;
			ptr->next = temp->next;
			delete temp;
			return;
		}
		ptr = ptr->next;
	}
	cout<<"value not found in the list"<<"\n";
}

// delete the last node 
void deletelastnode(){
	Node *ptr = head;
	while(ptr->next->next!=NULL)
		ptr = ptr->next;
	Node *temp = ptr->next;
	ptr->next = temp->next;
	delete temp;
}

// reverse the list
void reverselist(){
	Node *prev,*ptr,*next;
	prev = NULL;
	ptr = head;
	while(ptr!=NULL){
		next = ptr->next;
		ptr->next = prev;
		prev = ptr;
		ptr = next;
	}
	head = prev;
}

int main(){
	fastIO();

	addatbeginning(11);
	addatend(13);
	addatbeginning(15);
	addafter(11,25);
	addbefore(13,20);
	addatpos(2,18);
	deletefirstnode();
	deletebetween(20);
	deletelastnode();
	printlinkedlist();
	reverselist();
	printlinkedlist();

	return 0;
}