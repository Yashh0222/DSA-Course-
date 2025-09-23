#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Node{
    public:
    unordered_map<char, Node*> children; // holds addres of every children in the form of node 
    int endOfWord ;
    int freq ;
    
    Node(){
        endOfWord = false;
    }
};

class Trie{
    Node* root;
    public:
    
    Trie(){
        root = new Node;
        root->freq = -1;
    }

    void insert(string key){
        Node* temp = root;

        for (int i = 0; i < key.size(); i++)
        {
            if(temp->children.count(key[i]) == 0){
                temp->children[key[i]] = new Node();
                temp->children[key[i]]->freq = 1; // to find prefix we added freq to every child if we get 1 as next child we return unique prefix
            }else{                
                temp->children[key[i]]->freq++; // if we get again same char for other word when we are inserting freq++ 
            } // Eg: dog, dove here when inserting dog d->freq = 1 , again when inserting dove d freq becomes 2 find 1 freq child and return its prtefix
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

    string getPrefix(string key){
        Node* temp = root;
        string prefix ="";

        for (int i = 0; i < key.size(); i++)
        {
            prefix += key[i];
            if(temp->children[key[i]]->freq == 1){ // if we get one child reutrn prefix
                break;
            }
            temp = temp->children[key[i]]; //if not serch for next child 
        }
        return prefix;
    }
};

// Crete func to find prefix
void prefixProblem(vector<string> dict){
    Trie trie;

    for (int i = 0; i < dict.size(); i++)
    {
        trie.insert(dict[i]);
    }

    for (int i = 0; i < dict.size(); i++)
    {
        cout<<trie.getPrefix(dict[i])<<endl;
    }
    
    
} 
int main(){ 
    vector<string > dict = {"zebra","dog","duck","dove"};
    
    prefixProblem(dict);    
    return 0; 
}