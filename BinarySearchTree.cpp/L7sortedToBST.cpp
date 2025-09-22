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

//To built BST from sorted array
Node* buildBSTfromSorted(int arr[], int start, int end){
    
    // Base CAse
    if(start > end){
        return NULL;
    }
    int mid = start + (end - start)/2;
    Node* curr = new Node(arr[mid]);
    curr->left = buildBSTfromSorted(arr, start, mid-1);
    curr->right = buildBSTfromSorted(arr, mid+1, end);

    return curr;
}

void preorder(Node* root){
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    //int arr[6]  = {5,1,3,4,2,7};
    int arr2[7]  = {3,4,5,6,7,8,9};
    int arr3[9]  = {8,5,3,1,4,6,10,11,14};

    Node* root = buildBSTfromSorted(arr2, 0, 6);
    preorder(root);
    return 0;
}