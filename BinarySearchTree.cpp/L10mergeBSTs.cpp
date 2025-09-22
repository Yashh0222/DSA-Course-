#include <iostream>
#include <vector>
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
void preorder(Node* root){

    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
Node* buildBSTfromVec(vector<int> merged,int start, int end){
    //base case
    if(start > end){
        return nullptr;
    }

    int mid = start + (end - start)/2;
    Node* curr = new Node(merged[mid]);
    curr->left = buildBSTfromVec(merged, start, mid-1);
    curr->right = buildBSTfromVec(merged, mid+1,end);

    return curr;
}
void getInorder(Node* root, vector<int> &nodes){
    if(root==NULL){
        return ;
    }

    getInorder(root->left ,nodes);
    nodes.push_back(root->data);
    getInorder(root->right ,nodes);
}
// to merge BSTs 
Node* mergeBSTs(Node* root1, Node* root2){
    vector<int> nodes1;
    vector<int> nodes2;
    vector<int> merged;

    getInorder(root1, nodes1);
    getInorder(root2, nodes2);

    int i=0,j=0;
    while (i<nodes1.size() && j<nodes2.size())
    {
        if(nodes1[i] < nodes2[j]){
            merged.push_back(nodes1[i++]);
        }else{
            merged.push_back(nodes2[j++]);
        }
    }

    while(i<nodes1.size()){        
        merged.push_back(nodes1[i++]);
    }
    
    while(j<nodes2.size()){        
        merged.push_back(nodes2[j++]);
    }

    return buildBSTfromVec(merged, 0, merged.size()-1);
}
int main()
{
    Node* root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(4);

    
    Node* root2 = new Node(9);
    root2->left = new Node(3);
    root2->right = new Node(12);

    Node* root = mergeBSTs(root1, root2);
    preorder(root);
    return 0;
}