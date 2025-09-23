#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Node{
    public:
    unordered_map<char, Node*> children; // holds addres of every children ion form of node 
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
        return temp->endOfWord; // if endofword is trure it return true if it is false it return false 
    }
};

bool helper(Trie &trie, string key){
    //BAse case
    if(key.size() == 0){
        return true;
    }
    for (int i = 0; i < key.size(); i++)
    {
        string first = key.substr(0, i+1); // this selects one char from string and compare with dict val trie 
        string second = key.substr( i+1); // this substr is except first substr all other substr 

        if(trie.search(first) && helper(trie, second)){
            return true;
        }
    }
    return false; 
}
// To break given key and find key words in given dictonary
bool wordBreak(vector<string> dict, string key){
    Trie trie;
    for (int i = 0; i < dict.size(); i++)
    {
        trie.insert(dict[i]);
    }
    
    return helper(trie, key);
}
int main(){ 
    vector<string > dict = {"i","like"," sam","samsung","mobile"," ice"};
    
    cout<<wordBreak(dict, "ilikesamsung")<<endl;
    
    return 0; 
}