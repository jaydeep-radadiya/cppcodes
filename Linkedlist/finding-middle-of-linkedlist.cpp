// first method
int getMiddle(Node *head){
    int size = 0;
    Node *temp = NULL;

    while(temp!=NULL){
        temp = temp->next;
        size++;
    }

    int mid = size/2+1;
    temp = head;
    for(int i=1;i<=mid;i++){
        if(i==mid)
            return temp->data;
        temp = temp->next;
    }
}

// second method
int getMiddle(Node *head){
    Node *slow = head;
    Node *fast = head;

    while(fast!=NULL and fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}