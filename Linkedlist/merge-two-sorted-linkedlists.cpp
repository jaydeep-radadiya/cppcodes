Node *sortedMerge(Node *head1,Node *head2){
    Node *temp = new Node(0);
    Node *res = temp;
    
    while(head1!=NULL and head2!=NULL){
        if(head1->data < head2->data){
            temp->next = head1;
            temp = temp->next;
            head1 = head1->next;
        }
        else{
            temp->next = head2;
            temp = temp->next;
            head2 = head2->next;
        }
    }
    
    if(head1!=NULL) temp->next = head1;
    if(head2!=NULL) temp->next = head2;
    return res->next;
}