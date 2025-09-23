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

//Finding Kth ansister from givennode (same as lca)
int kthAnsister(Node* root, int node, int k){
    //Base Case 
    if(root == nullptr){
        return -1;
    }

    if (root->data == node)// if we get anisiter at main root retrun 0 and add 1
    {
        return 0;
    }

    // if not find node on currlevel go to next level 
    int leftDist = kthAnsister(root->left, node, k);
    int rightDist = kthAnsister(root->right, node, k);
    
    //ccondn if node is not present in tree
    if (leftDist == -1 && rightDist == -1)
    {
        return -1;
    }
    
    //if we get traverse back with +1 and if validval == k return that root data
    int validVal = leftDist == -1 ? rightDist : leftDist;
    if (validVal + 1 == k)
    {
        cout<<"ktAnsister is = "<<root->data<<endl;
    }
    
    // if we not get kthansister on that level add + 1
    return validVal + 1;

}
int main()
{
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node* root = buildTree(nodes);
    
    int node = 5, k = 1;
    kthAnsister(root, node, k);
    return 0;
}