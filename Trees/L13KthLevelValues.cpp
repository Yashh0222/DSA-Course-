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

void kthHelper(Node* root, int k, int currLevel){

    // Base case
    if(root == NULL){
        return ;
    }

    if (currLevel == k)
    {
        cout<<root->data<<" ";
    }

    kthHelper(root->left, k, currLevel+1); // going to next level level++ 
    kthHelper(root->right, k, currLevel+1);
    
}
void kthLevelValue(Node* root, int k){
    kthHelper(root, k, 1);
}
int main()
{
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node* root = buildTree(nodes);

    kthLevelValue(root, 2);    
    return 0;
}
