#include <iostream>
#include <queue>
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
// Level Order traversal using queue 
void levelTraversal(Node* root){
    // maintain base case 

    if(root == NULL){
        return ;
    }

    //create queue
    queue<Node*> q;

    q.push(root);// push root val to queue
    q.push(NULL);
  
    while (!q.empty())
    {
       //make root = currNode and pop it  
       Node* currNode = q.front();
       q.pop();

       if (currNode == nullptr)//after every level tthis prints endline
       {
        cout<<endl;
        if(q.empty()){// this is to check for last queue data if empty break 
            break;
        }
        q.push(NULL);// to track next line
       }else{
        // print data root which is stord in currNode
       cout<<currNode->data<<" ";

       // continue for left and rght subtree 
       if (currNode->left != NULL)
       {
        q.push(currNode->left);
       }

       if (currNode->right != NULL)
       {
        q.push(currNode->right);
       }
       } 
    }
    
cout<<endl;
        
}
int main()
{
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node* root = buildTree(nodes);
    
    levelTraversal(root);

    return 0;
}