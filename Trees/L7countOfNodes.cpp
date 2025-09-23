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

int count(Node* root){
    // Base Case 
    if (root == NULL)
    {
        return 0;
    }
    
    // recursion gives count of every subtree 
    int leftCount = count(root->left);
    int rightCount = count(root->right);

    int currCount = leftCount + rightCount + 1; // extra one to add root of every subtree
    
    return currCount;
}
int main()
{
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node* root = buildTree(nodes);
    
    cout<<"Count: "<<count(root)<<endl;
    return 0;
}