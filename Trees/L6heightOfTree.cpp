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

// To calculate height of tree
int height(Node* root){
    // Base casse
    if (root == NULL)
    {
        return 0;
    }
    
    int leftht = height(root->left);
    int rightht = height(root->right);

    //to calculate particular level find max and add 1
    int currht = max(leftht, rightht) + 1;
    return currht;
}

int main()
{
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    vector<int> nodes2 = {1,2,4,-1,-1,5,-1,6,-1,7,-1,-1,3,-1,-1};

    Node* root = buildTree(nodes);
    idx = -1;
    Node* root2 = buildTree(nodes2);
    
    cout<<root->data<<endl; //1
    cout<<root2->data<<endl; //1

    cout<<"height of tree is = "<<height(root)<<endl;
    cout<<"height of tree is = "<<height(root2)<<endl; 
    return 0;
}