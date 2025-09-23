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

//identical code
bool isIdentical(Node* root1, Node* root2){

     //Base Case
    if(root1 == nullptr && root2 == nullptr){
        return true;
    }else if(root1 == nullptr || root2 == nullptr){
        return false;
    }

    if (root1->data != root2->data)
    {
        return false;
    }

    return isIdentical(root1->left, root2->left) && // this condn works only if both are true
           isIdentical(root1->right, root2->right); 
           
    
}

bool isSubTree(Node* root, Node* subRoot){
    //Base Case
    if(root == nullptr && subRoot == nullptr){
        return true;
    }else if(root == nullptr || subRoot == nullptr){
        return false;
    }
    if (root->data == subRoot->data)
    {
        //check for whole subtree for identical tree values
        if(isIdentical(root, subRoot)){
            return true;
        }
    }

    int isleftSubtree = isSubTree(root->left, subRoot);
    if(!isleftSubtree){
        return  isSubTree(root->right, subRoot);
    }
    return true;
}
int main()
{
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node* root = buildTree(nodes);

    Node* subRoot = new Node(2);
    subRoot->left = new Node(4);
    //subRoot->right = new Node(5);

    cout<<isSubTree(root, subRoot); // 1
    return 0;
}