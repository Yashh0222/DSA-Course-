#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Node{
    public:
    unordered_map<char, Node*> children; // holds addres of every children in the form of node 
    int endOfWord ;
    
    Node(){
        endOfWord = false;
    }
};

class Trie{
    Node* root;
    public:
    
    Trie(){
        root = new Node;
    }

    void insert(string key){
        Node* temp = root;

        for (int i = 0; i < key.size(); i++)
        {
            if(temp->children.count(key[i]) == 0){
                temp->children[key[i]] = new Node();
            }
            temp = temp->children[key[i]];
        }
        temp->endOfWord = true;
    }

    //Funtn to search word in trie
    bool search(string key){
        Node* temp = root;

        for (int i = 0; i < key.size(); i++)
        {
            if (temp->children.count(key[i]))
            {
                temp = temp->children[key[i]];
            }else{
                return false;
            }
            
        }
        return temp->endOfWord; // if endofword is true it return true if it is false it return false 
    }

    int countHelper(Node* root){
        int ans = 0;

        for(pair<char, Node*> child : root->children){
            ans += countHelper(child.second);
        }
        return ans + 1;
    }
    int countNodes(){ // here helper is used bcz root cant be accessed outside class
        return countHelper(root);
    }
};

// suffix of given string 
int countUniqueSubStr(string str){
    Trie trie;

    for (int i = 0; i < str.size(); i++)
    {
        string suffix = str.substr(i);
        trie.insert(suffix);
    }
    return trie.countNodes();
}
int main(){ 
    string str = "ababa";
    
    cout<<countUniqueSubStr(str)<<endl; 
    return 0; 
}