//Writen by CodemanSumon
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
Node* insertToBST (Node* &root, int d){
    //base case
    if (root == NULL){
        root = new Node(d);
        return root;
    }
    if (d > root->data){
        root->right = insertToBST(root->right,d);
        //right part me insertion
    }
    else{
        root->left = insertToBST(root->left,d);
        //left parte me insertion
    }
    return root;
}
void takeInput (Node* &root){
    int data;
    cin>>data;
    while (data!=-1){
        insertToBST(root,data);
        cin>>data;
    }
}
void levelOrderTraversal (Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()){
        Node* temp = q.front();
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
void inorder (Node* root){
    //base case
    if (root == NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder (Node* root){
    //base case
    if (root == NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder (Node* root){
    //base case
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
Node*  minval (Node* root){
    Node* temp = root;
    while (temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}
Node*  maxval (Node* root){
    Node* temp = root;
    while (temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}
Node* deleteFromBST(Node* root,int val){
    //base case
    if (root==NULL){
        return root;
    }
    if (root->data == val){
        //0 child
        if (root->left == NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        //1 child
        //left child
        if (root->left !=NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        //right child 
        if (root->left == NULL && root->right != NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        //2 child
        if (root->left!=NULL && root->right!=NULL){
            int mini = minval(root->right)->data;
            root->data=mini;
            root->right = deleteFromBST(root->right,mini);
            return root;
        }
    }
    else if (root->data > val){
        //left me jao
        root->left = deleteFromBST(root->left,val);
        return root;
    }
    else{
        //right me jao
        root->right = deleteFromBST(root->right,val);
        return root;
    }
}
int main()
{
    Node* root = NULL;
    cout<<"Enter data to create BST: "<<endl;
    takeInput(root);
    cout<<"Printing the BST"<<endl;
    levelOrderTraversal(root);
    cout<<"Printing inorder: ";
    inorder(root);
    cout<<endl;
    cout<<"Printing preorder: ";
    preorder(root);
    cout<<endl;
    cout<<"Printing postorder: ";
    postorder(root);
    cout<<endl;
    cout<<"Minval is: "<<minval(root)->data<<endl;
    cout<<"Maxval is: "<<maxval(root)->data<<endl;
    //deletion
    root=deleteFromBST(root,50);
    cout<<"Printing the BST"<<endl;
    levelOrderTraversal(root);
    return 0;
}