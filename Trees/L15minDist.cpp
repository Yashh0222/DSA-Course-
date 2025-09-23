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

bool rootToNodePath(Node* root, int n, vector<int> &path){

    if(root == nullptr){
        return false;
    }

    path.push_back(root->data);
    if(root->data == n){
        return true;
    }

    int isleft = rootToNodePath(root->left, n, path);
    int isright = rootToNodePath(root->right, n, path);

    if (isleft || isright)
    {
        return true;
    }
    
    path.pop_back();
    return false;

}
// LCA = lowest common ansister
int LCA(Node* root,  int n1, int n2){ // TC = 0(n), SC = 0(n) 
    vector<int> path1;
    vector<int> path2;

    rootToNodePath(root, n1, path1);
    rootToNodePath(root, n2, path2);

    int lca = -1;
    for (int i = 0,j=0; i < path1.size() && j<path2.size(); i++,j++)
    {
        if (path1[i] != path2[i])
        {
            return lca;
        }
        lca = path1[i];
    }
    return lca;
}

// apprroch 2: TC = 0(N), SC = 0(1);

Node* LCA2(Node* root, int n1, int n2){
    // BAse case 
    if(root == NULL){
        return NULL;
    }
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }

    Node* leftLCA = LCA2(root->left, n1, n2);
    Node* rightLCA = LCA2(root->right, n1, n2);

    //if we get ans in sub tree return root
    if(leftLCA != NULL && rightLCA != NULL){
        return root;
    }
    
     
    return (leftLCA == NULL) ? rightLCA : leftLCA;
    // if leftLCA is NULL it return rightLCA(which has valid value)
    // if leftLCA is not NULL it return leftLCA(which has valid value)
    // if leftLCA is NULL it returns rightLCA (which has NULL value) 
} 

// finding dist from lca to n
int dist(Node* root, int n){
    // Base Case 
    if (root == NULL)
    {
        return -1;
    }

    if(root->data == n){
        return 0;
    }

    int leftdist = dist(root->left, n);
    if(leftdist != -1){
        return leftdist + 1;
    }

    int rightdist = dist(root->right, n);
    if(rightdist != -1){
        return rightdist + 1;
    }
    return -1;
}
// to find min dist we need lca 
int minDist(Node* root, int n1, int n2){
    
    Node* lca = LCA2(root, n1, n2);

    int dist1 = dist(lca, n1);
    int dist2 = dist(lca, n2);

    return dist1 + dist2;
}
int main()
{
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node* root = buildTree(nodes);
    
    int n1 = 4, n2 = 5 ; //4
    
    cout<<"Min dist blw nodes = "<<minDist(root, n1, n2);
    return 0;
}