/*
    Following is the Binary Tree node structure:

    class BinaryTreeNode {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
*/
bool searchInBST(BinaryTreeNode<int> *root, int x) {
    // Write your code here.
    if (root==NULL)
        return false;
    if (root->data==x)
        return true;
    if (root->data > x)
        //left part
        return searchInBST (root->left,x);
    else
        //right part
        return searchInBST (root->right,x);
}
bool searchInBST(BinaryTreeNode<int> *root, int x) {
    // Write your code here.
    BinaryTreeNode<int>* temp = root;
    while (temp != NULL){
        if (temp->data == x)
            return true;
        if (temp->data > x)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return false;
}