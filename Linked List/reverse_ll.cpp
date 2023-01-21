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
void insert_at_tail (node* &head, int val){
    node* n = new node (val);
    if (head==NULL){
        head = n;
        return;
    }
    node* temp = head;
    while (temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = n;
}
void display (node* head){
    node* temp = head;
    while (temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
node* reverse (node* &head){
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;
    while (currptr!=NULL){
        nextptr = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nextptr;
    }
    return prevptr;
}
node* reverse_recurssive (node* &head){
    if (head==NULL || head->next == NULL){
        return head;
    }
    node* newhead = reverse_recurssive(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
}
int main()
{
    node* head = NULL;
    insert_at_tail (head,1);
    insert_at_tail(head,2);
    insert_at_tail(head,3);
    insert_at_tail(head,4);
    display(head);
    node* newhead = reverse(head);
    display(newhead);
    return 0;
}