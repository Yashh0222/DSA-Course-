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

static int idx = -1;

Node *buildTree(vector<int> nodes)
{
    idx++;

    if(nodes[idx] == -1){
        return nullptr;
    }
    // crete new node to add
    Node *currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);  // this adds recursivelly to left subtree
    currNode->right = buildTree(nodes); // this adds to right subtree

    return currNode;
}

// Inorder traversal
void inorder(Node* root){

    //Basee Case
    if (root == nullptr)
    {
        return;
    }
    
    //first go left sub tree 
    inorder(root->left);

    //now print left subtree root
    cout<<root->data<<" ";

    //for same root go to right subtree
    inorder(root->right);
}
int main()
{
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node* root = buildTree(nodes);
    
    cout<<root->data<<endl;

    inorder(root);
    return 0;
}