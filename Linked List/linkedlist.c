#include <stdio.h>
#include <stdlib.h>
struct node{  
    int data;
    struct node *next;
};
int count_total_nodes(struct node** head){
    int count = 0;
    struct node*temp = *head;
    while (temp!=NULL){
        temp = temp->next;
        count++;
    }
    return count;
}  
void insert_at_head(struct node** head, int val){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = val;
    new_node->next = (*head);
    (*head) = new_node;
}
void insert_at_tail (struct node** head, int val){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));   
    new_node->data = val;
    new_node->next = NULL;
    if (*head == NULL){
        *head = new_node;
        return;
    }
    struct node* temp = (*head);
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new_node;
}
void insert_after (struct node* prev, int val){
    if (prev == NULL){
        printf("Not possible\n");
        return;
    }
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = val;
    new_node->next = prev->next;
    prev->next = new_node;
}
void insert_at_mid (struct node** head, int val, int c){
    int d = c/2;
    if ((*head) == NULL && (*head)->next == NULL){
        printf("Not possible\n");
        return;
    }
    struct node* temp = *head;
    for (int i=1; i<d; i++){
        temp = temp->next;
    }
    insert_after (temp,val);
}
void display(struct node* head){
    struct node* temp = head;
    while (temp != NULL){
        printf ("%d",temp->data);
        printf("->");
        temp = temp->next;
    }
    printf("NULL");
}
void delete_at_head (struct node** head){
    struct node *temp = (*head);
    (*head) = temp->next;
    free(temp);
}
void delete_at_end (struct node** head){
    struct node* temp = (*head); 
    struct node* prev = NULL;
    while (temp->next){
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
}
void delete_at_mid (struct node** head, int key){
    struct node* temp;
    struct node* prev;
    temp = *head;
    prev = *head;
    for (int i = 0; i<key; i++) {
        if (i == 0 && key == 1) {
            *head = (*head)->next;
            free(temp);
        }
        else {
            if (i == key - 1 && temp) {
                prev->next = temp->next;
                free(temp);
            }
            else {
                prev = temp;
                if (prev == NULL)
                    break;
                temp = temp->next;
            }
        }
    }
}
int main(){
    struct node* head = NULL;
    int flag = 1;
    while (flag){
        printf ("\n1 for insertion at begining");
        printf ("\n2 for insertion at end");
        printf ("\n3 for insertion at mid");
        printf ("\n4 for deletion at begining");
        printf ("\n5 for deletion at end");
        printf ("\n6 for deletion at mid");
        printf ("\n7 for displaying");
        printf ("\n8 for exit");
        int ch,n,cnt,d;
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("\nEnter node: ");
                scanf("%d",&n);
                insert_at_head(&head,n);
                break;
            case 2:
                printf("\nEnter node: ");
                scanf("%d",&n);
                insert_at_tail (&head,n);
                break;
            case 3:
                printf("\nEnter node: ");
                scanf ("%d",&n);
                cnt = count_total_nodes(&head);
                insert_at_mid(&head,n,cnt);
                break;
            case 4:
                delete_at_head (&head);
                break;
            case 5:
                delete_at_end (&head);
                break;
            case 6:
                cnt = count_total_nodes(&head);
                d = cnt/2;
                delete_at_mid(&head,d);
                break;
            case 7:
                printf("\nThe created Linked List is: ");
                display(head);
                break;
            case 8:
                printf("\nThank you!!");
                flag = 0;
                break;
            default: 
                printf("\nWrong Choice");
        }
    }
    return 0;
}