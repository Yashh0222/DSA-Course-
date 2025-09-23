#include <iostream>
#include <vector>
#include <queue>
#include <map>
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

// To print top view of tree
void topView(Node* root){
    queue<pair<Node*, int>> q; // (rootNode, horizontalDIst) pair stores root and hd
    map<int, int> m; // (hd , nodevalue)

    q.push(make_pair(root, 0));
    while(!q.empty()){
        pair<Node* ,int> curr = q.front(); // save temporarily for future use
        q.pop();

        Node* currNode = curr.first;
        int currHD = curr.second;

        if(m.count(currHD) == 0){ // this checks if map consist hd value twise or not if it is not present this adds to map
            m[currHD] = currNode->data;
        }

        // to add other level values check if value left  present 
        if(currNode->left != NULL){
            pair<Node*, int> left = make_pair(currNode->left, currHD-1);
            q.push(left);
        }

        
        // to add other level values check if value at right side tree present 
        if(currNode->right != NULL){
            pair<Node*, int> right = make_pair(currNode->right, currHD+1);
            q.push(right);
        }
    }
    for(auto it: m){
        cout<<it.second<<" ";
    }cout<<endl;
}
int main()
{
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node* root = buildTree(nodes);
    
    topView(root);
    return 0;
}