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
int height(Node* root){ // 
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

int diameter(Node* root){ //TC = 0(n2)
    if(root == NULL){
        return 0;
    }

    int currDiam = height(root->left) + height(root->right) + 1;//this gives curr diam of that root
    int leftDiam = diameter(root->left); // this calculates recursively towards left
    int rightDiam = diameter(root->right);

    return max(currDiam, max(leftDiam, rightDiam)); 

}

pair<int, int>diameter2(Node* root){ // TC = 0(n)

    // base case 
    if(root == nullptr){
        return make_pair(0, 0);
    }
    //Pair(diameter , height)
    pair<int, int> leftInfo = diameter2(root->left);// making pair of diameter and height
    pair<int, int> rightInfo = diameter2(root->right);
    
    int currDiam = leftInfo.second + rightInfo.second + 1;//this gives currrr dia
    int finalDiam = max(currDiam, max(leftInfo.first, rightInfo.first)); // this comapres every possible diam and givs max diam
    int finalHt = max(leftInfo.second,rightInfo.second) + 1;

    return make_pair(finalDiam, finalHt);
}
int main()
{
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,-1};
    vector<int> nodes2 = {1,2,4,-1,-1,5,-1,6,-1,7,-1,-1,3,-1,-1};

    Node* root = buildTree(nodes);
    idx = -1;
    Node* root2 = buildTree(nodes2);
    
    cout<<root->data<<endl; //1
    cout<<root2->data<<endl; //1

    cout<<"height of tree is = "<<height(root)<<endl;
   cout<<"height of tree is = "<<height(root2)<<endl; 

    cout<<"Diameter : "<<diameter(root)<<endl;
    cout<<"Diameter : "<<diameter(root2)<<endl;

    cout<<"Diameter : "<<diameter2(root).first<<endl;
    cout<<"Diameter : "<<diameter2(root2).first<<endl;
    return 0;
}