#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

Node *insert(Node *root, int val)
{
    if (root == NULL) // Base case when no val is present add val and make it root
    {
        root = new Node(val);
        return root;
    }

    if (val < root->data)
    { // left subtree
        root->left = insert(root->left, val);
    }
    else
    { // right subtreee
        root->right = insert(root->right, val);
    }

    return root;
}
Node *buildBST(int arr[], int n)
{
    Node *root = NULL;

    for (int i = 0; i < n; i++)
    {
        root = insert(root, arr[i]);
    }

    return root;
}

// INorder traversal 
void inorder(Node* root){
    if(root == NULL){
        return ;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

    
}
 // validate using helper
bool validateHelper(Node* root, Node* min,Node* max){
    if (root == NULL)
    {
        return true;
    }

    if(min != NULL && root->data < min->data){
        return false;
    }
    
    
    if(max != NULL && root->data > max->data){
        return false;
    }

    return validateHelper(root->left, min, root)
        &&  validateHelper(root->right, root, max);
} 
// To Validate BST
bool validateBST(Node* root){
    return validateHelper(root, NULL,NULL);
}
int main()
{
    //int arr[6]  = {5,1,3,4,2,7};
    int arr2[9]  = {8,5,3,1,4,6,10,11,14};

    Node* root = buildBST(arr2, 9);
    root->data = 15; // false = 0 
    cout<<validateBST(root)<<endl; //true = 1
    return 0;
}