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

// To print num in given range
void printInRange(Node* root, int start,int end){
    if(root ==NULL){
        return ;
    }

    // check if curr root is in given range
    if(start <= root->data &&  root->data <= end){
        printInRange(root->left, start, end);
        cout<<root->data<<" ";
        printInRange(root->right, start, end);
    }else if(root->data < start){ // if the no is not in range in lefttree go to righttree
        printInRange(root->right, start, end);
    }else{ // if no is not present in right tree go to left tree 
        printInRange(root->left, start, end);
    }    
}
int main()
{
    //int arr[6]  = {5,1,3,4,2,7};
    int arr2[9]  = {8,5,3,1,4,6,10,11,14};

    Node* root = buildBST(arr2, 9);
    
    printInRange(root, 5 , 12); //range from 5 to 12
    
    
    return 0;
}