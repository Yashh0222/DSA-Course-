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

class Info{
    public:
    bool isBST;
    int max;
    int min;
    int size;

    Info(bool isBST, int max, int min, int size){
        this->isBST = isBST;
        this->max = max;
        this->min = min;
        this->size = size;
    }
};

// To find max nodes of BST in BT
static int maxsize;
Info* largestBST(Node* root){

    // Base Case 
    if(root == NULL){
       return new Info(true, INT8_MAX, INT8_MIN,0); 
    }
    Info* leftInfo = largestBST(root->left);
    Info* rightInfo = largestBST(root->right);


    int currMin = min(root->data, min(leftInfo->min, rightInfo->min));//this find min of left tree
    int currMax = max(root->data, max(leftInfo->max, rightInfo->max));// this finds max of right tree
    int currsize = leftInfo->size + rightInfo->size + 1;
    
    if(leftInfo->isBST && rightInfo->isBST && root->data > leftInfo->max && rightInfo->min){
        maxsize = max(maxsize, currsize);
        return new Info(true, currMin, currMax, currsize);
    }
    
        
    return new Info(false, currMin, currMax, currsize);
}

int main()
{
    Node* root = new Node(50);
    root->left = new Node(30);
    root->left->left = new Node(5);
    root->left->left->right = new Node(20);

    root->right = new Node(60);
    root->right->left = new Node(45);
    root->right->right = new Node(70);
    root->right->right->left = new Node(65);
    root->right->right->right = new Node(80);

    largestBST(root);
    cout<<" max size: "<<maxsize<<endl;
    return 0;
}