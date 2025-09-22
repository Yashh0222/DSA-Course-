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

// To GEt Inorder Successor
Node*  getinorderSuccser(Node* root){
    while (root->left != NULL)
    {
        root = root->left;
    }
    
    return root; // returning inorder succsesor
}
//To delete a Node 
Node* deleteNode(Node* root, int val){
    //Base case 
    if(root == NULL){
        return NULL;
    }

    if(val < root->data){
        root->left = deleteNode(root->left, val);        
    }else if(val > root->data){
        root->right = deleteNode(root->right, val);
    }else{
        // when root == val 
        //case : 1 if root has 0 children
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        
        //case:2 if root has 1 child either left or right
        if(root->left == NULL || root->right ==NULL){
            return root->left == NULL ? root->right : root->left;
        }

        //case:3 if root has 2 child find inorder succser and replace it then case 1 & 2 will delete IS
        Node* IS = getinorderSuccser(root->right);
        root->data = IS->data;
        root->right = deleteNode(root->right, IS->data);
        return root;        
    }
    return root;
}
int main()
{
    //int arr[6]  = {5,1,3,4,2,7};
    int arr2[9]  = {8,5,3,1,4,6,10,11,14};

    Node* root = buildBST(arr2, 9);
    inorder(root);
    cout<<endl;

    deleteNode(root, 5);

    // printing after delleting
    inorder(root);
    cout<<endl;
    return 0;
}