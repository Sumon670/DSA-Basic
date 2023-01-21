//Writen by CodemanSumon
#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        int data;
        node* right;
        node* left;
    node (int d){
        this -> data = d;
        this ->right = NULL;
        this -> left = NULL;
    }
};
node* buildtree (node* root){
    cout<<"Enter data: "<<endl;
    int data;
    cin>>data;
    root = new node (data);
    if (data==-1){
        return NULL;
    }
    cout << "Enter data for inserting in the left of "<<data<<endl;
    root->left = buildtree(root->left);
    cout << "Enter data for inserting in the right of "<<data<<endl;
    root->right = buildtree(root->right);
    return root;
}
void levelOrderTraversal (node* root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()){
        node* temp = q.front();
        q.pop();
        if (temp==NULL){
            //purana level complete ho chuka
            cout<<endl;
            if (!q.empty()){
                //queue still has some child nodes
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if (temp->left){
                q.push(temp->left);
        }
            if (temp->right){
                q.push(temp->right);
        }
        }
    }
}
void reverseLevelOrderTraversal (node* root){
    queue<node*>q;
    stack<node*>st;
    q.push(root);
    q.push(NULL);
    while (!q.empty()){
        node* temp = q.front();
        q.pop();
        st.push(temp);
        if (temp == NULL){
            if (!q.empty())
                q.push(NULL);
        }
        else{   
            if (temp->right){
                q.push(temp->right);
            }
            if (temp->left){
                q.push(temp->left);
            }
        }
    }
    while (!st.empty()){
        node* temp = st.top();
        st.pop();
        if (temp == NULL){
            cout<<endl;
        }
        else{
            cout<<temp->data<<" ";
        }
    }
}
void inorder (node* root){
    //base case
    if (root == NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder (node* root){
    //base case
    if (root == NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder (node* root){
    //base case
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
node* buildFromLevelOrder (node* &root){
    queue<node*>q;
    cout<<"Enter the data for root: "<<endl;
    int data;
    cin>>data;
    root = new node (data);
    q.push(root);
    while (!q.empty()){
        node* temp = q.front();
        q.pop();
        cout<<"Enter left node for: "<<temp->data<<endl;
        int leftData;
        cin>>leftData;
        if (leftData != -1){
            temp->left = new node (leftData);
            q.push(temp->left);
        }
        cout<<"Enter right node for: "<<temp->data<<endl;
        int rightData;
        cin>>rightData;
        if (rightData != -1){
            temp->right = new node (rightData);
            q.push(temp->right);
        }
    }
};
int main()
{
    node* root = NULL;
    buildFromLevelOrder(root);
    levelOrderTraversal(root);
    //create a tree;
    //root = buildtree(root);
    //levelorder
    //cout<<"Printing level order traversal output: "<<endl;
    //levelOrderTraversal(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    //reverseLevelOrderTraversal(root);
    // cout<<"Inorder traversal is: ";
    // inorder(root);
    // cout<<endl;
    // cout<<"Preorder traversal is: ";
    // preorder(root);
    // cout<<endl;
    // cout<<"postorder traversal is: ";
    // postorder(root);
    // cout<<endl;
    return 0;
}