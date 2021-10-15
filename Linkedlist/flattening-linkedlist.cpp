class Node{
	int data;
	Node *next;
	Node *bottom;

	Node(int data){
		this->data = data;
		this->next = NULL;
		this->bottom = NULL;
	}
}

Node *mergeTwoLists(Node *a,Node *b){
	Node *temp = new Node(0);
	Node *res = temp;

	while(a!=NULL and b!=NULL){
		if(a->data < b->data){
			temp->bottom = a;
			temp = temp->bottom;
			a = a->bottom;
		}
		else{
			temp->bottom = b;
			temp = temp->bottom;
			b = b->bottom;
		}
	}

	if(a!=NULL) temp->bottom = a;
	if(b!=NULL) temp->bottom = b;
	return res->bottom;
}

Node *flatten(Node *head){
	if(head==NULL or head->next==NULL)
		return head;

	head->next = flatten(head->next);
	head = mergeTwoLists(head,head->next);
	return head;
}