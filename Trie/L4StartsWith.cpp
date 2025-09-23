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
            }else if(temp->endOfWord){
                return false;
            }
            
        }
        return true; // if given substr is present in any inserted word return true 
    }
};
int main(){ 
    vector<string > words = {"apple","app","mango","man","women"};
    Trie trie;

    for (int i = 0; i < words.size(); i++)
    {
        trie.insert(words[i]);
    }

    cout<<trie.search("wom")<<endl;
    
    return 0; 
}