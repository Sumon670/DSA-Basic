//Writen by CodemanSumon
#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node (int val){
        data = val;
        next = NULL;
    }
};
void insert_at_head (node* &head, int val){
    node* n = new node (val);
    if (head==NULL){
        n->next = n;
        head = n;
        return;
    }
    node* temp = head;
    while (temp->next != head){
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head = n;
}
void insert_at_tail (node* &head, int val){
    if (head == NULL){
        insert_at_head(head,val);
        return;
    }
    node* n = new node (val);
    node* temp = head;
    while (temp->next != head){
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}
void display (node* head){
    node* temp = head;
    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp != head /*NULL (code will never stop)*/ );
    cout<<endl;
}
void delete_at_head (node* &head){
    node* temp = head;
    while (temp->next != head){
        temp = temp->next;
    }
    node* todelete = head;
    temp->next = head->next;
    head = head->next;
    delete todelete; 
}
void deletion (node* &head, int pos){
    if (pos==1){
        delete_at_head (head);
        return;
    }
    node* temp = head;
    int count = 1;
    while (count != pos-1){
        temp = temp->next;
        count += 1;
    }
    node* todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}
int main()
{
    node* head = NULL;
    insert_at_tail(head,1);
    insert_at_tail(head,2);
    insert_at_tail(head,3);
    insert_at_tail(head,4);
    display (head);
    insert_at_head (head,5);
    display(head);
    deletion (head,1);
    display(head);
    return 0;
}