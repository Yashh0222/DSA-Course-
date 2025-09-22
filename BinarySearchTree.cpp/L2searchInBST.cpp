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

//to search in BST  
bool search(Node* root, int key){
    if(root == NULL){
        return false;
    }

    if(root->data == key){
        return true;
    }

    if(key < root->data){// if key < root search in left subtree
        return search(root->left, key);
    }else{ // if key greaer than root dearch in right treee
        return search(root->right, key);
    }


}
int main()
{
    //int arr[6]  = {5,1,3,4,2,7};
    int arr2[9]  = {8,5,3,1,4,6,10,11,14};

    Node* root = buildBST(arr2, 9);
    inorder(root);
    cout<<endl;
    cout<<search(root, 15);
    return 0;
}