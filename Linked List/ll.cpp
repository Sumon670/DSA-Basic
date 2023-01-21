//Writen by CodemanSumon
#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node *next;
    node (int val){
        data = val;
        next = NULL;
    }
};
void insert_at_tail(node* &head, int val){
    node* n = new node(val);
    if (head==NULL){
        head = n;
        return;
    }
    node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = n; 
}
void display(node *head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
void insert_at_head (node* &head, int val){
    node* n = new node(val);
    n->next=head;
    head=n;

}
bool search (node* head, int key){
    node* temp = head;
    while(temp!=NULL){
        if (temp->data == key){
            return true;
        }
        temp=temp->next;
    }
    return false;
}
void delete_at_head (node* &head){
    node* todelete = head;
    head = head->next;
    delete todelete;
}
void deletion (node* &head, int val){
    if (head==NULL){
        return;
    }
    if (head->next == NULL){
        delete_at_head(head);
        return;
    }
    node* temp = head;
    while (temp->next->data != val){
        temp = temp->next;
    }
    node* todelte = temp->next;
    temp->next = temp->next->next;
    delete todelte;
}

int main()
{
    node* head=NULL;
    insert_at_tail(head,1);    
    insert_at_tail(head,2);    
    insert_at_tail(head,3);    
    //display(head);
    insert_at_tail(head,4);
    display(head);
    //cout<<search(head,3)<<endl; 
    deletion (head,3);
    display(head);
    delete_at_head(head);
    display(head);
    return 0;
}